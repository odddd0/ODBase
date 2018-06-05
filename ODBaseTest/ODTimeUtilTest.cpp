
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

TEST(ODTimeUtil, IsSameDay)
{
    EXPECT_TRUE(ODTimeUtil::IsSameDay(1528192338, 1528192339));
    EXPECT_TRUE(ODTimeUtil::IsSameDay(1528192338, 1528195000));
    EXPECT_TRUE(ODTimeUtil::IsSameDay(1528192338, 1528199000));
    EXPECT_TRUE(ODTimeUtil::IsSameDay(1528128000, 1528128001));
    EXPECT_FALSE(ODTimeUtil::IsSameDay(1528128000, 1528127999));
}
