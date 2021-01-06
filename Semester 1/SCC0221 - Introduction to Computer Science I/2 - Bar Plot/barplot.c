#include<stdio.h>
#include<stdlib.h>

void bubblesort(int*, int);

int main(void){
    int q_bars, q_data, *data;
    scanf("%d %d", &q_bars, &q_data);
    data = (int*)malloc(q_data * sizeof(int));
    for(int i = 0; i < q_data; i++){
        scanf("%d", &data[i]);
    }
    bubblesort(data, q_data);
    int *count = (int*)calloc(q_bars, sizeof(int));

    for(int i = 0, j = 0; i < q_data-1; i++){
        if(data[i] == data[i+1])
            count[j]++;
        else
            j++;
    }
    for(int i = 0; i < q_bars; i++){
        printf("%d - ", i);
        for(int j = 0; j <= count[i]; j++)
            printf("#");
        printf("\n");
    }
    free(data);
    free(count);
    return 0;
}

void bubblesort(int *array, int size){
    int sort = 1;
    while(sort){
        sort = 0;
        for(int i = 0; i < size-1; i++){
            if(array[i] > array[i+1]){
                int copy = array[i];
                array[i] = array[i+1];
                array[i+1] = copy;
                sort = 1;
            }
        }
    }
}