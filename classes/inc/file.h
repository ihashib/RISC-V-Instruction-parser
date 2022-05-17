#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class file_operation {
    public:
        std::string file_path;                  //file path
        bool file_read;                         //true if file is read
        bool file_error;                        //true if file is not found
        std::vector<std::string> file_content;  //file content

    public:
        file_operation(std::string file_path);  //constructor
        ~file_operation();                      //destructor

        std::vector<std::string> read_file();   //read file content and store into vector
        void print_file_content();              //print file content

        virtual void file_close();
};

#endif
