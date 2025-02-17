We are using Vs Code terminal. For all exercices, we will use the command "g++ -std=c++17 -o main -DEXO=num main.cpp",
if we remove the part '-DEXO=num' that create the Macro EXO, the EXO is defined and unitialized by 1.
For exo1, instead of '-DEXO=num', we can write '-DDEBUG' that will define the macro DEBUG.
So after compiling our c++ code, we will use the command ./main and then the program start (exo[num]).
