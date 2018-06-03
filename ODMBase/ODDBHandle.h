#ifndef _ODDBHANDLE_H_DB81DA8B00554332D1F1E565FEAE9A99_
#define _ODDBHANDLE_H_DB81DA8B00554332D1F1E565FEAE9A99_

#include "ODBaseTypes.h"
#include "ODMBase.h"
#include "ODSqliteHandle.h"

class ODDBHandle
{
public:
    static ODDBHandle * Instance();

public:
    void Setup(const std::string &DBPath);

public:
    template<class T>
    bool Select(ODMBaseList &list)
    {
        std::string errMsg;
        return SelectImpl<T>(list, errMsg);
    }

    template<class T>
    bool Select(ODMBaseList &list, std::string &errMsg)
    {
        return SelectImpl<T>(list, errMsg);
    }

    bool Insert(const ODMBaseList &list)
    {
        std::string errMsg;
        return InsertImpl(list, errMsg);
    }
    bool Insert(const ODMBaseList &list, std::string &errMsg)
    {
        return InsertImpl(list, errMsg);
    }

private:
    template<class T>
    bool SelectImpl(ODMBaseList &list, std::string &errMsg)
    {
        bool Result = false;
        StringTable stringTable;
        std::string sql = "";
        T::GetSqlSelect(sql);
        Result = ODSqliteHandle::Exec(_DBPath, sql, stringTable, errMsg);
        std::for_each(stringTable.begin(), stringTable.end(), [&list](StringList &x){
            list.push_back(std::make_shared<T>(x));
        });
        return Result;
    }

    bool InsertImpl(const ODMBaseList &list, std::string &errMsg);
private:
    ODDBHandle();
    ~ODDBHandle();

private:
    std::string _DBPath;
};

#endif // _ODDBHANDLE_H_DB81DA8B00554332D1F1E565FEAE9A99_
