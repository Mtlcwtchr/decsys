//
// Created by aliqu on 7/22/2024.
//

#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H
#include <_mingw.h>

enum ECharacteristic {

};

class Characteristic {

private:
    ECharacteristic type;
    float value;

public:
    Characteristic(ECharacteristic _type, float _baseValue);

    void Append(Characteristic* _characteristic);

    __forceinline float Get() const { return value; }
    __forceinline void Set(const float _value) { value += _value; }

    __forceinline ECharacteristic GetType() const { return type; }
};



#endif //CHARACTERISTIC_H
