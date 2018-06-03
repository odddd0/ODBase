#include "ODDBHandle.h"

ODDBHandle *ODDBHandle::Instance()
{
    static ODDBHandle * obj = new ODDBHandle;
    return obj;
}

ODDBHandle::ODDBHandle()
{

}

ODDBHandle::~ODDBHandle()
{

}

void ODDBHandle::Setup(const std::string &DBPath)
{
    _DBPath = DBPath;
}

bool ODDBHandle::InsertImpl(const ODMBaseList &list, std::string &errMsg)
{
    bool Result = false;
    std::string sql = "";

    std::for_each(list.begin(), list.end(), [&sql](const ODMBasePtr &x){
        x->GetSqlInsert(sql);
    });
    Result = ODSqliteHandle::Exec(_DBPath, sql, errMsg);
    return Result;
}


