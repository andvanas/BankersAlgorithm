# BankersAlgorithm
An example of bankers algorithm for deadlock avoidance given to us in an assignment in CS33211 at Kent State University.

The purpose of this assignment (Programmming Assignment #2 in CS33211) is to implement the bankers algorithm for deadlock prevention.
The input for the matrices is within input.txt. The program reads the values from the file and assigns each value to the specific array/matrix index
that is given to us within the instructions. I tried to comment for almost all of processes within the files but, to sum it up, the main function
reads the values from input.txt and calls the isSafe() function. This functions calculates if there is a safe state or not, as well as calling the
calculateNeed() function which calculates the need matrix for the program. Each of these 3 functions work coherently to find out if the input has a
safe state as well the sequence.

Note: within input.txt, the first line contains the values for the available instances of the resources. The following 5 lines contain the values for the
allocation matrix. The next 5 lines after the allocation matrix is filled contains the values for the max matrix.
