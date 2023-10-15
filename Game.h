//
// Created by Willow Zuvich on 10/14/23.
//

#ifndef CPTS223_ASSIGNMENTS_GAME_H
#define CPTS223_ASSIGNMENTS_GAME_H

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "profile.h"

#define MAX_PROFILES 15
#define MAX_QUESTIONS 30
#define MIN_QUESTIONS 5

#define RULES 1
#define PLAY 2
#define LOAD 3
#define ADD 4
#define REMOVE 5
#define EXIT 6

#define RETURN 'r'
#define CONTINUE 1
#define QUIT 2

class Game{
public:
    //constructor
    Game();

    //function controls flow of game
    void play();

private:

    //members
    LinkedList<std::string, std::string> mCommandList;
    profile mProfiles[MAX_PROFILES];


    int mNumQuestions;
    int mCurrentProfileLocation;
    int mNumProfiles;
    std::vector<std::string> mUsedCommands;


    //member functions
    //load Commands --populates mCommandList with commands and definitions
    void loadCommands();

    //load profiles -- populates mProfiles
    void loadProfiles();

    //store commands --stores commands to commands.csv
    void storeCommands();

    //store profiles -- stores profiles to profiles.csv
    void storeProfiles();

    //function displays menu options to user and returns user choice
    int menu();

    //function displays game rules
    void displayRules();

    //function allows user to load previous game stats from the profiles on record
    //returns 1 if profile was loaded, 0 if not
    bool loadGame();

    //function allows user to add a new command --no repeats
    void addCommand();

    //function allows user to remove a command
    void removeCommand();

    //function gets user input of number of questions
    void getNumQuestions();

    //function runs through the requested number of questions
    void runQuestions();

    //function allows user to create a new profile
    void addProfile();

    //function returns a reference to a random node contained in mCommandList
    Node<std::string, std::string> *& genCommand();

    //function generates a random number between max and min (inclusive)
    int generateRandom(int max, int min);

};


#endif //CPTS223_ASSIGNMENTS_GAME_H
