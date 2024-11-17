#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int priority;
};

bool comparePriority(const Process& p1, const Process& p2) {
    return p1.priority < p2.priority;
}

void priorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), comparePriority);

    int currentTime = 0;
    double total_waiting_time = 0, total_turnaround_time = 0;

    cout << "Gantt Chart:" << endl;
    for (const auto& process : processes) {
        cout << "P" << process.id << " ";
        currentTime += process.burst_time;
        total_waiting_time += currentTime - process.burst_time;
        total_turnaround_time += currentTime;
        cout << currentTime << " ";
    }
    cout << endl;

    cout << "Average Waiting Time: " << total_waiting_time / processes.size() << endl;
    cout << "Average Turnaround Time: " << total_turnaround_time / processes.size() << endl;
}

int main() {
    vector<Process> processes = {
        {1, 6, 2},
        {2, 8, 1},
        {3, 7, 2},
        {4, 3, 0}
    };

    priorityScheduling(processes);

    return 0;
}
