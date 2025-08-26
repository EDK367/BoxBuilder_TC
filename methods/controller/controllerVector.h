#ifndef CONTROLLERVECTOR_H
#define CONTROLLERVECTOR_H

template <typename T>
class ControllerVector
{
private:
    T **array;
    int size;

public:
    ControllerVector();
    ~ControllerVector();

    void push(T *newElement);
    void pop(int index);
    void sortByStart();

    T *getElement(int index) const;
    void clear();
    int getSize() const;
};

#endif // CONTROLLERVECTOR_H
