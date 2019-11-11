#include "typeprogresscontroller.h"

TypeProgressController::TypeProgressController(QString text, QObject *parent) : QObject(parent),text(text)
{

}

void TypeProgressController::computeProgress()
{
    progressText="";
    progress=0;
    if(input.isEmpty() || text.isEmpty())
        return ;


    progressText="<color="+goodColor+">";
    const int base = text.length();
    const int end  = std::min<int>(input.length(), base);

    int i = 0;
    while(i< end && input.at(i) == text.at(i))
    {
        progressText.append(input.at(i));
        i++;
    }

    progress = static_cast<double>(i)/(base);
    progressText+="</color>";

    if(i<input.length())
    {
        progressText+="<color="+wrongColor+">";
        progressText+=input.midRef(i);
        progressText+="</color>";
    }

}
