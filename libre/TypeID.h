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
        inline static TypeID Get()
        {
            static TypeID id = counter++;
            return id;
        }
    };
}