//
// Created by user on 18/07/2024.
//

#ifndef OPPORTUNITY_H
#define OPPORTUNITY_H

#include <list>

class Entity;
class Need;

class Opportunity {

private:
    Entity* owner;
    std::list<Need*> requiredNeeds;

public:
    explicit Opportunity(Entity* _owner);
    virtual ~Opportunity();

    void AddNeed(Need* _need);
    void RemoveNeed(Need* _need);

    __forceinline Entity* GetOwner() const { return owner; }

    void Advance(Entity* _actor, Need* _need);
    virtual float GetSuccessChance(Entity* _actor) = 0;
    virtual float GetPriority(Entity* _actor) = 0;

    virtual bool CanPerform(Entity* _actor) = 0;
    virtual void RunAction(Entity* _actor) = 0;
};



#endif //OPPORTUNITY_H
