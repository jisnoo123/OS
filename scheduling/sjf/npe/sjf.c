#define MAX 100
#include <stdio.h>
#include <stdlib.h>

struct process{
    int id; // Process id    
    int at; // Arrival time
    int bt; // Burst time
};

struct process pro[MAX]; //Array of processes
struct process gc[MAX]; //Gantt chart

int n; //Number of processes
int te = 0; //Time elapsed . Initially it is 0

void input(){
    printf("Enter number of processes:");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter process id:");
        scanf("%d",&pro[i].id);

        printf("Enter Arrival time:");
        scanf("%d",&pro[i].at);

        printf("Enter Burst time:");
        scanf("%d",&pro[i].bt);
    }
}

void sort_at(){
    //Sort by arrival time
    for(int pass = 1; pass<n; pass++){
        for(int j=0; j<n-pass; j++){
            if(pro[j+1].at<pro[j].at){
                int t;
                printf("Where is it??");
                //Swap the id
                t = pro[j].id;
                pro[j].id = pro[j+1].id;
                pro[j+1].id = t;

                //Swap the arrival time
                t = pro[j].at;
                pro[j].at = pro[j+1].at;
                pro[j+1].at = t;

                //Swap the burst time
                t = pro[j].bt;
                pro[j].bt = pro[j+1].bt;
                pro[j+1].bt = t;
            }
        }
        
    }
}

void display(){
    for(int i=0; i<n; i++){
        printf("Process id: %d\n", pro[i].id);
        printf("Arrival time: %d\n", pro[i].at);
        printf("Burst time: %d\n", pro[i].bt);
        
    }
}

void sort_bt(int sti, int fii){
    //Sort by burst time
    int num = fii - sti + 1;

    for(int pass = 1; pass<num; pass++){
        for(int j=0; j<num-pass; j++){
            if(pro[j+1].bt<pro[j].bt){
                int t;

                //Swap the id
                t = pro[j].id;
                pro[j].id = pro[j+1].id;
                pro[j+1].id = t;

                //Swap the arrival time
                t = pro[j].at;
                pro[j].at = pro[j+1].at;
                pro[j+1].at = t;

                //Swap the burst time
                t = pro[j].bt;
                pro[j].bt = pro[j+1].bt;
                pro[j+1].bt = t;
            }
        }
    }
}

void sjf(){
    //Shortest job first

    //The job that has arrived first is the first to be executed

    gc[0].id = pro[0].id;
    gc[0].at = pro[0].at;
    gc[0].bt = pro[0].bt;
    int i = 0; //Record which index of the process array has been done 
    int ne = 1; //Number of executed jobs
    
    while(ne!=n){
        te = gc[i].at + gc[i].bt; //Time elapsed after the first job
        int st = i; //The starting index
        int fi = i; //The final index
        while(pro[fi].at < te){
            fi++;
        }
        sort_bt(st,fi);
        i = st;
        gc[i].id = pro[i].id;
        gc[i].at = pro[i].at;
        gc[i].bt = pro[i].bt;
        ne++;
    }
}

void gnatt_chart(){
    //Display the gnatt chart
    for(int i=0; i<n; i++){
        printf("Process id: %d ", gc[i].id);
        printf("Arrival time: %d ", gc[i].at);
        printf("Burst time: %d ", gc[i].bt); 
        printf("\n");
    }
}

int main(){
    input();
    printf("Initial\n");
    display();
    sort_at();
    printf("\nFinal\n");
    display();
    printf("HIIII");
    sjf();
    printf("Gnatt chart:\n");
    gnatt_chart();
}