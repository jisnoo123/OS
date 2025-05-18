//Least recently used page replacement algorithm
#define MAX 100
#include <stdio.h>

int n, f, a[MAX], c=0;
int fr[MAX][2];

void input(){
    printf("Enter number of frames:");
    scanf("%d",&f);
    printf("\nEnter number of elements in the sequence:");
    scanf("%d",&n);
    printf("\nKeep entering the sequence one by one:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("\nSequence input is done\n");
}

void init(){
    //Initialize the counter of the frames to 0 and the page to be -1 indicating free frame
    for(int i=0; i<f; i++){
        fr[i][0] = -1;
        fr[i][1] = 0;
    }
}

void display(){
    printf("\nYour sequence is:\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int search(int key){
    //Returns the position of key if key is already loaded in the frames otherwise return -1
    for(int i=0; i<f; i++){
        if(fr[i][0] == key){
            return i;
        }
    }
    return -1;
}

int find_min_count(){
    //Finds the page that is least recently used, that is having the minimum count
    int min = fr[0][1]; 
    int ind = 0;

    for(int i=1; i<f; i++){
        if(fr[i][1]<min){
            min = fr[i][1];
            ind = i;
        }
    }

    return ind; //Returns the index of the least recently used page
}

void display_frames(){
    //Displays the current state of the frames
    for(int i=0; i<f; i++){
        if(fr[i][0]!=-1){
            printf("%d\n", fr[i][0]);
        }
        else{
            printf("_\n");
        }
    }
    printf("\n");
}

void lru(){
    //Initialize
    init();

    printf("At first, all frames are free:\n");
    display_frames();
    //Now from the second element of the sequence to the last, allocate the pages
    for(int i=0; i<n; i++){
        printf("\nPage in sequence: %d\n", a[i]);
        if(search(a[i])==-1){
            //The page is not in the frames
            int ind = find_min_count();
            fr[ind][0] = a[i];
            fr[ind][1] = ++c;
            display_frames();
        }
        else{
            fr[search(a[i])][1] = ++c;
            printf("%d already allocated in frame\n", a[i]);
        }
    }
}

int main(){
    input();
    display();
    lru();
}