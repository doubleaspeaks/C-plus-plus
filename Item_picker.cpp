// Exercise 05.04.01.txt
// This program draws one of eight balls, using
//  code similar to dealer2.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int rand_0toN1(int n);
void draw_an_item();
int select_next_available(int n);

char *colors[4] =  {"red", "blue", "orange", "green"};
char *shapes[2] = {"ball", "cube" };

int item_drawn[8];
int items_remaining = 8;

int main() {
    int n, i;

    srand(time(NULL));      // Set seed for random numbers.

    while (1) {
        cout << "Enter no. of items to draw (0 to exit): ";
        cin >> n;
        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
            draw_an_item();
    }
    return 0;
}

// Draw-an-item function
// Performs one item-pick by getting a random 0-4 and a random
//  0-1. These are then used to index the string arrays, colors
//  and shapes
//
void draw_an_item() {
    int c;         // Random index (0 thru 4) into colors array
    int s;         // Random index (0 thru 1) into shapes array
    int n, item;

    n = rand_0toN1(items_remaining--);
    item = select_next_available(n);

    c = item % 4;            // c = random 0 to 3
    s = item / 4;            // s = random 0 to 1
    cout << colors[c] << " " << shapes[s] << endl;
}

// Select-next-available-item function.
// Find the Nth element of item_drawn, skipping over all those
//  elements already set to true.
//
int select_next_available(int n) {
    int i = 0;

    // At beginning of draw, skip past items already drawn.

    while (item_drawn[i])
        i++;

    while (n-- > 0) {     // Do the following n times:
        i++;                       // Advance to next card
        while (item_drawn[i])      // Skip past cards
            i++;                   //  already drawn.
    }
    item_drawn[i] = true;        // Note item drawn
    return i;                    // Return this number.
}


// Random 0-to-N1 Function.
// Generate a random integer from 0 to N-1.
//
int rand_0toN1(int n) {
    return rand() % n;
}
