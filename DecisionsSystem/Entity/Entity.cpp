//
// Created by user on 18/07/2024.
//

#include "Entity.h"

#include <cstdio>
#include <limits>

#include "../Opportunities/Opportunity.h"
#include "../Needs/Need.h"
#include "../Feats/Feat.h"
#include "../Stats/Characteristic.h"

Entity::~Entity() {
    for (const auto opp : opportunities) {
        delete opp;
    }

    for(const auto need : needs) {
        delete need;
    }

    for(const auto stat : stats) {
        delete stat;
    }

    for(const auto feat : feats) {
        delete feat;
    }

    stats.clear();
    feats.clear();
    needs.clear();
    opportunities.clear();
}

void Entity::AddNeed(Need *_need) {
    needs.push_back(_need);
}

void Entity::AddOpportunity(Opportunity *_opportunity) {
    opportunities.push_back(_opportunity);
}

void Entity::AddFeat(Feat *_feat) {
    for (auto feat : feats) {
        if(feat->GetType() != _feat->GetType())
            continue;

        feat->Append(_feat);
        return;
    }

    feats.push_back(_feat);
}

void Entity::AddCharacteristic(Characteristic *_characteristic) {
    for (auto stat : stats) {
        if(stat->GetType() != _characteristic->GetType())
            continue;

        stat->Append(_characteristic);
        return;
    }

    stats.push_back(_characteristic);
}

void Entity::UpdateDecision() {

    // Get unsatisfied needs
    std::list<Need*> unsatisfiedNeeds;
    for (const auto need : needs) {
        if(need->bSatisfied(this)) continue;
        unsatisfiedNeeds.push_back(need);
    }

    // If all needs satisfied add some higher level need
    if(unsatisfiedNeeds.empty())
    {
        printf("No needs");
        // TODO: some random need
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

    if(currentGoalNeed && currentGoalNeed->GetNecessity() > bestNecessity) return;

    const auto bestResolution = mostPriorNeed->FindBestResolution(this);

    currentGoalNeed = mostPriorNeed;
    currentGoalOpportunity = bestResolution;

    bestResolution->Advance(this, currentGoalNeed);
}
