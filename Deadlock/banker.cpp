// C++ program to illustrate Banker's Algorithm
#include<iostream>
using namespace std;

// Number of processes

// Number of resources
const int R = 4;
// Function to find the need of each process
void calculateNeed(int need[100][R], int maxm[100][R],
				int allot[100][R], int n)
{
	// Calculating Need of each P
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < R ; j++)

			// Need of instance = maxm instance -
			//				 allocated instance
			need[i][j] = maxm[i][j] - allot[i][j];
}

// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][R],
			int allot[][R], int n)
{
	int need[n][R];

	// Function to calculate need matrix
	calculateNeed(need, maxm, allot, n);

	// Mark all processes as infinish
	bool finish[n] = {0};

	// To store safe sequence
	int safeSeq[n];

	// Make a copy of available resources
	int work[R];
	for (int i = 0; i < R ; i++)
		work[i] = avail[i];

	// While all processes are not finished
	// or system is not in safe state.
	int count = 0;
	while (count < n)
	{
		// Find a process which is not finish and
		// whose needs can be satisfied with current
		// work[] resources.
		bool found = false;
		for (int p = 0; p < n; p++)
		{
			// First check if a process is finished,
			// if no, go for next condition
			if (finish[p] == 0)
			{
				// Check if for all resources of
				// current P need is less
				// than work
				int j;
				for (j = 0; j < R; j++)
					if (need[p][j] > work[j])
						break;

				// If all needs of p were satisfied.
				if (j == R)
				{
					// Add the allocated resources of
					// current P to the available/work
					// resources i.e.free the resources
					for (int k = 0 ; k < R ; k++)
						work[k] += allot[p][k];

					// Add this process to safe sequence.
					safeSeq[count++] = p;

					// Mark this p as finished
					finish[p] = 1;

					found = true;
				}
			}
		}

		// If we could not find a next process in safe
		// sequence.
		if (found == false)
		{
			cout << "System is not in safe state" << endl;
			for(int i = 0; i < n; i++){
                if(finish[i] == 0){
                    cout << i << " ";
                }
            }
			return false;
		}
	}

	// If system is in safe state then
	// safe sequence will be as below
	cout << "System is in safe state.\nSafe"
		" sequence is: ";
	for (int i = 0; i < n ; i++)
		cout << safeSeq[i] << " ";

	return true;
}

// Driver code
int main()
{
	cout << "Input resources: " << endl;
	int resources[R];
	for(int i = 0; i < R; i++){
		cin >> resources[i];
	}
	int n;
	cout << "Enter number of processes: ";
	cin >> n ;

	int processes[n];
	for(int i = 0; i < n ; i++){
		processes[i] = i;
	}
	cout << endl;
	cout << "Input allot: "<< endl;
	int allot[100][R];
	for(int i = 0; i < n;  i++){
		for(int j = 0; j < R; j++){
			cin >> allot[i][j];
		}
	}
	// Available instances of resources
	cout << "Input avail: " << endl;
	int avail[R];
	for(int i = 0; i < R; i++){
		cin >> avail[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < R; j++){
			resources[j] -= allot[i][j];
		}
	}

	// Maximum R that can be allocated
	// to processes
	cout << "Input maxm: " << endl; 
	int maxm[100][R];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < R; j++){
			cin >> maxm[i][j];
		}
	}
	// Resources allocated to processes

	// Check system is in safe state or not
	isSafe(processes, avail, maxm, allot, n);

	return 0;
}
