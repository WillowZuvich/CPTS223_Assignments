//
// Created by Willow Zuvich on 10/14/23.
//

#include "Game.h"

//constructor
Game::Game()
{
    mNumProfiles = 0;
   //load data
   loadCommands();
   loadProfiles();

    mNumQuestions = MIN_QUESTIONS;
    mCurrentProfileLocation = 0;
}

//function controls flow of game
void Game::play()
{
    int choice = -1;
    ///welcome message
    std::cout<< "********WELCOME!*******" << std::endl;

    do
    {
        //menu
        choice = menu();

        //reset used question vector (clear if necessary, ie not empty)
        mUsedCommands.clear();

        switch(choice)
        {
            case RULES:
                //display rules
                displayRules();
                break;
            case PLAY:
                //add profile
                addProfile();
                //get number of questions
                getNumQuestions();
                //run questions
                runQuestions();
                break;
            case LOAD:
                //load profile info
                loadGame();
                //get number of questions
                getNumQuestions();
                //run questions
                runQuestions();
                break;
            case ADD:
                //add command
                addCommand();
                break;
            case REMOVE:
                //remove command
                removeCommand();
                break;
            case EXIT:
                //store data
                storeCommands();
                storeProfiles();
                break;
        }
    }
    while(choice != EXIT);
}

//load Commands --populates mCommandList with commands and definitions
// returns true if commands.csv was successfully opened, false if not
void Game::loadCommands()
{
    std::ifstream commandStr;
    commandStr.open("CSV/commands.csv");
    std::string line;
    std::string tempCommand;
    std::string tempDef;

    if(commandStr.is_open())
    {
        while(!commandStr.eof())
        {
            getline(commandStr, line);
            std::stringstream ss(line);
            getline(ss, tempCommand, ',');
            getline(ss, tempDef, '\"');
            getline(ss, tempDef, '\"');

            mCommandList.insertFront(tempCommand, tempDef);
        }
    }
    else
        std::cout << "Failed to load Commands" << std::endl;

    commandStr.close();
}

//load profiles -- populates mProfiles
void Game::loadProfiles()
{
    std::ifstream profStr;
    profStr.open("CSV/profiles.csv");
    std::string line;
    std::string tempName;
    std::string tempPoints;

    if(profStr.is_open())
    {
        while(!profStr.eof() && mNumProfiles < MAX_PROFILES)
        {
            getline(profStr, line);
            std::stringstream ss(line);
            getline(ss, tempName, ',');
            getline(ss, tempPoints);

            //make space in array
            for(int i = mNumProfiles; i > 0; --i)
            {
                mProfiles[i] = mProfiles[i-1];
            }

            mProfiles[0].setName(tempName);
            mProfiles[0].setPoints(stoi(tempPoints));

            ++mNumProfiles;
        }
    }
    else
        std::cout << "Failed to open profile.csv" << std::endl;

    //close file
    profStr.close();
}

//store commands --stores commands to commands.csv
void Game::storeCommands()
{
    std::ofstream oStr("CSV/commands.csv");
    Node<std::string, std::string> * pCur = mCommandList.getHead();

    if(oStr.is_open())
    {
        for(; pCur != nullptr; pCur = pCur->getNext())
        {
            oStr << pCur->getP1() << ",\"" << pCur->getP2() << "\"";
            if(pCur->getNext() != nullptr)
            {
                oStr << std::endl;
            }
        }
    }
    else
        std::cout << "Failed to open commands.csv for writing" << std::endl;

    //close file
    oStr.close();
}

//store profiles -- stores profiles to profiles.csv
void Game::storeProfiles()
{
    std::ofstream oStr("CSV/profiles.csv");

    if(oStr.is_open())
    {
        for(int i = 0; i < mNumProfiles; ++i)
        {
            oStr << mProfiles[i].getName() << "," << mProfiles[i].getPoints();
            if(i + 1 != mNumProfiles)
            {
                oStr << std::endl;
            }
        }
    }
    else
        std::cout << "Failed to open profiles.csv for writing" << std::endl;

    //close file
    oStr.close();
}

//function displays menu options to user and returns user choice
int Game::menu()
{
    int choice = -1;

    do {
        std::cout << "********MENU********\n";
        std::cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n";
        std::cout << "5. Remove Command\n6. Exit\nEnter Choice: ";

        std::cin >> choice;

        system("clear");

    }while(choice != RULES && choice != PLAY && choice != LOAD && choice != ADD
    && choice != REMOVE && choice != EXIT);

    return choice;
}

//function displays game rules
void Game::displayRules()
{
    char key;
    do
    {
        std::cout << "********RULES********\n";
        std::cout << "The goal of this game is to gain points by correctly matching Linux commands\n";
        std::cout << "with their descriptions. You will be provided with three descriptions to\n";
        std::cout << "choose from. Incorrect answers lead to a loss of one point. You may choose\n";
        std::cout << "to answer between 5-30 questions.\n";
        std::cout << "Additionally, you may add or remove commands, and load a previous game.\n";
        std::cout << "Enter 'r' to return to the Menu: ";
        std::cin >> key;
        system("clear");
    }while(key != RETURN);
}

