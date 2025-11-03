//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {return -1;}
        int root = data[0];
        data[0] = data[size];
        downheap(0, weightArr);
        return root; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parPos = (pos - 1) / 2;
        while (weightArr[data[pos]] < weightArr[data[parPos]] || pos != 0) {
            int tmp = data[pos];
            data[pos] = data[parPos];
            data[parPos] = tmp;
            pos = parPos;
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child

        while () {
            int lChild = pos * 2 + 1;
            int rChild = pos * 2 + 2;
            int smallest = pos;

            if (lChild > 0 && weightArr[data[pos]] > weightArr[data[lChild]]) {
                smallest = data[lChild];
            }
            if (lChild > 0 && weightArr[data[pos]] > weightArr[data[rChild]]) {
                smallest = data[rChild];
            }

            if (smallest != pos) {
                int tmp = data[pos];
                data[pos] = smallest;
                smallest = tmp;
                pos = smallest;
            }

        }
    }
};

#endif