#define MAX 10
#include <stdio.h>
int m,n;
int available[MAX], request[MAX], max[MAX][MAX], allocation[MAX][MAX], need[MAX][MAX];
int work[MAX], finish[MAX], seq[MAX];

void input(){
    printf("Enter no. of processes:");
    scanf("%d",&n);
    printf("Enter no. of resource types:");
    scanf("%d",&m);

    printf("Enter available:\n");
    for(int i=0 ; i<m; i++){
        printf("Resource %d No. of instances available:",i);
        scanf("%d",&available[i]);
    }

    printf("Enter max resources:\n");
    for(int i=0;i<n;i++){
        printf("For Process %d", i);
        printf("____________\n");
        for(int j=0; j<m; j++){
            printf("Resource %d No. of instances max:", j);
            scanf("%d",&max[i][j]);
        }
    }
}

void init(){
    /*Initialization*/
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //Allocation = 0 initially
            allocation[i][j]=0;
            //Assuming that need = max
            need[i][j]=max[i][j];
        }
    }
}

int need_work(int i){
    //Returns 1 if need_i<=work otherwise returns 0
    int flag=0;
    for(int j=0; j<m; j++){
        if(need[i][j]>work[j]){
            flag++;
            break;
        }
    }
    return !flag;
}

int check_finish(){
    //Returns 0 if all the processes are not finished yet otherwise return 1
    int flag=0;
    for(int i=0; i<n; i++){
        if(finish[i]==0){
            flag++;
            break;
        }
    }
    return !flag;
}

int safety(){
    printf("_____Safety Algorithm_____\n");
    /* Safety algorithm*/

    //Initialization
    //Initialize work[] = available[]
    for(int j=0; j<m; j++){
        work[j]=available[j];
    }
    //Initialize finish[i] = false for all the processes
    for(int i=0; i<n; i++){
        finish[i] = 0; //No process has terminated
    }
    //Initialize sequence
    for(int i=0; i<n; i++){
        seq[i] = -1;
    }

    int s=0;
    //Check for safe state
    while(check_finish()!=1){
        int c=0; //Counter to check if no processes are found having the two conditions
        for(int i=0; i<n; i++){
            if(finish[i]==0 && need_work(i)==1){
                printf("Found Process %d\n",i);
                c++;
                //Allocate needs by updating work
                for(int j=0; j<m; j++){
                    work[j]+=allocation[i][j];
                }
                finish[i]=1;
                //Record the safe sequence in which work is being allocated
                seq[s]=i;
                s++;
            }
        }

        if(c==0){
            break;
        }
    }

    return check_finish(); //Returns 1 if safe state otherwise returns 0
}

void undo_safety(){
    //Undo safety 
    for(int i=0; i<n; i++){
        if(finish[i]==1){
            for(int j=0; j<m; j++){
                work[j]-=allocation[i][j];
            }
        }
    }
}


int req_need(int i){
    /*Compares request with need. 
    Returns 1 if request_i<=need[i][] otherwise returns 0
    */
    int flag=0;
    for(int j=0; j<m; j++){
        if(request[j]>need[i][j]){
            flag++;
            break;
        }
    }
    return !flag;
}

int req_available(){
    /*Compares request with available. 
    Returns 1 if request_i<=available[i][] otherwise returns 0
    */
    int flag=0;
    for(int j=0; j<m; j++){
        if(request[j]>available[j]){
            flag++;
            break;
        }
    }
    return !flag;
}

void resource_request(int i){
    /*Resource request algorithm*/
    if(req_need(i)==1){
        if(req_available()==1){
            //Modify the states
            for(int j=0; j<m; j++){
                available[j]-=request[j];
                allocation[i][j]+=request[j];
                need[i][j]-=request[j];
            }
        }
        else{
            printf("\nProcess %d Resources unavailable\n",i);
        }
    }
    else{
        printf("\nProcess %d Request exceeds need\n",i);
    }
}

void undo_resource_request(int i){
    //Undo resource request
    for(int j=0; j<m; j++){
        available[j]+=request[j];
        allocation[i][j]-=request[j];
        need[i][j]+=request[j];
    }
}

void display(){
    //Display all necessary details
    for(int i=0; i<n; i++){
        printf("Process %d___\n",i);

        printf("\nResources allocated:\n");
        for(int j=0; j<m; j++){
            printf("Resource %d Allocated:%d \n",j,allocation[i][j]);
        }
        printf("\nResources need:\n");
        for(int j=0; j<m; j++){
            printf("Resource %d Need:%d \n",j,need[i][j]);
        }
        printf("\nResources max:\n");
        for(int j=0; j<m; j++){
            printf("Resource %d Max:%d \n",j,max[i][j]);
        }
    }

    printf("Resources available:\n");
    for(int j=0; j<m; j++){
        printf("Resource %d Available: %d\n", j,available[j]);
    }
}

void computation(){
    int ch,pid;
    do{
        printf("Enter 1 for request or 2 to end:");
        scanf("%d",&ch);
        if(ch==1){
            //Request
            printf("Enter the process number that requests:");
            scanf("%d",&pid);
            //Take the number of resources requested for each resource type
            printf("For process %d ____\n", pid);
            for(int j=0; j<m; j++){
                printf("Enter request of resource %d: ",j);
                scanf("%d",&request[j]);
                printf("\n");
            }

            //Check allocation with resource allocation
            resource_request(pid);
            printf("After resource request__\n");
            display();

            if(safety()==1){
                //Safe state
                printf("System is in a safe state\n");
                printf("Safe sequence is:\n");
                for(int i=0; i<n; i++){
                    printf("%d ", seq[i]);
                }
            }
            else{
                //Unsafe state
                printf("System is in an unsafe state\n");
                //Undo resource request
                undo_safety();
                //Undo safety
                undo_resource_request(pid);
            }
        }
    }
    while(ch!=2);
}

int main(){
    input();
    printf("Initial Details:\n");
    display();
    init();
    computation();
    printf("Final Details:");
    display();
}