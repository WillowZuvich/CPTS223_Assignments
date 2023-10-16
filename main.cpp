#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here

    //Scenario 1
    cout << "***Scenario 1 Map***" << endl;
    //create map
    map<string, TwitterData> map1;
    //insert data
    for(int i = 0; i < 5; ++i)
    {
        map1.insert({twitter_data[i].getUserName(), twitter_data[i]});
    }
    //print contents line by line
    for(auto & i : map1)
    {
        cout << "Key: " << i.first << ", Value: " << i.second.print() << endl;
    }

    //find username savage1
    auto j = map1.find("savage1");
    //print record
    cout << "Search for Key: " << j->first << ", Value: " << j->second.print() << endl;

    //remove person from tree
    map1.erase(j);

    cout << endl << endl;

    //Scenario 2
    cout << "***Scenario 2 Map***" << endl;

    //create map
    map<string, TwitterData> map2;
    //insert data
    for(int i = 0; i < 5; ++i)
    {
        map2.insert({twitter_data[i].getEmail(), twitter_data[i]});
    }
    //print contents line by line
    for(auto & i : map2)
    {
        cout << "Key: " << i.first << ", Value: " << i.second.print() << endl;
    }

    //find username savage1
    auto k = map2.find("kat@gmail.com");
    //print record
    cout << "Search for Key: " << k->first << ", Value: " << k->second.print() << endl;

    //remove person from tree
    map2.erase(k);


    return 0;
}