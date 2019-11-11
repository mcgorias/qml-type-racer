#ifndef TYPEPROGRESSCONTROLLER_H
#define TYPEPROGRESSCONTROLLER_H

#include <QObject>

class TypeProgressController : public QObject
{
    Q_OBJECT
public:
    explicit TypeProgressController(QObject *parent = nullptr);

    double computeProgress(QString t) const;
    QString computeProgressString(QString t) const;

    QString text;
    QString goodColor="green";
    QString wrongColor="grey";
signals:

public slots:



};

#endif // TYPEPROGRESSCONTROLLER_H
