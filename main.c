#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Função de ordenação que implementa
 * o selection sort
 */
void selectionSort(int v[], int n) {
    int i, j, min, aux;
    for(i = 0; i < (n - 1); i++) {
        min = i;
        for(j = (i + 1); j < n; j++){
            if(v[j] < v[min])
                min = j;
        }
        if(i != min) {
            aux = v[i];
            v[i] = v[min];
            v[min] = aux; 
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void saveExecutionTime(int n, double time) {
    FILE* f = fopen("exec_time.csv", "a");
    fprintf(f, "\n%d;%lf", n, time);
    fclose(f);
}

void readNumbers(const char* fileName, int v[]) {
    FILE* f = fopen(fileName, "r");
    if(f == NULL) {
        printf("arquivo nao pode ser aberto");
        return;
    }

    int n, idx = 0;
    fscanf(f, "%d", &n);    
    while(!feof(f)) {
        fscanf(f, "%d", &n);
        v[idx++] = n;
    }
    fclose(f);
}

int main(int argc, char** argv)
{   //     0            1               2
    // programa | nome arquivo | numero entradas
    int N = atoi(argv[2]);
    // vetor de numeros
    int v[N];
    readNumbers(argv[1], v);
    double time_spent = 0.0; 
    clock_t begin = clock();     
    // executando o algoritmo
    selectionSort(v, N);
    // fim execucao    
    clock_t end = clock();     
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    saveExecutionTime(N, time_spent);
    return 0;
}