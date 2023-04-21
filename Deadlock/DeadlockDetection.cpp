#include<bits/stdc++.h>
using namespace std;
const int R = 3;
bool solve(int processes[], int work[], int allocation[][R],
            int request[][R], int n)
{
    // Mark all processes as infinish
    bool finish[n] = {0};

    // To store safe sequence
    int safeSeq[n];

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
                    if (request[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allocation[p][k];

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
int main(){
    int resources[R];
    cout << "Enter resources: " << endl;
    for(int i = 0; i < R; i++){
        cin >> resources[i];
    }
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int processes[n];
    for(int i = 0; i < n; i++){
        processes[i] = i;
    }
    int allocation[n][R];
    cout << "Input allocation: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < R; j++){
            cin >> allocation[i][j];
            resources[j] -= allocation[i][j];
        }
    }
    int request[n][R];
    cout << "Input Request: " << endl;
    for(int i = 0; i <  n; i++){
        for(int j = 0; j < R; j++){
            cin >> request[i][j];
        }
    }
    solve(processes, resources, allocation, request,  n);
}