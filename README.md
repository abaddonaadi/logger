#Intro:-
This is a very basic logger program. It prints the logs from main.

#To build the code:- 
g++ main.cpp Logger.cpp -o <Executable_Name>

#To run the executable file:-
./<Executable_Name>

#Log Level:-
0- DEBUG
1- INFO
2- WARNING
3- ERROR

Log levels are based on decreasing priority
Which means, if DEBUG is selected all 4 log levels are visibble.
If Warning is selected only Warning and Error is visible
