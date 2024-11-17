#include<iostream> 
using namespace std; 

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum, int at[]) { 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; 
	while (true) { 
		bool done = true; 

		for (int i = 0 ; i < n; i++) { 
			if (rem_bt[i] > 0 && at[i] <= t) { 
				done = false; 
				if (rem_bt[i] > quantum) { 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} else { 
					t += rem_bt[i]; 
					wt[i] = t - bt[i] - at[i]; // Corrected this line
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done) break; 
	} 
}


void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) { 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int n, int bt[], int at[], int quantum) { 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	findWaitingTime(processes, n, bt, wt, quantum, at); 
	findTurnAroundTime(processes, n, bt, wt, tat); 

	cout << "PN\tAT\tBT\tWT\tTAT\n"; 

	for (int i=0; i<n; i++) { 
		total_wt += wt[i]; 
		total_tat += tat[i]; 
		cout << "P" << processes[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl; 
	} 

	cout << "Average waiting time = " << (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl; 

	cout << "\nGantt Chart:\n";
	int current_time = 0;
	while (true) {
		bool all_done = true;
		for (int i = 0; i < n; ++i) {
			if (bt[i] > 0 && at[i] <= current_time) {
				all_done = false;
				cout << "| P" << processes[i] << " ";
				if (bt[i] > quantum) {
					current_time += quantum;
					bt[i] -= quantum;
				} else {
					current_time += bt[i];
					bt[i] = 0;
				}
				cout << " (" << current_time << ") ";
			}
		}
		if (all_done) break;
	}
	cout << "|\n";
} 

int main() { 
	int processes[] = {1, 2, 3,4,5,6}; 
	int n = sizeof processes / sizeof processes[0]; 

	int burst_time[] = {5, 6, 3,1,5,4}; 
	int arrival_time[] = {0, 1,2,3,4, 6}; 
	int quantum = 4; 
	findavgTime(processes, n, burst_time, arrival_time, quantum); 
	return 0; 
} 
