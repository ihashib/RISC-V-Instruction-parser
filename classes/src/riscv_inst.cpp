#include "../inc/riscv_inst.h"

instructions::instructions()
{
    opcode = "";
    operands = "";
    instruction_set = false;
}

instructions::~instructions()
{
    opcode = "";
    operands = "";
    instruction_set = false;
}

void instructions::set_instruction(std::string &opcode, std::string &operands)
{
    //set opcode and operands of the instuction
    this->opcode = opcode;
    this->operands = operands;

    instruction_set = true;
};

void instructions::print_instructions(std::vector<instructions> &instructions_vec)
{
    //check if vector is empty, iterate vector and print
    if(instructions_vec.size() > 0)
    {
        std::cout << "###Print Opcode and operands###" << std::endl;
        
        for(auto i = 0; i < instructions_vec.size(); i++)
        {
            std::cout << "opcode :"<< instructions_vec[i].opcode << std::endl;

            std::cout << "Operands: " << instructions_vec[i].operands << std::endl;
        }
    }
    else
    {
        std::cout << "No instructions" << std::endl;
    }
}