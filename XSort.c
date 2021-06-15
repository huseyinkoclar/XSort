#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct record
{
int id;
int grade;
char name[15];
char surname[15];
char email[28];
};

struct header
{
int id;
int grade;
char name[15];
char surname[15];
char email[26];
};

int main();

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    struct record record;
    FILE* stream;
    stream = fopen("students.csv", "r");

    int k=0;
    char ch;
    while(!feof(stream)){
        ch=getc(stream);
        if(ch=='\n'){
            k++;
        }
    }
    printf("satir = %d\n",k+1);
    stream = fopen("students.csv", "r");
    
    char line[k];
    int count = 0;
    while(fgets(line, k, stream)){
        char* tmp = strdup(line);
        char* tmp2 = strdup(line);
        char* tmp3 = strdup(line);
        char* tmp4 = strdup(line); 
        char* tmp5 = strdup(line);       
        record.id =  atoi(getfield(tmp,1));
        record.grade =  atoi(getfield(tmp5, 5));
        strcpy(record.name, getfield(tmp2, 2));
        strcpy(record.email, getfield(tmp4, 4));
        strcpy(record.surname, getfield(tmp3, 3));
        
        count++;
        free(tmp);
        free(tmp2);
        free(tmp3);
        free(tmp4);
        free(tmp5);
    }
    printf("%d   ",record.id);
    printf(record.name);
    printf("  ");
    printf(record.surname);
    printf("   ");
    printf(record.email);
    printf("   ");
    printf("%d", record.grade);
    
}

void replacementselectionSort(char path[], char path2[], char outpath[], int pageSize, int bufferCount)
{
    struct record record;
    int recordSize;
    int recordCount = pageSize/recordSize;
    
    FILE* stream;
    stream = fopen(path, "r");
    struct record in[recordCount];
    bool endOfFile = ReadLines(path, recordCount);
    struct record out[recordCount * sizeof(record)];
    heapSort(recordCount,in);
    struct record list[recordCount];
    int lastEject;
    int i = 0;
    int j = 0;
    int k = 0;

    
    while(i != pageSize){
        while(!heapEmpty(heap)){

            struct record rec = heap.pop();
            lastEject = rec.id;
            out[i] = rec;

            struct record newRec = readLines(stream,1);

            if(newRec.id<lastEject){
                list[j] = newRec;
                j++;
            }
            else{
                heap.push(newRec);
            }
        }
        free(heap);
        heap = createHeap(recordCount, list);
        FILE *fpt = fopen(path2,"w+");
        fprintf(fpt, out);
        fclose(fpt);
        free(fpt);
        i++;
    }
    
}


 // Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  } 
