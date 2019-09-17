#pragma once
#include <stdexcept>
#include "non-transferable.hpp"

namespace design_pattern
{
    template<class Instance>
    struct Exclusive: Non_Transferable
    {
        using instance_type = Instance;

        Exclusive()
        {
            if(instance != nullptr){
                throw std::logic_error("Duplicated.");
            }

            instance = static_cast<instance_type*>(this);
        }

        ~Exclusive() 
        { 
            //delete instance;
            instance = nullptr;
        }

        static auto current() -> instance_type&
        {
            if(instance == nullptr){
                throw std::logic_error("Not initialize.");
            }
            return *instance;
        }

    private:
        static instance_type* instance;
    };

    template<class Instance>
    typename Exclusive<Instance>::instance_type* 
    Exclusive<Instance>::instance = nullptr;
}