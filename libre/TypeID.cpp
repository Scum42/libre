#include "TypeID.h"

using namespace libre;

TypeID TypeIDUtility::counter = 0;

template<typename T>
TypeID TypeIDUtility::Get()
{
    static TypeID id = counter++;
    return id;
}