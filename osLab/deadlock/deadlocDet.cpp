#include <iostream>
#include <vector>

using namespace std;

const int MAX_PROCESS = 10;
const int MAX_RESOURCE = 10;

vector<vector<int>> allocation(MAX_PROCESS, vector<int>(MAX_RESOURCE));
vector<vector<int>> max_demand(MAX_PROCESS, vector<int>(MAX_RESOURCE));
vector<int> available(MAX_RESOURCE);
vector<bool> marked(MAX_PROCESS);

int num_processes, num_resources;

void initialize() {
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    cout << "Enter the number of resources: ";
    cin >> num_resources;

    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter maximum demand matrix:\n";
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> max_demand[i][j];
        }
    }

    cout << "Enter available resources:\n";
    for (int j = 0; j < num_resources; j++) {
        cin >> available[j];
    }

    for (int i = 0; i < num_processes; i++) {
        marked[i] = false;
    }
}

bool is_safe(int process, vector<int>& work) {
    for (int j = 0; j < num_resources; j++) {
        if (max_demand[process][j] - allocation[process][j] > work[j]) {
            return false;
        }
    }
    return true;
}

bool detect_deadlock() {
    vector<int> work = available;

    int count = 0;
    while (count < num_processes) {
        bool found = false;
        for (int i = 0; i < num_processes; i++) {
            if (!marked[i] && is_safe(i, work)) {
                marked[i] = true;
                for (int j = 0; j < num_resources; j++) {
                    work[j] += allocation[i][j];
                }
                found = true;
                count++;
            }
        }
        if (!found) {
            return true; // Deadlock detected
        }
    }
    return false; // No deadlock detected
}

int main() {
    initialize();

    if (detect_deadlock()) {
        cout << "Deadlock detected!" << endl;
    } else {
        cout << "No deadlock detected." << endl;
    }

    return 0;
}
