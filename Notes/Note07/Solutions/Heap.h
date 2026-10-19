#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

namespace aan 
{
    /*
    + A heap is a comparable rooted complete binary tree.
    + A rooted tree is a tree with a distinct vertex called the root that is 
    start or head of the tree.
    + The branch nodes of a node X are the children of X. And node X is the parent of 
    each branch node.
    + Nodes with the same the parent are called siblings.
    + The root has no parent.
    + The descendants of a node X is its children and its children's descendants.
    + The ancestors of a node X is its parent and its parent's ancestors.
    + A node with no children is an external node (or a leaf).
    + A nonleaf node is called an internal node.
    + The degree of a node X is equal to the number of its children.
    + The depth of a node X is equal to the number of its ancestors.
    + The depth of the tree is equal to the maximum depth of its leaves.
    + The level of a node X is its depth.
    + A binary tree is a rooted tree such that each node has at most 2 children
    + A full tree is binary tree such that each node either has 0 or 2 children
    + A complete tree is a binary tree that is only missing 0 or more of its rightmost leaves
    + Max-Heap: For every node X, Data(X) <= Data(Parent(X))
    + Min-Heap: For every node X, Data(X) >= Data(Parent(X))

                        A
                B               C
            D       E      F         G     

        [A,B,C,D,E,F,G]
         0 1 2 3 4 5 6

         Parent(i) = (i - 1) / 2
         Left(i) = 2i + 1
         Right(i) = 2i + 2
    */

    template <template T>
    void MaxHeapify(std::vector<T>& A, int idx, int heapSize)
    {
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int largest = idx;

        if(l < heapSize && A[l] > A[largest])
        {
            largest = l;
        }

        if(r < heapSize && A[r] > A[largest])
        {
            largest = r;
        }

        if(largest != idx)
        {
            T t = A[idx];
            A[idx] = A[largest];
            A[largest] = t;
            MaxHeapify(A,largest,heapSize);
        }
    }

    /*
    A = [50,13,24,41,17,21]

                    50
            41              24
        13      17      21

    idx = 1, heapSize = 6
    1. l = 3, r = 4, largest = 1
    2. largest = 3
    3. A = [50,41,24,13,17,21]
    4. idx = 3, l = 7, r = 8, largest = 3
    */

    template <typename T>
    void BuildMaxHeap(std::vector<T>& A, int heapSize)
    {
        int i = heapSize / 2;

        while(i >= 0)
        {
            MaxHeapify(A,i,heapSize);
            i -= 1;
        }
    }

    /*
    A = [2,10,5,12,8,15], heapSize = 6

    1. i = 3
    2. A = [2,10,5,12,8,15], i = 2
    3. A = [2,10,15,12,8,5], i = 1
    4. A = [2,12,15,10,8,5], i = 0
    5. A = [15,12,2,10,8,5]
    6. A = [15,12,5,10,8,2], i = -1

                    15
            12              5
        10      8      2
    */

}

#endif