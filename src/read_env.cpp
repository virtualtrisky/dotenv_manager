#include <read_env.hpp>

std::map<std::string, std::string> dotenv_manager::env;

void dotenv_manager::invalid_syntax_warning(const int& line_index)
{
    printf("[DOTENV_WARNING]: invalid syntax at line %i\n", line_index);
}

void dotenv_manager::trim(std::string& str)
{
    const auto str_begin = str.find_first_not_of(" \t\r\n\"");
    if (str_begin == std::string::npos) { str = ""; return; }

    const auto str_end   = str.find_last_not_of(" \t\r\n\"");
    const auto str_range = str_end - str_begin + 1;

    str = str.substr(str_begin, str_range);
}

bool dotenv_manager::load_env()
{
    std::ifstream file(".env");

    if (!file.is_open())
    {
        printf("[DOTENV_ERROR]: failed to open .env file\n");
        return false;
    }

    std::string line;
    int line_index = 0;
    while (std::getline(file, line))
    {
        line_index++;
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, '=') && std::getline(iss, value))
        {
            trim(key);
            trim(value);

            if (key.empty())
            {
                invalid_syntax_warning(line_index);
                continue;
            }

            env[key] = value;
        }
        else
        {
            invalid_syntax_warning(line_index);
        }
    }

    file.close();
    return true;
}