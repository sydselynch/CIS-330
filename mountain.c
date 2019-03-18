#include <stdio.h>
#include "mountain.h"
#include <stdio.h>
#include <stdlib.h>


void printNumberMountain(const int numPeaks, int *heights , int ***triangles) {
    int i, j, h, wOffset, vOffset;
    int max = 0;
    int cols = 0;
    int count = 0;

    // Find the maximum height
    for (i = 0; i < numPeaks; i++) {
        cols += (heights[i]*2) - 1;
        if (max < heights[i]) {
            max = heights[i];
        }
    }

    // Allocate memory for array
    *triangles = malloc(max * sizeof(int *));
    for (i = 0; i < max; i++) {
        (*triangles)[i] = (int *)malloc(cols * sizeof(int));
    }


    // Initialize array
    wOffset = 0;
    for (i = 0; i < max; i++) {
        for (j = 0; j < cols; j++) {
            (*triangles)[i][j] = -1;
        }
    }
    for (h = 0; h < numPeaks; h++) {
        
        vOffset = max - heights[h];
        for (i = 0; i < heights[h]; i++) {
            for (j = heights[h] - 1 - i; j < heights[h] + i; j++) {
                (*triangles)[i+vOffset][j+wOffset] = count;
                count++;
            }

            count = 0;
        }

        wOffset += heights[h] * 2 - 1;
    }

    // Print array
    for (i=0; i < max; i++) {
        for (j=0; j < cols; j++) {
            if ((*triangles)[i][j] == -1) {
                printf("  ");
            }
            else {
                printf("%d ", (*triangles)[i][j]);
            }
        }
        printf("\n");
    }

}

int main() {
    int **triangle;
    int *heights;
    int heightInput;
    int valid = 0;
    int numPeaks;
    char non_int;
    int i;

    while (valid == 0) {
        printf("Please enter the number of peaks [1-5]: ");
        if (scanf("%d", &numPeaks) == 0) {
            scanf("%s", &non_int);
            printf("The number of peaks must be an integer [1-5].\n");
            printf("\n");
        }

        else if (numPeaks < 1 || numPeaks > 5) {
            printf("The number of peaks must be between 1 and 5 (inclusive).\n");
            printf("\n");
        }

        else {
            printf("Enter the heights of the peaks (each should be between 1 and 5): ");
            heights = (int *) malloc (numPeaks * sizeof(int));

            for (i = 0; i < numPeaks; i++) {
                if (scanf("%d", &heightInput) == 1 && (heightInput >= 1 && heightInput <= 5)) {
                    heights[i] = heightInput;
                }
                else {
                    printf("The heights must be between 1 and 5 (inclusive).\n");
                    i--;
                }
            }
            valid = 1;
        }

        //printf("%d", numPeaks);
        //printf("%d %d %d", heights[0], heights[1], heights[2]);

        //printf("%d", max);
    }    





    printNumberMountain((const int)numPeaks, heights, &triangle);

}