// Function for FCFS Scheduling
void fcfs(Process processes[], int n) {
    printf("\n--- FCFS Scheduling ---\n");
    sort_by_arrival(processes, n);

    int time = 0;
    float total_waiting = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival) {
            time = processes[i].arrival; // CPU idle time
        }

        processes[i].waiting = time - processes[i].arrival;
        time += processes[i].burst;
        processes[i].turnaround = processes[i].waiting + processes[i].burst;

        total_waiting += processes[i].waiting;
        total_turnaround += processes[i].turnaround;

        printf("Process %d: Waiting = %d, Turnaround = %d\n",
               processes[i].pid, processes[i].waiting, processes[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
}
