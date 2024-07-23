cmake_minimum_required(VERSION 3.28)
project(MemOrKek)

set(CMAKE_CXX_STANDARD 17)

add_executable(MemOrKek main.cpp
        DecisionsSystem/Needs/Need.cpp
        DecisionsSystem/Needs/Need.h
        DecisionsSystem/Opportunities/Opportunity.cpp
        DecisionsSystem/Opportunities/Opportunity.h
        DecisionsSystem/Needs/Description/NeedDescription.cpp
        DecisionsSystem/Needs/Description/NeedDescription.h
        DecisionsSystem/Entity/Entity.cpp
        DecisionsSystem/Entity/Entity.h
        DecisionsSystem/Feats/Feat.cpp
        DecisionsSystem/Feats/Feat.h
        DecisionsSystem/Stats/Characteristic.cpp
        DecisionsSystem/Stats/Characteristic.h)
