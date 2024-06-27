bison -d Compiler.y
flex Compiler.l
gcc lex.yy.c Compiler.tab.c -o Compiler -lm -std=c99
./Compiler