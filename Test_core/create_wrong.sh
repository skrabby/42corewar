#!/bin/sh




./asm check_wrong/unknown_instruction.s
./asm check_wrong/wrong_argument.s
./asm check_wrong/wrong_character_label.s
./asm check_wrong/wrong_lexical.s
./asm check_wrong/wrong_refer.s
./asm check_wrong/wrong_type.s



echo "======================================================="


./asm1 check_wrong/unknown_instruction.s
./asm1 check_wrong/wrong_argument.s
./asm1 check_wrong/wrong_character_label.s
./asm1 check_wrong/wrong_lexical.s
./asm1 check_wrong/wrong_refer.s
./asm1 check_wrong/wrong_type.s


echo "DONE CREATE CHAMPIONS"