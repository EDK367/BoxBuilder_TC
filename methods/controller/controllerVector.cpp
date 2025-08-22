#include "controllervector.h"
#include "../../models/controller/controllerBL.h"

template <typename T>
ControllerVector<T>::ControllerVector() : array(nullptr), size(0) {}

template <typename T>
ControllerVector<T>::~ControllerVector() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;
}

template <typename T>
void ControllerVector<T>::push(T* newElement) {
    T** newArray = new T*[size + 1];

    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }

    newArray[size] = newElement;

    delete[] array;

    array = newArray;
    size++;
}

template <typename T>
void ControllerVector<T>::pop(int index) {
    if (index < 0 || index >= size)
    {
        return;
    }
    delete array[index];

    if (size == 1) {
        delete[] array;
        array = nullptr;
        size = 0;
        return;
    }

    T** newArray = new T*[size - 1];
    int j = 0;

    for (int i = 0; i < size; ++i) {
        if (i != index) {
            newArray[j++] = array[i];
        }
    }

    delete[] array;
    array = newArray;
    size--;
}

template <typename T>
T* ControllerVector<T>::getElement(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return array[index];
}

template <typename T>
int ControllerVector<T>::getSize() const {
    return size;
}

// uso de clase
template class ControllerVector<ControllerBL>;
