#include <stdio.h>

struct Process
{
    int pid;
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

void sortProcesses(struct Process p[], int n)
{
    struct Process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    // Sort by Burst Time (The core of SJF)
    sortProcesses(p, n);

    // Calculate Waiting Time and Turnaround Time
    p[0].wt = 0; // First process doesn't wait
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    // Display Table
    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    // Gantt Chart
    printf("\n--- Gantt Chart ---\n ");
    for (int i = 0; i < n; i++)
        printf("------- ");
    printf("\n|");
    for (int i = 0; i < n; i++)
        printf("  P%d  |", p[i].pid);
    printf("\n ");
    for (int i = 0; i < n; i++)
        printf("------- ");

    printf("\n0");
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        current_time += p[i].bt;
        printf("      %d", current_time);
    }

    printf("\n\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}