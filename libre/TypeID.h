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

// Easily replicate the boilerplate code necessary for components (sorry).
#define DEFINE_TYPE_ID(type) virtual inline libre::TypeID GetTypeID() const override { return libre::TypeIDUtility::Get<type>(); }
