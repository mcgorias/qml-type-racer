#include "typeprogresscontroller.h"

TypeProgressController::TypeProgressController(QObject *parent) : QObject(parent)
{

}

double TypeProgressController::computeProgress(QString t) const
{
    const int base = text.length();
    const int end  = std::min<int>(t.length(), base);

    int progress = 0;
    while(progress< end && t.at(progress) == text.at(progress))
        progress++;

    return progress / static_cast<double>(base);
}

QString TypeProgressController::computeProgressString(QString t) const
{
    if(t.isEmpty())
        return "" ;

    QString ret="<color="+goodColor+">";
    const int base = text.length();
    const int end  = std::min<int>(t.length(), base);

    int progress = 0;
    while(progress< end && t.at(progress) == text.at(progress))
    {
        ret.append(t.at(progress));
        progress++;
    }
    ret+="</color>";
    if(progress<t.length())
    {

        ret+="<color="+wrongColor+">";
        ret+=t.midRef(progress);
        ret+="</color>";
    }
    return ret;
}
