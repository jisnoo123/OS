#define MAX 10
#include <stdio.h>
int m,n;
int available[MAX], request[MAX], max[MAX][MAX], allocation[MAX][MAX], need[MAX][MAX];
int work[MAX], finish[MAX], seq[MAX], s=0;

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
            printf("Resource %d No. of instances need:", j);
            scanf("%d",&max[i][j]);
        }
    }
}

void init(){
    /*Initialization*/
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
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

void safety(){
    /* Safety algorithm*/

    //Initialization
    //Initialize work[] = available[]
    for(int i=0; i<m; i++){
        work[i]=available[i];
    }
    //Initialize finish[i] = false for all i
    for(int i=0; i<n; i++){
        finish[i] = 0; //No process has terminated
    }

    //Check for safe state
    
    while(check_finish()!=1){
        int c=0; //Counter to check if no processes are found having the two conditions
        for(int i=0; i<n; i++){
            if(finish[i]==0 && need_work(i)==1){
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

    if(check_finish()==1){
        printf("\nThe system is in a safe state\n");
        printf("Safe sequence is: ");
        for(int i=0; i<n; i++){
            printf("%d ", seq[i]);
        }
    }
    else{
        printf("\nSystem is in an unsafe state\n");
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
        }
    }
    return !flag;
}

int req_available(int i){
    /*Compares request with available. 
    Returns 1 if request_i<=available[i][] otherwise returns 0
    */
    int flag=0;
    for(int j=0; j<m; j++){
        if(request[j]>available[j]){
            flag++;
        }
    }
    return !flag;
}

void resource_request(int i){
    /*Resource request algorithm*/
    if(req_need(i)==1){
        if(req_available(i)==1){
            //Modify the states
            for(int j=0; j<m; j++){
                available[j]+=request[j];
                allocation[i][j]+=request[j];
                need[i][j]-=request[j];
            }
        }
        else{
            printf("Process %d Resources unavailable\n",i);
        }
    }
    else{
        printf("Process %d Request exceeds need\n",i);
    }
}
    
void display_allocation(){
    //Display the allocation
    for(int i=0; i<n; i++){
        printf("Process %d Resources allocated____\n",i);
        for(int j=0; j<m; j++){
            printf("Resource %d Allocated:%d ",j,allocation[i][j]);
        }
        printf("\n");
    }
}

void allocate(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //Process i requesting
            request[j] = need[i][j];
        }
        //Check if can be granted or process needs to wait
        resource_request(i);
    }
    //Check if system can be in a safe state
    safety(); 
}

int main(){
    input();
    init();
    allocate();
    printf("\nFinally the allocation is:");
    display_allocation();
}