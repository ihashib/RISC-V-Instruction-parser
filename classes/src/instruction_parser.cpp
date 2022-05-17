#include "../inc/instruction_parser.h"

ins_parse::ins_parse()
{
    comment_char = '#';                                                  //comment char
    delim = ", ";                                                        //delimiter for counting operands
    opcode_list = {"add", "addi", "sub", "subi", "la", "li", "ecall"};   //predefined list of opcode
    opcode_operand_count = {3, 3, 3, 3, 2, 2, 0};                        //predefined list of operand count each opcode takes
}

ins_parse::ins_parse(std::string delim, char comment_char, std::vector<std::string> &opcode_list, std::vector <uint8_t> &opcode_operand_count)
{
    //enables to set delim, comment and list of opcodes list and operand count
    this->comment_char = comment_char;
    this->opcode_list = opcode_list;
    this->opcode_operand_count = opcode_operand_count;
    this->delim = delim;
}

ins_parse::~ins_parse()
{
    delim = "";
    comment_char = NULL;        
    opcode_list.clear();
    opcode_operand_count.clear();
}

bool ins_parse::parse_comment(std::string ins_str)
{
    //if the first char of a line is the comment char, return true
    if(ins_str[0] == comment_char)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector <instructions> ins_parse::parse_str(std::vector<std::string> &ins_str)   //parse string
{
    instructions ins;
    std::vector<instructions> instruction_vec;
    std::string operands;
    std::string opcode;
    
    //if the size of the referenced vector is 0, return empty vector
    if(ins_str.size() == 0)
    {
        std::cout << "No instruction set!" << std::endl;

        return instruction_vec;
    }
    else
    {
        //iterate though the referenced vector
        for(auto i = 0; i < ins_str.size(); i++) 
        {
            //parse comments
            if(parse_comment(ins_str[i]))
            {
                continue;
            }
            
            //Find the opcode and separate it
            auto opcode_last = ins_str[i].find_first_of(" ", 1, ins_str.size()-1);
            
            if(opcode_last != 1)
            {
                this->opcode = ins_str[i].substr(0, opcode_last);
            }
            else
            {
                //If the opcode has no operands, opcode_last returns 1
                //No need to check for the operands
                this->opcode = ins_str[i].substr(0, ins_str.size()-1);
            }

            std::cout << "opcode: " << this->opcode << std::endl;

            //check if the opcode is in the list
            auto opcode_index = 0;
            for(opcode_index = 0; opcode_index < opcode_list.size(); opcode_index++)
            {
                if(this->opcode == opcode_list[opcode_index])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }

            //If the opcode has operands
            if(opcode_last != 1)
            {
                //Separate operands
                this->operands = ins_str[i].substr(opcode_last + 1, ins_str[i].size());

                std::cout << "operands: " << this->operands << std::endl;
                
                //operands count
                auto operand_count = 0;
                std::string::size_type pos = 0;
                while ((pos = this->operands.find(delim, pos )) != std::string::npos) {
                        ++operand_count;
                        pos += delim.length();
                }
                ++operand_count;        //while loop finds the delimiter only, not the operands

                std::cout << "operand_count: " << operand_count << std::endl;

                //check opcode operant count and set opcode and operands
                if(operand_count != opcode_operand_count[opcode_index])
                {
                    std::cout << "Operand count does not match" << std::endl;
                }
                else
                {                    
                    ins.set_instruction(this->opcode, this->operands);
                    instruction_vec.push_back(ins);
                    operand_count = 0;
                }
            }
            else
            {
                //If opcode has no operands
                operands = "No operands";
                ins.set_instruction(this->opcode, this->operands);
                instruction_vec.push_back(ins);
            }

            //reset opcode and operands
            this->opcode = "";
            this->operands = "";
        }
    }
    return instruction_vec;
}