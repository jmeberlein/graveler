#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    setlocale(LC_NUMERIC, ""); // Enables a cool formatting trick, where I can add commas in printf
    srand(time(NULL));

    int MAX_TRIALS = 1000000000;
    int REQUIRED_ONES = 177;
    int ROLLS_PER_TRIAL = 231;

    int i, trials, ones, max_ones;

    for (trials = 0, max_ones = 0; trials < MAX_TRIALS && max_ones < REQUIRED_ONES; trials++) {
        for (i = 0, ones = 0; i < ROLLS_PER_TRIAL; i++) {
            if (!(rand() % 4)) {
                ones++;
            }
        }
        if (ones > max_ones) {
            max_ones = ones;
        }
    }
    
    printf("Most ones found:  %d\n", max_ones);
    printf("Number of trials: %'d\n", trials);

    return 0;
}