#include <stdio.h>

struct Process
{
    int pid, at, bt, rt, ct, tat, wt;
};

int main()
{
    int n, tq, current_time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int queue[100], front = 0, rear = 0;
    int visited[100] = {0};

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival and burst time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Initial push: find process arriving at time 0
    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= current_time)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    printf("\nGantt Chart:\n|");
    while (completed != n)
    {
        if (front == rear)
        { // No process in queue
            current_time++;
            for (int i = 0; i < n; i++)
            {
                if (p[i].at <= current_time && !visited[i])
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];
        printf(" P%d |", p[i].pid);

        if (p[i].rt > tq)
        {
            p[i].rt -= tq;
            current_time += tq;
        }
        else
        {
            current_time += p[i].rt;
            p[i].rt = 0;
            completed++;
            p[i].ct = current_time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }

        // Add newly arrived processes to queue
        for (int j = 0; j < n; j++)
        {
            if (p[j].at <= current_time && !visited[j])
            {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // If current process not finished, put it back in queue
        if (p[i].rt > 0)
        {
            queue[rear++] = i;
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    return 0;
}