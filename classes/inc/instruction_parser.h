#ifndef _INSTRUCTION_PARSER_H_
#define _INSTRUCTION_PARSER_H_

#include <iostream>
#include <string>
#include <vector>
#include "riscv_inst.h"

class ins_parse: public instructions{

    protected:
        char comment_char;                  
        std::vector <std::string> opcode_list;                                                          //predefined list of opcode
        std::vector <uint8_t> opcode_operand_count;                                                     //predefined list of operand count each opcode takes
        std::string delim;                                                                              //delimiter for counting operands

    public:
        ins_parse();                                                                                                                                      //default constructor
        ins_parse(std::string delim, char comment_char, std::vector<std::string> &opcode_list, std::vector <uint8_t> &opcode_operand_count);       //Can set instruction list and comment char   
        ~ins_parse();                                                                                                                                     //destructor

        bool parse_comment(std::string ins_str);                                   //parse comment

        std::vector <instructions> parse_str(std::vector<std::string> &ins_str);   //parse string of each instruction

};

#endif