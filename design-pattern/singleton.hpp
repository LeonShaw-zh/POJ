#pragma once
#include "non-transferable.hpp"

namespace design_pattern
{
    template<class Instance>
    struct Singleton: Non_Transferable
    {
        using instance_type = Instance;

        static auto instance() -> instance_type&
        {
            static instance_type ins;
            return ins;
        }

    protected:
        Singleton() = default;
    };
}