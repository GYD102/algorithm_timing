#include <stdio.h>

// Bubble-sort

int test[10] = {10, 9, 2, 3, 7, 5, 1, 6, 4, 8};

int testing_0(int t[], size_t arr_size){
    printf("Size of test array = %ld\n\n", arr_size);
    for(unsigned short i = 0; i < 12; i++){
        printf("Item at index %d is %d\n", i, t[i]);
        printf("Address of item %d is %p\n\n", i, &t[i]);
    }
    return 0;
}

int print_arr(int deck[]){
    size_t deck_size = 10;
    printf("[%d", deck[0]);
    for(int i = 1; i < deck_size; i++){
        printf(", %d", deck[i]);
    }
    printf("]\n");
    return 0;
}

int* bubble_sort(int deck[], size_t deck_size){
    int i, temp;
    int tot_swaps, swaps, compares = 0;
    while(swaps > 0){
        tot_swaps += swaps;
        swaps = 0;
        for(i = 1; i < deck_size; i++){
            if(deck[i-1] > deck[i]){
                // printf("Swapping index %d w/ %d, values %d and %d\n",
                //     i-1, i, deck[i-1], deck[i]);
                temp = deck[i-1];
                deck[i-1] = deck[i];
                deck[i] = temp;
                swaps += 1;
            }
            compares += 1;
        }
    }
    return deck;
}

int* selection_sort(int deck[], size_t deck_size){
    int i, j, temp, min_ind;
    int compares, swaps = 0;
    for(i = 0; i < deck_size-1; i++){
        min_ind = i;
        for(j = i+1; j < deck_size; j++){
            if(deck[j] < deck[min_ind])
                min_ind = j;
            compares++;
        }
        if(i != min_ind){
            // printf("Swapping index %d w/ %d, values %d and %d\n",
            //         i, min_ind, deck[i], deck[min_ind]);
            temp = deck[i];
            deck[i] = deck[min_ind];
            deck[min_ind] = temp;
            swaps++;
        }
    }
    return deck;
}

int* insertion_sort(int deck[], size_t deck_size){
    
}

int main(){
    // printf("Size of test array = %ld\n\n", sizeof(test));
    // testing_0(test, sizeof(test));
    print_arr(test);
    // print_arr(bubble_sort(test, 10));
    print_arr(selection_sort(test, 10));
    print_arr(test);
}