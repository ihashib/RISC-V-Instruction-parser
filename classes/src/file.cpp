#include "../inc/file.h"

//constructor definition
file_operation::file_operation(std::string file_path)
{
    this->file_path = file_path;
    file_error = false;
    file_read = false;
}

//descructor definition
file_operation::~file_operation()
{
    file_error = false;
    file_read = false;
    file_path = "";
}

//read file content and store into vector
std::vector<std::string> file_operation::read_file()
{
    std::ifstream file(this->file_path);
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            file_content.push_back(line);
        }
        file.close();

        std::cout << "File read!" << std::endl;
    }
    else
    {
        file_error = true;
        std::cout << "File not read" << std::endl;
    }

    return file_content;
}

//print file content
void file_operation::print_file_content()
{
    if (!file_error)
    {
        for (auto i = 0; i < file_content.size(); i++)
        {
            std::cout << file_content[i] << std::endl;
        }
    }
    else
    {
        std::cout << "File not read, can not print" << std::endl;
    }
}

//close file
void file_operation::file_close()
{
    file_error = false;
    file_read = false;
    file_path = "";
}





