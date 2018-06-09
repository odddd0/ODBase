//====================================================================
//  ODTimeUtilTest.cpp
//  created 6.5.18
//  written by odddd0
//
//  https://github.com/odddd0/ODWay
//====================================================================

#include <gtest/gtest.h>

#include <ODUtil/ODTimeUtil.h>

TEST(ODTimeUtil, ToString)
{
    std::string tmpStr;
    tmpStr = ODTimeUtil::Timestamp2String(1528184066, "%y%m%d_%H%M%S");
    EXPECT_EQ("180605_153426", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(1528184066, "%dDays %2Hhour %2MMinute %2SSecond");
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

TEST(ODTimeUtil, Duration2Str)
{
    std::string tmpStr;
    tmpStr = ODTimeUtil::Duration2String(12);
    EXPECT_EQ("12s", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(72);
    EXPECT_EQ("01m", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(1002);
    EXPECT_EQ("16m", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(3002);
    EXPECT_EQ("50m", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(7002);
    EXPECT_EQ("1h56m", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(27002);
    EXPECT_EQ("7h30m", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(227002);
    EXPECT_EQ("2d 15h03m", tmpStr);

    tmpStr = ODTimeUtil::Duration2String(12, "__DIGITAL__");
    EXPECT_EQ("00:00:12", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(72, "__DIGITAL__");
    EXPECT_EQ("00:01:12", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(1002, "__DIGITAL__");
    EXPECT_EQ("00:16:42", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(3002, "__DIGITAL__");
    EXPECT_EQ("00:50:02", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(7002, "__DIGITAL__");
    EXPECT_EQ("01:56:42", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(27002, "__DIGITAL__");
    EXPECT_EQ("07:30:02", tmpStr);
    tmpStr = ODTimeUtil::Duration2String(227002, "__DIGITAL__");
    EXPECT_EQ("2-15:03:22", tmpStr);
}
