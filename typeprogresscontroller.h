#ifndef TYPEPROGRESSCONTROLLER_H
#define TYPEPROGRESSCONTROLLER_H

#include <QObject>
#include <QTime>

class TypeProgressController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text         READ getText          WRITE setText                            )
    Q_PROPERTY(QString input        READ getInput         WRITE setInput                           )
    Q_PROPERTY(QString progressText READ getProgressText                 NOTIFY progressTextChanged)
    Q_PROPERTY(double  progress     READ getProgress                     NOTIFY progressChanged    )
    Q_PROPERTY(bool    good         READ isGood                          NOTIFY goodChanged        )
    Q_PROPERTY(double  wpm          READ computeWPM                                                )
    Q_PROPERTY(QString timeElapsed  READ timeElapsed                                               )

public:
    explicit TypeProgressController(QString text=QString(), QObject * parent = nullptr);

    void setText (QString t) {reset(); text=t; computeProgress();}
    void setInput(QString i) {
        if(over)
            return ;

        if(input.isEmpty() && i.length() == 1)
        {
            reset();
            startTime.start();
        }
        input = i;
        computeProgress();
    }

    QString getText()         const {return text         ;}
    QString getProgressText() const {return progressText ;}
    double  getProgress()     const {return progress     ;}
    QString getInput()        const {return input        ;}
    QString getGoodColor()    const {return goodColor    ;}
    QString getWrongColor()   const {return wrongColor   ;}
    bool    isGood()          const {return good         ;}
    QString timeElapsed()     const;

    double computeWPM()       const {
        if(startTime == QTime())
            return 0;

        auto time = good ? duration : startTime.elapsed();
        return static_cast<int>( input.count(' ') * 60. /(time/1000.) +0.5);
    }
    QString goodColor="green";
    QString wrongColor="grey";

signals:

    void progressTextChanged(QString);
    void progressChanged(double);
    void goodChanged(bool);
    void finished();
public slots:

    void computeProgress();

    void reset(){
        input        = "";
        progressText = "";
        progress     = 0.;
        duration     = 0 ;
        over         = false;
        good         = true ;
        startTime    = QTime();
        emitProgressChanged();
    }

protected:
    void emitProgressChanged();
    static QString coloredText(QString txt,QString color);
    QString input;
    QString text;
    QString progressText;
    double  progress;
    bool    good;
    QTime   startTime;
    int     duration;
    bool    over;

};

#endif // TYPEPROGRESSCONTROLLER_H
