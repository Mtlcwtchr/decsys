//
// Created by aliqu on 7/22/2024.
//

#include "Feat.h"

Feat::Feat(EFeat _type, float _baseProgression) {
    progression = _baseProgression;
    type = _type;
}

void Feat::Append(Feat* _feat) {
    if(_feat->type != type) {
        delete _feat;
        return;
    }

    Append(_feat->GetProgression());
    delete _feat;
}
