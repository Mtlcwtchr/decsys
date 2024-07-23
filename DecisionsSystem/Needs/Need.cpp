//
// Created by user on 18/07/2024.
//

#include "Need.h"
#include "Description/NeedDescription.h"
#include "../Opportunities/Opportunity.h"

#include <cmath>
#include <limits>

Need::Need(Entity* _owner, NeedDescription* _description) {
    description = _description;
    necessity = _description->baseNecessity;
    owner = _owner;
}

Need::~Need() {
    owner = nullptr;
    description = nullptr;
    for (const auto opp : resolutionOpportunities) {
        delete opp;
    }

    resolutionOpportunities.clear();
}

void Need::AddOpportunity(Opportunity* _opportunity) {
    resolutionOpportunities.push_back(_opportunity);
}

void Need::RemoveOpportunity(Opportunity* _opportunity) {
    resolutionOpportunities.remove(_opportunity);
}

Opportunity * Need::FindBestResolution(Entity* _actor) const {
    if(resolutionOpportunities.empty())
        return nullptr;

    Opportunity* bestOpportunity = nullptr;
    auto bestChance = std::numeric_limits<float>::min();
    auto bestPriority = std::numeric_limits<float>::min();
    for (const auto opportunity : resolutionOpportunities)
    {
        if(!opportunity->CanPerform(_actor))
            continue;

        const auto chance = opportunity->GetSuccessChance(_actor);
        const auto priority = opportunity->GetPriority(_actor);

        if(!bestOpportunity ||
            (chance - bestChance > std::numeric_limits<float>::epsilon() ||
            (std::abs(chance - bestChance) <= std::numeric_limits<float>::epsilon() &&
             std::abs(priority - bestPriority) > std::numeric_limits<float>::epsilon())))
        {
            bestChance = chance;
            bestPriority = priority;
            bestOpportunity = opportunity;
        }
    }

    return bestOpportunity;
}
