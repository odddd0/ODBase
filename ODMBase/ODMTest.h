#ifndef ODMTEST_H
#define ODMTEST_H

#include "ODMBase.h"

struct ODMTest : public ODMBase
{
public:
    ODMTest();
    ODMTest(const StringList &stringList);

public:
    static void GetSqlCreateTable(std::string &sql_);
    static void GetSqlSelect(std::string &sql_);
    void GetSqlInsert(std::string &sql_);

private:
    std::string _name;
    int _score;

private:
    static bool _init;
};
typedef std::shared_ptr<ODMTest> ODMTestPtr;

#endif // ODMTEST_H
