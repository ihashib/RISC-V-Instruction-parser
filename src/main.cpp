#include <iostream>
#include "../classes/inc/file.h"
#include "../classes/inc/riscv_inst.h"
#include "../classes/inc/instruction_parser.h"


int main()
{
    //Read instrctions from file
    std::vector<std::string> ins_str;
    file_operation file("/media/ihashib/New Volume/Work/CC++/dsi_solve/data/RISC-V.txt");

    ins_str = file.read_file();
    file.print_file_content();

    //RISC V instruction object
    instructions risc_v_inst;
    std::vector<instructions> instructions_vec;

    //Parse instructions
    ins_parse ins_parse_obj;
    instructions_vec = ins_parse_obj.parse_str(ins_str);

    //print instructions
    risc_v_inst.print_instructions(instructions_vec);

    return 0;
}