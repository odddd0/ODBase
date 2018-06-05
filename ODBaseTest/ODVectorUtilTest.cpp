
#include <gtest/gtest.h>

#include <ODUtil/ODVectorUtil.h>

TEST(ODVectorUtil, RefreshInsert)
{
    StringList tmpList;
    ODVectorUtil::RefreshInsert<std::string>(tmpList, "1");
    ODVectorUtil::RefreshInsert<std::string>(tmpList, "2");
    ODVectorUtil::RefreshInsert<std::string>(tmpList, "3");
    ODVectorUtil::RefreshInsert<std::string>(tmpList, "2");
    ODVectorUtil::RefreshInsert<std::string>(tmpList, "1");
}
