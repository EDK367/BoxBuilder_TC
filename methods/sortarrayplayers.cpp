#include "sortarrayplayers.h"

SortArrayPlayers::SortArrayPlayers() {}

// ordenar el arreglo a base de MergeSort
void SortArrayPlayers::mergeSortPlayers(Players playersArray[], int start, int end, int typeSort)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;

        // recursividad
        mergeSortPlayers(playersArray, start, middle, typeSort);
        mergeSortPlayers(playersArray, middle + 1, end, typeSort);

        // unir
        merge(playersArray, start, middle, end, typeSort);
    }
}

// ordenamiento recursivo
void SortArrayPlayers::merge(Players playersArray[], int start, int middle, int end, int typeSort)
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
        if (typeSort == 1)
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

        if (typeSort == 2)
        {
            if (leftArray[i].getTotalBox() >= rightArray[j].getTotalBox())
            {
                playersArray[k] = leftArray[i];
                i++;
            } else {
                playersArray[k] = rightArray[j];
                j++;
            }
            k++;
        }

        if (typeSort == 3)
        {
            if (leftArray[i].getTotalBoxRow() >= rightArray[j].getTotalBoxRow())
            {
                playersArray[k] = leftArray[i];
                i++;
            } else {
                playersArray[k] = rightArray[j];
                j++;
            }
            k++;
        }
        if (typeSort == 4)
        {
            if (leftArray[i].getTotalBoxColumn() >= rightArray[j].getTotalBoxColumn())
            {
                playersArray[k] = leftArray[i];
                i++;
            } else {
                playersArray[k] = rightArray[j];
                j++;
            }
            k++;
        }
        if (typeSort == 5)
        {
            if (leftArray[i].getTotalPowers() >= rightArray[j].getTotalPowers())
            {
                playersArray[k] = leftArray[i];
                i++;
            } else {
                playersArray[k] = rightArray[j];
                j++;
            }
            k++;
        }

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
