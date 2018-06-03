
#include "ODMBase.h"

ODMBase::ODMBase(const int &id_)
    : _preId(id_)
    , _id(id_)
    , _type("ODMBase")
{

}

ODMBase::ODMBase(const std::string &type_)
    : _type(type_)
{
    time_t curTime = 0;
    _preId = _id = time(&curTime);
}

ODMBase::ODMBase(const std::string &type_, const int &id_)
    : _preId(id_)
    , _id(id_)
    , _type(type_){}
