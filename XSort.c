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

typedef struct record rec;

int main();

struct record *readLine(char path[], int spesificLine, int size);

void heapSort(struct record* arr[], int size);

void heapify(struct record* arr[], int n, int i);

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
  
    //printf(readLine("students.csv", 1, k).name);
    //replacementselectionSort("students.csv", "output.csv", k, 4);
    struct record* arr[5];
    for(int i = 0; i<6;i++){
      arr[i] = readLine("students.csv", i+1, k);
    }
    printf("%d \n", sizeof(arr));
    heapSort(arr,(sizeof arr/sizeof arr[0])+1);
    int a = sizeof arr/sizeof arr[0];
    
    printf("%d\n",arr[0]->id);
    printf("%d\n",arr[1]->id);
    printf("%d\n",arr[2]->id);
    printf("%d\n",arr[3]->id);
    printf("%d\n",arr[4]->id);
    printf("%d\n",arr[5]->id);

    struct record* deneme =readLine("students.csv", 5, k);
    printf(deneme->name);
    printf("basarili");
}

/*
void replacementselectionSort(char path[], char outpath[], int pageSize, int bufferCount)
{
    struct record record;
    int recordSize;
    int recordCount = pageSize/recordSize;
    struct record heap[4];
    FILE* stream;
    stream = fopen(path, "r");
    struct record in[recordCount];
    struct record out[recordCount * sizeof(record)];
    heapSort(recordCount,in);
    struct record list[recordCount];
    int lastEject;
    int i = 0;
    int j = 0;
    int k = 0;
    int c = 4;
    while(i != pageSize){
        while(!heapEmpty(heap)){

            struct record rec = heap[(sizeof(heap)/sizeof(heap[0]) - 1)];
            lastEject = rec.id;
            out[i] = rec;
            
            struct record newRec = *readLine(path, c, pageSize);
            c++;
            if(newRec.id<lastEject){
                list[j] = newRec;
                j++;
            }
            else{
                heap[sizeof(heap)/sizeof(heap[0]) - 1] = newRec;
            }
        }
        free(heap);
        FILE *fpt = fopen(outpath,"w+");
        fprintf(fpt, out);
        fclose(fpt);
        free(fpt);
        i++;
    }
    
}
*/
struct record* temp;  
  
void heapify(struct record* arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left]->id >arr[largest]->id)  
largest = left;  
  
if (right < size && arr[right]->id > arr[largest]->id)  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heapSort(struct record* arr[], int size) {  

for (int i = size / 2 - 1; i >= 0; i--)  {
  heapify(arr, size, i);  
}
for (int i=size-1; i>=0; i--)  
{  
    temp = arr[0];  
    arr[0]= arr[i];   
    arr[i]= temp;  
    heapify(arr, i, 0);  
}  
}  
    
  struct record* readLine(char path[], int spesificLine, int size){
    struct record* record = calloc(51, sizeof(struct record));
    FILE *stream = fopen(path, "r");
    
    char line[size];
    int count = 0;
    while(fgets(line, size, stream)){
      if(count==spesificLine){
        char* tmp = strdup(line);
        char* tmp2 = strdup(line);
        char* tmp3 = strdup(line);
        char* tmp4 = strdup(line); 
        char* tmp5 = strdup(line);       
        record->id =  atoi(getfield(tmp,1));
        record->grade =  atoi(getfield(tmp5, 5));
        strcpy(record->name, getfield(tmp2, 2));
        strcpy(record->email, getfield(tmp4, 4));
        strcpy(record->surname, getfield(tmp3, 3));
        free(tmp);
        free(tmp2);
        free(tmp3);
        free(tmp4);
        free(tmp5);
        break;
      }
      count++;
    }
    return record;
  }
  
  
