//
// Created by aliqu on 7/22/2024.
//

#include "Characteristic.h"

Characteristic::Characteristic(ECharacteristic _type, float _baseValue) {
    type = _type;
    value = _baseValue;
}

void Characteristic::Append(Characteristic* _characteristic) {
    if(_characteristic->type != type) {
        delete _characteristic;
        return;
    }

    Set(Get() + _characteristic->Get()) ;

    delete _characteristic;
}
