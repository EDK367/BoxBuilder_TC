#ifndef NODOINFO_H
#define NODOINFO_H

class NodoInfo
{
private:
    bool isConnectedUp;
    bool isConnectedDown;
    bool isConnectedLeft;
    bool isConnectedRight;

public:
    NodoInfo();
    ~NodoInfo() = default;


    // getter y setter
    bool getIsConnectedUp() const;
    bool getIsConnectedDown() const;
    bool getIsConnectedLeft() const;
    bool getIsConnectedRight() const;

    void setIsConnectedUp(bool value);
    void setIsConnectedDown(bool value);
    void setIsConnectedLeft(bool value);
    void setIsConnectedRight(bool value);

};

#endif // NODOINFO_H
