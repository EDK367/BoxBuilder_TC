#include "controllervector.h"
#include "../../models/controller/controllerBL.h"

template <typename T>
ControllerVector<T>::ControllerVector() : array(nullptr), size(0)
{}

template <typename T>
ControllerVector<T>::~ControllerVector() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}

template <typename T>
void ControllerVector<T>::push(T *newElement)
{
    size++;
    T **newArray = new T*[size];
    for (int i = 0; i < size; ++i)
    {
        if (array) {
            newArray[i] = array[i];
        }
    }
    newArray[size - 1] = newElement;

    delete[] array;
    array = newArray;
}

template <typename T>
void ControllerVector<T>::pop(int index)
{
    if (index < 0 || index >= size) return;

    delete array[index];

    if (size == 1) {
        delete[] array;
        array = nullptr;
    } else {
        T** newArray = new T*[size - 1];
        int j = 0;
        for (int i = 0; i < size; ++i) {
            if (i != index) {
                newArray[j++] = array[i];
            }
        }
        delete[] array;
        array = newArray;
    }
    size--;
}


template <typename T>
T *ControllerVector<T>::getElement(int index) const
{
    if (index < 0)
    {
        return nullptr;
    }
    return array[index];
}

template <typename T>
int ControllerVector<T>::getSize() const
{
    return size;
}

template class ControllerVector<ControllerBL>;
