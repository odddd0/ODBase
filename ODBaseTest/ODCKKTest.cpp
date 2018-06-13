//====================================================================
//  ODCKKTest.cpp
//  created 6.13.18
//  written by odddd0
//
//  https://github.com/odddd0/ODWay
//====================================================================

#include <gtest/gtest.h>

#include <ODUtil/ODCKK.h>

TEST(ODCKK, ToString)
{
    CKKPtr ckk = std::make_shared<ODCKK>();
    ckk->appendData("1", "11", "111");
    ckk->appendData("1", "11", "112");
    ckk->appendData("1", "12", "121");
    ckk->appendData("1", "13", "131");
    ckk->appendData("2", "21", "211");
    ckk->appendData("2", "22", "221");
    ckk->appendData("2", "23", "231");
    ckk->appendData("3", "31", "311");

    StringList tmpList;
    ckk->classifyList(tmpList);
    ckk->kindFirstList(tmpList, "1");
    ckk->kindFirstList(tmpList, "2");
    ckk->kindFirstList(tmpList, "3");
    ckk->kindFirstList(tmpList, "4");
    ckk->kindSecondList(tmpList, "1", "11");
    ckk->kindSecondList(tmpList, "1", "13");
    ckk->kindSecondList(tmpList, "2", "21");
    ckk->kindSecondList(tmpList, "3", "31");
    ckk->kindSecondList(tmpList, "3", "32");
    ckk->kindFirstList(tmpList);
    ckk->kindSecondList(tmpList, "2");
    ckk->kindSecondList(tmpList);
}
