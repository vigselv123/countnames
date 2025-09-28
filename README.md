Purpose: This code returns the number of times a name is found in a file
Author name: Vignesh Selvaraj
Author email: vignesh.selvaraj@sjsu.edu
Last modified date: 10/1/2025
Creation date: 9/27/2025

Github link:

To get the run time for the longest file: time ./countnames test/names_long.txt
Run it 3 times and get the average.

1st run:
real: 0m0.002s
user: 0m0.002s
sys:  0m0.000s

2nd run:
real: 0m0.002s
user: 0m0.001s
sys:  0m0.001s

3rd run:
real: 0m0.002s
user: 0m0.000s
sys:  0m0.002s

Average runtime:
real: 0m0.002s
user: 0m0.001s
sys:  0m0.001s

The test cases are in the test folder. To run the program, compile it by
opening the terminal. In the terminal, go to the directory that has the test folder 
and the countnames file, then enter:

gcc -o coutnames countnames.c -Wall -Werror

To run test case 1:
./countnames test/names.txt or ./countnames names.txt depending on where the text files are under
Expected result:
Warning - Line 2 is Empty
Warning - Line 5 is Empty
Nicky: 1
Dave Joe: 2
Yuan Cheng Cheng: 3
John Smith: 1

Same command with different .txt name for different test inputs, format of results should follow results above
