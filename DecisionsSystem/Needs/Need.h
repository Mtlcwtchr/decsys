//
// Created by user on 18/07/2024.
//

#ifndef NEED_H
#define NEED_H

#include <list>

class Entity;
class Opportunity;
class NeedDescription;

class Need {

protected:
    Entity* owner;
    NeedDescription* description;

    float necessity;
    std::list<Opportunity*> resolutionOpportunities;

public:
    explicit Need(Entity* _owner, NeedDescription* _description);
    virtual ~Need();

    void AddOpportunity(Opportunity* _opportunity);
    void RemoveOpportunity(Opportunity* _opportunity);

    Opportunity* FindBestResolution(Entity* _actor) const;

    __forceinline void SetNecessity(const float _necessity) { necessity = _necessity;}
    __forceinline float GetNecessity() const { return necessity; }

    __forceinline Entity* GetOwner() const { return owner; }
    __forceinline NeedDescription* GetDescription() const { return description; }

    virtual float GetSatisfaction(Entity* _actor) = 0;
    virtual bool bSatisfied(Entity* _actor) = 0;
};



#endif //NEED_H
