//
// Created by user on 18/07/2024.
//

#include "Opportunity.h"

#include <limits>

#include "../Entity/Entity.h"
#include "../Needs/Need.h"

Opportunity::Opportunity(Entity* _owner) {
    owner = _owner;
}

Opportunity::~Opportunity() {
    owner = nullptr;
    for (const auto need : requiredNeeds) {
        delete need;
    }
    requiredNeeds.clear();
}

void Opportunity::AddNeed(Need *_need) {
    requiredNeeds.push_back(_need);
}

void Opportunity::RemoveNeed(Need *_need) {
    requiredNeeds.remove(_need);
}

void Opportunity::Advance(Entity *_actor, Need* _need) {

    // Get unsatisfied needs
    std::list<Need*> unsatisfiedNeeds;
    for (const auto need : requiredNeeds) {
        if(need->bSatisfied(_actor)) continue;
        unsatisfiedNeeds.push_back(need);
    }

    // If all needs satisfied run action
    if(unsatisfiedNeeds.empty())
    {
        RunAction(_actor);
        return;
    }

    Need* mostPriorNeed = nullptr;
    float bestNecessity = std::numeric_limits<float>::min();
    for (const auto need : unsatisfiedNeeds) {
        const auto necessity = need->GetNecessity();
        if( !mostPriorNeed ||
            necessity - bestNecessity > std::numeric_limits<float>::epsilon()) {
            mostPriorNeed = need;
            bestNecessity = necessity;
        }
    }

    mostPriorNeed->SetNecessity(mostPriorNeed->GetNecessity() + _need->GetNecessity());

    _actor->AddNeed(mostPriorNeed);
    _actor->UpdateDecision();
}
