#pragma once
namespace design_pattern
{
    struct Non_Transferable
    {
        Non_Transferable() = default;
        Non_Transferable(Non_Transferable const&) = delete;
        Non_Transferable(Non_Transferable &&) = delete;
        auto operator=(Non_Transferable const&) -> Non_Transferable& = delete;
        auto operator=(Non_Transferable &&) -> Non_Transferable& = delete;
    };
}