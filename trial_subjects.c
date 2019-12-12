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

int testing_1(){
    short s[5];
    int t[5];
    long u[5];
    printf("short[] s: %p\ns + 1: %p\n\n", s, s+1);
    printf("int[] t: %p\nt + 1: %p\n\n", t, t+1);
    printf("long[] u: %p\nu + 1: %p\n\n", u, u+1);
    return 0;
}

int print_arr(int deck[], int deck_size){
    // size_t deck_size = 10;
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
    int i, j, k, temp;
    for(i = 1; i < deck_size; i++){
        for(j = 0; j < i; j++){
            if(deck[i] < deck[j]){
                temp = deck[j];
                deck[j] = deck[i];
                deck[i] = temp;
                for(k = j+1; k < i; k++){
                    temp = deck[k];
                    deck[k] = deck[i];
                    deck[i] = temp;
                }
            }
        }
    }
    return deck;
}

int* merge_sort(int* deck, size_t deck_size){
    if(deck_size < 2) return deck;
    merge_sort(deck, deck_size / 2);
    merge_sort(deck + deck_size / 2, deck_size - deck_size / 2);
    int sorted_deck[deck_size];
    int deck_size_0 = deck_size / 2;
    int j = deck_size_0;
    int i = 0, k = 0;
    while(i < deck_size_0 && j < deck_size){
        sorted_deck[k] = deck[i];
        if(deck[j] < deck[i]){
            sorted_deck[k] = deck[j];
            j++;
        }
        else i++;
        k++;
    }
    if(i == deck_size_0){
        while(j < deck_size){
            sorted_deck[k] = deck[j];
            j++;
            k++;
        }
    }
    else{
        while(i < deck_size_0){
            sorted_deck[k] = deck[i];
            i++;
            k++;
        }
    }
    for(i = 0; i < deck_size; i++)
        deck[i] = sorted_deck[i];
    return deck;
}

int* quick_sort(int deck[], size_t deck_size){
    
    return deck;
}

int main(){
    // printf("Size of test array = %ld\n\n", sizeof(test));
    // testing_0(test, sizeof(test));
    // testing_1();
    print_arr(test, 10);
    // print_arr(bubble_sort(test, 10), 10);
    // print_arr(selection_sort(test, 10), 10);
    // print_arr(insertion_sort(test, 10), 10);
    print_arr(merge_sort(test, 10), 10);
    print_arr(test, 10);
}