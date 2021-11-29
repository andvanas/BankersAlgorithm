// Andrew Vanas
// 11/27/21

#include <iostream>
#include <fstream>

using namespace std;

// setting global variables for the # of processes(P) and resources(R)
const int P = 5;
const int R = 3;

// calculates the need matrix
void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R])
{
    for (int i = 0 ; i < P ; i++)
    {
        for (int j = 0 ; j < R ; j++)
	{
	    // operation needed to calculate the need matrix (need = max - allocated)
            need[i][j] = maxm[i][j] - allot[i][j];
	}
    }
}

// calculates if the system is in a safe state or not
bool isSafe(int processes[], int avail[], int maxm[][R], int allot[][R])
{
    int need[P][R];
    calculateNeed(need, maxm, allot);
    // array for marking as either finished or unfinished
    bool finish[P] = {0};
    // array to store the safe sequence
    int safeSeq[P];
    // array that is a copy of available resources
    int work[R];
    for (int i = 0; i < R ; i++)
    {
        work[i] = avail[i];
    }
    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            // checks to see if the process is finished
            if (finish[p] == 0)
            {
                int j;
		// checks if the need is less than the work for each resource
                for (j = 0; j < R; j++)
		{
                    if (need[p][j] > work[j])
		    {
                        break;
		    }
		}
                // if all needs of P are satisfied...
                if (j == R)
                {
                    for (int k = 0; k < R; k++)
                    {
                        work[k] += allot[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
	// checks to see if the system is not in a safe state
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }
    // outputs that the system is in a sage state and lists the sequence
    cout << "System is in safe state.\nSafe sequence is: ";
    for (int i = 0; i < P ; i++)
    {
        cout << safeSeq[i] << " ";
    }
    cout << "\n";
    return true;
}

int main()
{
    // initializes the processes and available arrays
    int processes[] = {0,1,2,3,4};
    int available[3];
    // initializes the max and allocation matrices
    int max[P][R];
    int allocation[P][R];
    // opens the file that contains the input for the program
    ifstream inputFile("input.txt");
    while(inputFile)
    {
	// loops through the first line in the file to get the values for the available array
        for(int i=0;i<3;i++)
        {
            inputFile >> available[i];
        }
	// loops for 5 lines to extract the values for the allocation matrix
	for(int i=0;i<P;i++)
	{
	    for(int j=0;j<R;j++)
	    {
	        inputFile >> allocation[i][j];
	    }
	}
	// loops for 5 more lines to extract the values for the max matrix
	for(int i=0;i<P;i++)
        {
            for(int j=0;j<R;j++)
            {
                inputFile >> max[i][j];
            }
        }

    }
    isSafe(processes, available, max, allocation);
    return 0;
}
