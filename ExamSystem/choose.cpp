#include "choose.h"

class chooseData : public QSharedData
{
public:

};

choose::choose() : data(new chooseData)
{

}

choose::choose(const choose &rhs) : data(rhs.data)
{

}

choose &choose::operator=(const choose &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

choose::~choose()
{

}
