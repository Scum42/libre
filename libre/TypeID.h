#pragma once

namespace libre
{
    typedef unsigned long TypeID;

    class TypeIDUtility
    {
    private:
        static TypeID counter;

    public:
        template <typename T>
        static TypeID Get();
    };
}