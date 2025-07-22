# Dotenv Manager

This program is a simple way to work with **dotenv**.


<br>

## How to include

- Add the header file **dotenv_manager.hpp** inside the **include** folder at the root of the project.


<br>

## How to compile

```shell
g++ src/main.cpp src/dotenv_manager.cpp -o path/to/executable -Iinclude
```

In this case, ```-Iinclude``` is the folder where **dotenv_manager.hpp** is


<br>

## How load .env file

To use it, first you need load the **.env** file. You can do this with the following command:

```c++
dotenv_manager::load_env();
```

This function will return a **boolean** value, **true** if it load the file properly and **false** if failed to load.


<br>

## How get values

The variable ```dotenv_manager::env``` is a ```std::map<std::string, std::string>```. So, you can access values by the name of them.

```c++
dotenv_manager::env["NAME"];
//or
dotenv_manager::env.at("NAME");
```