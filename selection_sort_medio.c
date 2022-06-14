#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selection_sort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void saveExecutionTime(int n, double time, const char* identifier) {
    char buff[255];
    sprintf(buff, "execution_time_%s.csv", identifier);
    FILE* f = fopen(buff, "a");
    fprintf(f, "%d;%lf\n", n, time);
    fclose(f);
}

void loadArray(const char* fileName, int v[], int n) {
    FILE* f = fopen(fileName, "r");
    int num, index = 0;
    fscanf(f, "%d", &num);
    while (!feof(f))
    {
        v[index++] = num;
        fscanf(f, "%d", &num);
    }  
    v[index] = num;  
}

void printArr(int v[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int main(int argc, char** argv) {
    // primeiro elemento -> nome do programa
    int n = atoi(argv[2]);
    char* fileName = argv[1];
    int v[n];
    loadArray(fileName, v, n);

    clock_t begin = clock();
    selection_sort(v, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;    
    saveExecutionTime(n, time_spent, argv[3]);

    return 0;
}
