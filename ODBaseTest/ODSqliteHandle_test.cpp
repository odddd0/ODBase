
#include <gtest/gtest.h>
#include <ODMBase/ODMTest.h>
#include <ODMBase/ODDBHandle.h>

StringTable testStrTable = {
    {"12", "vvasdf", "43"},
    {"32", "lgasdf", "34"}};

TEST(ODSqliteHandle, exec)
{
    ODMBaseList tmpList;
    ODDBHandle::Instance()->Setup("test.db");
    ODDBHandle::Instance()->Select<ODMTest>(tmpList);
    ODMTestPtr tmpPtr = std::static_pointer_cast<ODMTest>(tmpList[0]);
    ODMTestPtr tmpA = std::make_shared<ODMTest>();
    std::cout << "asd" << std::endl;
}

TEST(ODDBHandle, insert)
{
    ODMBaseList tmpList;
    tmpList.push_back(std::make_shared<ODMTest>(testStrTable[0]));
    tmpList.push_back(std::make_shared<ODMTest>(testStrTable[1]));
    ODDBHandle::Instance()->Insert(tmpList);
}
