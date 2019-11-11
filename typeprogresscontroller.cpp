#include "typeprogresscontroller.h"

TypeProgressController::TypeProgressController(QString text, QObject *parent) : QObject(parent),text(text),progressText(""),progress(0)
{

}

void TypeProgressController::computeProgress()
{
    progressText="";
    progress=0;
    good=false;

    if(input.isEmpty() || text.isEmpty())
    {
        emitProgressChanged();
        return ;
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
