
#include <gtest/gtest.h>

#include <ODUtil/ODTimeUtil.h>

TEST(ODTimeUtil, ToString)
{
    std::string tmpStr;
    ODTimeUtil::Timestamp2String(1528184066, "%y%m%d_%H%M%S", tmpStr);
    EXPECT_EQ("180605_153426", tmpStr);
    ODTimeUtil::Duration2String(1528184066, "%dDays %2Hhour %2MMinute %2SSecond", tmpStr);
    EXPECT_EQ("17687Days 07hour 34Minute 26Second", tmpStr);
}
