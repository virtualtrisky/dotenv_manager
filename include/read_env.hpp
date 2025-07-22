#ifndef _READ_ENV_HPP
#define _READ_ENV_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>

namespace dotenv_manager
{
    extern std::map<std::string, std::string> env;

    void invalid_syntax_warning(const int& line_index);

    void trim(std::string& str);

    /* @brief
     * Function used to load .env file and pull all environment variables into 'env' container.
     *
     * Will return false if cannot load file.
    */
    bool load_env();
}

#endif