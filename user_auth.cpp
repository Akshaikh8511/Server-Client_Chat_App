// user_auth.cpp

//////////////////////////////////////////////////// Header ///////////////////////////////////////////////////////////////////////
/* In this contains function defination for loading, savaing and authenticating user_credential data for the client - server project
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <algorithm>
#include "server.h"
#include "user_auth.h"
#include <vector>

using namespace std;

vector<UserData> user_data; // vector to store the user data

// This function is used to load the data from the user_credential file  (user.txt)
void UserManager::loadUserFile()
{
    ifstream userFile("users.txt");
    if (!userFile.is_open())
    {
        cout << "Error opening user file." << endl;
        return;
    }
    UserData user;

    while (userFile >> user.username >> user.password)
    {
        user_data.push_back(user);
    }
    userFile.close();
}

//  This function save the data to user_credential file  (User.txt)
void UserManager::saveUserFile()
{
    ofstream userFile("users.txt");
    if (!userFile.is_open())
    {
        cout << "Error opening user file." << endl;
        return;
    }
    for (const UserData &user : user_data)
    {
        userFile << user.username << " " << user.password << endl;
    }
    userFile.close();
}

// Authenticate the user by verify password and username
bool UserManager::authenticateUser(const std::string &username, const std::string &password)
{
    for (const UserData &user : user_data)
    {
        if (user.username == username)
        {
            if (user.password == password)
            {
                return true; // Authentication successful
            }
            else
            {
                cout << "Enter Valid Password.." << endl;
                return 0;
            } // Authentication successful
        }
    }

    return false;
}

// Is username taken verify that if the user is already taken by existing user or not
bool UserManager::isUsernameTaken(const std::string &username)
{
    for (const UserData &user : user_data)
    {
        if (user.username == username)
        {
            return true; // Username is already taken
        }
    }
    return false; // Username is available
}