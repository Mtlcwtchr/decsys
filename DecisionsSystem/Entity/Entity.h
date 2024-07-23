//
// Created by user on 18/07/2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <list>

class Opportunity;
class Need;
class Feat;
class Characteristic;

class Entity {

private:
    std::list<Need*> needs;
    std::list<Opportunity*> opportunities;

    std::list<Feat*> feats;
    std::list<Characteristic*> stats;

    Need* currentGoalNeed = nullptr;
    Opportunity* currentGoalOpportunity = nullptr;

public:
    virtual ~Entity();

    void AddNeed(Need* _need);
    void AddOpportunity(Opportunity* _opportunity);

    void AddFeat(Feat* _feat);
    void AddCharacteristic(Characteristic* _characteristic);

    void UpdateDecision();
};



#endif //ENTITY_H
