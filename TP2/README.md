We are using Vs Code terminal.
For all exercices, we will use the command "g++ -std=c++17 -o exo[num] -DEXO=num main.cpp", if we remove the part '-DEXO=num' that create the Macro EXO, the EXO is defined and unitialized by 1.
For Exercice1, we can use "g++ -std=c++17 -o exo[num] -DDEBUG main.cpp" so automatically the program compile the first exercice and we define the Macro DEBUG.
So after compiling our c++ code, for exo1, exo3 and exo4 we run the command './exo[num]', for exercice2 as the main function takes arguments ,we run the command './exo2 arg1 arg2 ...'. 
