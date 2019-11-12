#include "typeprogresscontroller.h"

TypeProgressController::TypeProgressController(QString text, QObject *parent) : QObject(parent),text(text),progressText(""),progress(0)
{

}

QString TypeProgressController::timeElapsed() const {

   QTime t0(0,0,0);
   auto ref = good ? duration : startTime.elapsed();
   t0 = t0.addMSecs(ref);
   QString format = "m:ss.z";

   auto str = t0.toString(format) ;

   return str;
}

void TypeProgressController::computeProgress()
{
    if(over)
        return;

    progressText="";
    progress=0;
    good=false;

    if(input.isEmpty() || text.isEmpty())
    {
        emitProgressChanged();
        return ;
    }

    duration = startTime.elapsed();

    if(input == text)
    {
        progress = 1.;
        good     = true;
        progressText = coloredText(text,goodColor);
        over     = true;
        emitProgressChanged();
        duration = startTime.elapsed();
        emit finished();
        return;
    }

    const int base = text.length();
    const int end  = std::min<int>(input.length(), base);

    QString prgTxt;
    int i = 0;
    while(i< end && input.at(i) == text.at(i))
    {
        prgTxt.append(input.at(i));
        i++;
    }

    progress = static_cast<double>(i)/(base);
    progressText+= coloredText(prgTxt,goodColor);

    good = i>=input.length();

    if(!good)
        progressText += coloredText(input.mid(i),wrongColor);

    emitProgressChanged();
}

void TypeProgressController::emitProgressChanged()
{
    emit progressChanged(progress);
    emit progressTextChanged(progressText);
}

QString TypeProgressController::coloredText(QString txt, QString color)
{
    return "<font color='"+color+"'>"+txt+"</font>";
}
