//
// Created by Willow Zuvich on 9/15/23.
//

#include "profile.h"

std::string profile::getName() const {
    return mName;
}

int profile::getPoints() const {
    return mPoints;
}

void profile::setName(const std::string &name) {
    mName = name;
}

void profile::setPoints(const int points) {
    mPoints = points;
}

void profile::subtractPoint() {
    mPoints -= POINT_INCREMENT;
}

void profile::addPoint() {
    mPoints += POINT_INCREMENT;
}
