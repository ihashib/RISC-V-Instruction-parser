#ifndef _RISCV_INST_H_
#define _RISCV_INST_H_

#include <iostream>
#include <string>
#include <vector>

class instructions{
    private:
        bool instruction_set;   //true if instruction is set/given

    public:
        std::string opcode;
        std::string operands;

    public:
        instructions();         //constructor
        ~instructions();        //destructor

        void set_instruction(std::string &opcode, std::string &operands);       //set opcode and operands of the instuction
        void print_instructions(std::vector<instructions> &instructions_vec);   //print opcode and operands of the instruction

};

#endif