//function allows user to load previous game stats from the profiles on record
//returns 1 if profile was loaded, 0 if not
bool Game::loadGame()
{
    bool found = false;
    std::string name;
    int i = 0;
    int key = 0;

    {
        std::cout << "Enter Profile Name: ";
        std::cin >> name;
        system("clear");

        for (; !found && i < mNumProfiles; ++i) {
            if (name == mProfiles[i].getName())
                found = true;
        }

        if (found) {
            mCurrentProfileLocation = i-1;
            do {
                std::cout << "Current points: " << mProfiles[i - 1].getPoints() << std::endl;
                std::cout << "Press (1) to continue: ";
                std::cin >> key;
                system("clear");
            } while (key != CONTINUE);
        } else {
            do {
                std::cout << "Profile not found. Press (1) to Enter a new name, press (2) to Quit: ";
                std::cin >> key;
                system("clear");
            } while (key != CONTINUE && key != QUIT);
        }
    }while(!found && key != QUIT);
    return found;
}

//function allows user to add a new command --no repeats
void Game::addCommand()
{
    int key = 0;
    bool duplicate = false;
    std::string newCommand;
    std::string newDesc;

    do {
        std::cout << "Enter Command: ";
        std::cin >> newCommand;
        duplicate = mCommandList.searchList(newCommand);
        system("clear");

        if(!duplicate)
        {
            std::cout << "Enter Description: ";
            std::cin >> newDesc;
            mCommandList.insertFront(newCommand, newDesc);
        }
        else
        {
            do
            {
                std::cout << "Command is already in List.\nPress (1) to Enter a new command or press (2) to Quit: ";
                std::cin >> key;
                system("clear");
            }while(key != CONTINUE && key != QUIT);
        }

    }while(duplicate && key != QUIT);
}

//function allows user to remove a command
void Game::removeCommand()
{
    int key = 0;
    bool found = false;
    std::string newCommand;
    std::string newDesc;

    do {
        std::cout << "Enter Command: ";
        std::cin >> newCommand;
        found = mCommandList.removeNode(newCommand);
        system("clear");

        if(!found)
        {
            do
            {
                std::cout << "Command not found.\nPress (1) to Enter a new command or press (2) to Quit: ";
                std::cin >> key;
                system("clear");
            }while(key != CONTINUE && key != QUIT);
        }

    }while(!found && key != QUIT);

}

//function gets user input of number of questions
void Game::getNumQuestions()
{
    int num = 0;
    do
    {
        std::cout << "Enter how many questions you want to answer(5-30): ";
        std::cin >> num;
        system("clear");
    }while(!(num <= MAX_QUESTIONS && num >= MIN_QUESTIONS));
    mNumQuestions = num;
}

//function runs through the requested number of questions
void Game::runQuestions()
{
    int correct = 0;
    Node<std::string, std::string> * pCorrect, *p2, *p3;
    int answer = 0;
    int key = 0;

    for(int i = 0; i < mNumQuestions; ++i)
    {
        //generate command and 3 descriptions
        correct = generateRandom(3, 1);
        do
        {
            pCorrect = genCommand();
        }while(std::find(mUsedCommands.begin(), mUsedCommands.end(),
                         pCorrect->getP1()) != mUsedCommands.end());
        mUsedCommands.push_back(pCorrect->getP1()); //add command to used list

        do {
            p2 = genCommand();
        }while(p2 == pCorrect);
        do {
            p3 = genCommand();
        }while(p3 == pCorrect || p3 == p2);

        //display answers
        std::cout << "Command: " << pCorrect->getP1() << std::endl;
        bool second = false;
        for(int j = 1; j <= 3; ++j)
        {
            if(j == correct)
            {
                std::cout << j << ". " << pCorrect->getP2() << std::endl;
            }
            else if(!second)
            {
                std::cout << j << ". " << p2->getP2() << std::endl;
                second = true;
            }
            else
                std::cout << j << ". " << p3->getP2() << std:: endl;
        }


        do {
            std::cout << "Enter Selection: ";
            std::cin >> answer;
        }while(answer != 1 && answer != 2 && answer != 3);

        system("clear");

        if(correct == answer)
        {
            mProfiles[mCurrentProfileLocation].addPoint();
            std::cout << "Correct!\n" << pCorrect->getP1() << ": " << pCorrect->getP2() << std::endl;
            std::cout << "One Point Earned. Point Total: " << mProfiles[mCurrentProfileLocation].getPoints() << std::endl;
        }
        else
        {
            mProfiles[mCurrentProfileLocation].subtractPoint();
            std::cout << "Incorrect.\n" << pCorrect->getP1() << ": " << pCorrect->getP2() << std::endl;
            std::cout << "One Point Lost. Point Total: " << mProfiles[mCurrentProfileLocation].getPoints() << std::endl;
        }

        do {
            std::cout << "Enter (1) to continue: ";
            std::cin >> key;
            system("clear");
        }while(key != CONTINUE);
    }
}

//function allows user to create a new profile
void Game::addProfile()
{
    std::string newName;

    //create space for profile
    for(int i = mNumProfiles; i > 0; --i)
    {
        mProfiles[i] = mProfiles[i-1];
    }

    std::cout << "Enter Profile Name: ";
    std::cin >> newName;

    //insert new profile
    mProfiles[0].setName(newName);
    mProfiles[0].setPoints(0);

    //update number of profiles
    ++mNumProfiles;

    //update profile location
    mCurrentProfileLocation = 0;
}

//function returns a reference to a random node contained in mCommandList
Node<std::string, std::string> *& Game::genCommand()
{
    int i;
    Node<std::string, std::string> * pCur;
    pCur = mCommandList.getHead();

    i = generateRandom(MAX_QUESTIONS, 0);

    for(; i > 0; --i)
    {
        if(pCur->getNext() == nullptr)
            pCur = mCommandList.getHead();
        else
            pCur = pCur->getNext();
    }

    return pCur;
}

//function generates a random number between max and min (inclusive)
int Game::generateRandom(int max, int min)
{
    int n;

    n = (rand() % max - (min - 1)) + min;

    return n;
}

