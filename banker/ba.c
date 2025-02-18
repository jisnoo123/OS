#include <stdio.h>
#define MAX 100
int n,m;
int max[MAX][MAX], available[MAX], allocation[MAX][MAX], need[MAX][MAX], work[MAX], finish[MAX], request[MAX];
int ss[MAX], s=0;

void input(){
    //Takes the necessary details
    printf("Enter no. of processes:");
    scanf("%d",&n);
    printf("\nEnter no. of resources:");
    scanf("%d",&m);

    printf("\nEnter available instances of resources:");
    for(int i=0; i<m; i++){
        printf("\nEnter available instances of resource %d :",i);
        scanf("%d",&available[i]);
    }

    printf("\nEnter max instances of resources:");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("\nEnter max instances of resource %d for process %d:",j,i);
            scanf("%d",&max[i][j]);
        }
    }
}

void init(){
    //Initialization

    //Allocation = 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            allocation[i][j] = 0;
        }
    }

    //Need = Max
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j];
        }
    }
}

int check_need(int row){
    //Returns 1 if need[row] <= work
    int flag = 0;
    for(int i = 0; i<m; i++){
        if(need[row][i]>work[i]){
            flag++;
            break;
        }
    }
    
    return !flag;
}

void update_work(int pno){
    //Update work
    for(int i=0; i<m; i++){
        work[i] = work[i] + allocation[pno][i];
    }
}

int check_finish(){
    //Returns 1 if all are completed
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
    //The safety algorithm

    //Work = available
    for(int i=0; i<m; i++){
        work[i] = available[i];
    }

    //Finish = false 
    for(int i=0; i<n; i++){
        finish[i] = 0;
    }

    while(check_finish()!=1){
        int found = 0;
        for(int i=0; i<n; i++){
            if(finish[i]==0 && check_need(i)==1){
                found = 1;
                update_work(i);
                finish[i] = 1;
                ss[s]=i;
                s++;
            }
        }

        if(found == 0){
            break;
        }
    }

    if(check_finish()==1){
        printf("Safe sequence exists\n");
        printf("Safe sequence:");
        for(int i=0; i<s; i++){
            printf("%d ", ss[i]);
        }
    }
    else{
        printf("Safe sequence doesn't exist\n");
    }
}

int check_req_need(int pno){
    //Returns 1 if Request_i <= Need[i]
    int flag=0;
    for(int i=0; i<m; i++){
        if(request[i] > need[pno][i]){
            flag++;
            break;
        }
    }
    
    return !flag;
}

void allocate(int pno){
    //Allocation[i] = Allocation[i] + Request_i
    for(int i=0;i<m;i++){
        allocation[pno][i] = allocation[pno][i] + request[i];
    }
}

int check_req_available(int pno){
    //Returns 1 if Request_i <= Available
    int flag=0;
    for(int i=0; i<m; i++){
        if(request[i]>available[i]){
            flag++;
            break;
        }
    }
    
    return !flag;
}

void resource_allocation(int pno){
    //Resource allocation algorithm
    if(check_req_need(pno)==1){
        if(check_req_available(pno)==1){
            allocate(pno);
        }
        else{
            printf("Resources not available\n");
        }
    }
    else{
        printf("Invalid request\n");
    }
}

void fill(){
    //Fill request with need for each proccess
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            request[j] = need[i][j];
        }
        resource_allocation(i);
    }
    //Check safe sequence exists or not
    safety();
}
int main(){
    input();
    init();
    fill();
}