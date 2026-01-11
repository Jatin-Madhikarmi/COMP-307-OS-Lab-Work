#include <stdio.h>
#include <limits.h>

struct Process
{
    int pid;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int rt;  // Remaining Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
};

int main()
{
    int n, completed = 0, current_time = 0, min_val = INT_MAX;
    int shortest = 0, finish_time;
    int found = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival and burst time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt; // Initialize remaining time
    }

    printf("\nGantt Chart:\n|");

    while (completed != n)
    {
        min_val = INT_MAX;
        found = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].rt < min_val && p[i].rt > 0)
            {
                min_val = p[i].rt;
                shortest = i;
                found = 1;
            }
        }

        if (found == 0)
        {
            current_time++;
            continue;
        }

        // Simulating 1 unit of execution
        p[shortest].rt--;
        printf(" P%d |", p[shortest].pid);

        if (p[shortest].rt == 0)
        {
            completed++;
            finish_time = current_time + 1;
            p[shortest].ct = finish_time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
        current_time++;
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}