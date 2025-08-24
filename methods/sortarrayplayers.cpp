#include "sortarrayplayers.h"

SortArrayPlayers::SortArrayPlayers() {}

// ordenar el arreglo a base de MergeSort
void SortArrayPlayers::mergeSortPlayers(Players playersArray[], int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;

        // recursividad
        mergeSortPlayers(playersArray, start, middle);
        mergeSortPlayers(playersArray, middle + 1, end);

        // unir
        merge(playersArray, start, middle, end);
    }
}

// ordenamiento recursivo
void SortArrayPlayers::merge(Players playersArray[], int start, int middle, int end)
{
    // ciclos
    int i, j, k;
    int leftSize = middle - start + 1;
    int rightSize = end - middle;

    Players *leftArray = new Players[leftSize];
    Players *rightArray = new Players[rightSize];

    // copiar arreglos
    for (int i = 0; i < leftSize; ++i)
    {
        leftArray[i] = playersArray[start + i];
    }

    for (int j = 0; j < rightSize; ++j)
    {
        rightArray[j] = playersArray[middle + 1 + j];
    }

    i = 0, j = 0, k = start;

    // mezclar
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i].getPoints() >= rightArray[j].getPoints())
        {
            playersArray[k] = leftArray[i];
            i++;
        } else {
            playersArray[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // complementar
    while(i < leftSize)
    {
        playersArray[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < rightSize)
    {
        playersArray[k] = rightArray[j];
        j++;
        k++;
    }

    // liberacion de memoria
    delete[] leftArray;
    delete[] rightArray;
}
