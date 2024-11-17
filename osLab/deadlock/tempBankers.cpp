#include <iostream>
#include <vector>

using namespace std;

// Function to check if allocating resources can avoid deadlock
bool isSafe(vector<vector<int>>& max, vector<vector<int>>& allocation, vector<int>& available, vector<int>& work, vector<bool>& finish, int processCount, int resourceCount) {
    vector<vector<int>> need(processCount, vector<int>(resourceCount));

    // Initialize need matrix
    for (int i = 0; i < processCount; ++i) {
        for (int j = 0; j < resourceCount; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count = 0;
    while (count < processCount) {
        bool found = false;
        for (int i = 0; i < processCount; ++i) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < resourceCount; ++j) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == resourceCount) {
                    for (int k = 0; k < resourceCount; ++k)
                        work[k] += allocation[i][k];
                    finish[i] = true;
                    ++count;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }

    for (int i = 0; i < processCount; ++i) {
        if (!finish[i])
            return false;
    }
    return true;
}

int main() {
    int processCount, resourceCount;

    cout << "Enter the number of processes: ";
    cin >> processCount;

    cout << "Enter the number of resources: ";
    cin >> resourceCount;

    vector<vector<int>> max(processCount, vector<int>(resourceCount));
    vector<vector<int>> allocation(processCount, vector<int>(resourceCount));
    vector<int> available(resourceCount);

    // Input maximum resources needed by each process
    cout << "Enter the maximum resources needed by each process:\n";
    for (int i = 0; i < processCount; ++i) {
        cout << "For process " << i << ":\n";
        for (int j = 0; j < resourceCount; ++j)
            cin >> max[i][j];
    }

    // Input allocated resources to each process
    cout << "Enter the allocated resources to each process:\n";
    for (int i = 0; i < processCount; ++i) {
        cout << "For process " << i << ":\n";
        for (int j = 0; j < resourceCount; ++j)
            cin >> allocation[i][j];
    }

    // Input available resources
    cout << "Enter the available resources:\n";
    for (int j = 0; j < resourceCount; ++j)
        cin >> available[j];

    vector<int> work = available;
    vector<bool> finish(processCount, false);

    if (isSafe(max, allocation, available, work, finish, processCount, resourceCount))
        cout << "The system is in safe state.\n";
    else
        cout << "The system is in unsafe state.\n";

    return 0;
}