CC = g++
CXXFLAGS = -std=c++17 -Wall

riscv_instruction_parser: src/main.o classes/src/file.o classes/src/instruction_parser.o classes/src/riscv_inst.o
	g++ src/main.o classes/src/file.o classes/src/instruction_parser.o classes/src/riscv_inst.o -o riscv_instruction_parser

main.o: src/main.cpp inc/main.cpp
	g++ -c src/main.cpp 	

files.o: classes/src/files.cpp classes/inc/files.h 
	g++ -c classes/src/file.cpp

instruction_parser.o: classes/src/instruction_parser.cpp classes/inc/instruction_parser.h
	g++ -c classes/src/instruction_parser.cpp

riscv_inst.o: classes/src/riscv_inst.cpp classes/inc/riscv_inst.h 
	g++ -c classes/src/riscv_inst.cpp
