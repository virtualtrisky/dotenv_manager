#include <iostream>
#include <dotenv_manager.hpp>

int main()
{
    dotenv_manager::load_env();

    std::cout << "Keys:\n";
    for (auto pair : dotenv_manager::env)
    {
        auto [key, value] = pair;

        std::cout << key << ": " << value << '\n';
    }

    return 0;
}
