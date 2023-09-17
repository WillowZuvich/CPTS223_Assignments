//
// Created by Willow Zuvich on 9/15/23.
//

#pragma once
#include<iostream>

#define POINT_INCREMENT 1

class profile
{
public:

    //getters
    std::string getName() const;

    int getPoints() const;

    //setters
    void setName(const std::string &name);

    void setPoints(const int points);

    //manipulate points
    void subtractPoint();

    void addPoint();

private:
    int mPoints;
    std::string mName;
};



