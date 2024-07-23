//
// Created by aliqu on 7/22/2024.
//

#ifndef FEAT_H
#define FEAT_H
#include <_mingw.h>

enum EFeat {

};

class Feat {

private:
    EFeat type;
    float progression;

public:
    Feat(EFeat _type, float _baseProgression);

    void Append(Feat* _feat);

    __forceinline float GetProgression() const { return progression; }
    __forceinline void Append(const float _progression) { progression += _progression; }

    __forceinline EFeat GetType() const { return type; }
};



#endif //FEAT_H
