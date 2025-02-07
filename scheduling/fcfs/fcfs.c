#include <stdio.h>
#define MAX 100
int at[MAX], bt[100], nm[MAX],n; //Arrival time and burst time

void input(){
    for(int i=0;i<n;i++){
        nm[i] = i;
        printf("Enter arrival time of Process %d:",i);
        scanf("%d",&at[i]);
        printf("Enter burst time of Process %d:",i);
        scanf("%d",&bt[i]);
    }
}

void sort(){
    //Applying bubble sort
    for(int pass=1; pass<n; pass++){
        for(int j=0; j<n-pass; j++){
            if(at[j+1]<at[j]){
                int t;
                //Swap arrival times
                t = at[j];
                at[j]=at[j+1];
                at[j+1]= t;

                //Swap burst times
                t = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]= t;

                //Swap names
                t = nm[j];
                nm[j]=nm[j+1];
                nm[j+1]= t;
            }
        }
    }
}

void chart(){
    //Display a chart
    printf("Process id\tArrival time\tBurst time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t",nm[i]);
        printf("%d\t\t",at[i] );
        printf("%d\t\t\n",bt[i]);
    }
}

int main(){
    printf("Enter number of processes:");
    scanf("%d",&n);

    //Take the burst time and arrival time
    input();

    //Display the initial chart
    printf("Initial chart:\n");
    chart();

    //Sort according to arrival times
    sort();
    
    //Display the final chart
    printf("Scheduled chart:\n");
    chart();
}