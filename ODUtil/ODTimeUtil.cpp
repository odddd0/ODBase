
#include "ODTimeUtil.h"

ODTimeUtil::ODTimeUtil()
{

}

void ODTimeUtil::Timestamp2String(const int &timestamp_, const std::string &format_, std::string &str_)
{
    struct tm *tmpTm;
    time_t lt;
    char str[80];
    lt = timestamp_;
    tmpTm=localtime(&lt);
    strftime(str, 100, format_.c_str(), tmpTm);
    str_ = str;
}

void ODTimeUtil::Duration2String(const int &timestamp_, const std::string &format_, std::string &str_)
{
    int tmpDay = timestamp_ / 86400;
    int tmpInt = timestamp_ % 86400;

    int tmpHour = tmpInt / 3600;
    tmpInt = tmpInt % 3600;

    int tmpMinute = tmpInt / 60;
    int tmpSecond = tmpInt % 60;

    str_.clear();
    bool nextTrans = false;
    int numLength = 0;
    std::string tmpStr;
    std::for_each(format_.begin(), format_.end(), [&](const char &x){
        if (nextTrans)
        {
            if (x >= 0x30 && x <= 0x39)
            {
                numLength = x - 0x30;
            }
            else
            {
                switch (x)
                {
                case 'd':tmpStr = std::to_string(tmpDay);break;
                case 'H':tmpStr = std::to_string(tmpHour);break;
                case 'M':tmpStr = std::to_string(tmpMinute);break;
                case 'S':tmpStr = std::to_string(tmpSecond);break;
                default:tmpStr.clear();break;
                }
                while (tmpStr.length() < numLength && !tmpStr.empty())
                {
                    tmpStr = "0" + tmpStr;
                }
                str_ += tmpStr;
                numLength = 0;
                nextTrans = false;
            }
        }
        else
        {
            if (x == '%')
            {
                nextTrans = true;
            }
            else
            {
                str_.push_back(x);
            }
        }
    });
}
