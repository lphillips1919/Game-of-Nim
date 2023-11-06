// The game of Nim
// Project 2
// Logan Phillips
// 4-20-22

#include<iostream>
#include<string> 

using namespace std;

const string USER {"User"};
const string COMPUTER {"Computer"};
int numTokens {10};
string activePlayer;
void WelcomeMessage();
void ChooseWhoGoesFirst(string& activePlayer);
void UserTurn(int& numTokens, string& activePlayer);
void GameBoard(int& numTokens, string& activePlayer);
void ComputerTurn(int& numTokens, string& activePlayer);
void GameWinner(string& activePlayer);

int main() { 

    WelcomeMessage();
    
    string activePlayer;

    ChooseWhoGoesFirst(activePlayer);

    GameBoard(numTokens, activePlayer);
    cout << endl;

    while (numTokens > 0) {
        if(activePlayer == USER) {
            UserTurn(numTokens, activePlayer);
            cout << endl;
        } else {
            ComputerTurn(numTokens, activePlayer);
            cout << endl;
        }
    }
    return 0;
}
// display a welcome message
    
void WelcomeMessage() {
    cout << "Welcome to NIM!" << endl;
    cout <<  endl;

    cout << "We start with 10 tokens on the board, and we will take turns" << endl;
    cout << "each removing either 1 or 2 tokens. The player who takes the" << endl;
    cout << "last token wins the game" << endl;
    cout << endl;   
    
    }
// prompt the user to see if the first turn is by the User or Computer

void ChooseWhoGoesFirst(string& activePlayer) {
    string userResponse;

    cout << "Who should go first? Type User " << "or " << "U " << "if you want" << endl;
    cout << "to go first, " << "or " <<  "Computer " << "or " << "c " "if you want me to go" << endl; 
    cout << "first, and press Return. ";
    getline (cin, userResponse);
    cout << endl;
 
    while(userResponse.at(0) != 'U' and
          userResponse.at(0) != 'u' and
          userResponse.at(0) != 'C' and
          userResponse.at(0) != 'c') {
        cout << "Im sorry, I don't understand that.";
        cout << endl;
        cout << "Please enter c to let the computer go first," << endl;
        cout << "or u if you want to go first: " << endl;
        getline (cin, userResponse);
        cout << endl;
    }
    if (userResponse.at(0) == 'u' or
        userResponse.at(0) == 'U') {
        activePlayer = USER;
    } else {
        activePlayer = COMPUTER;
    } 

    return;    
   
}

// function for the user turn 

void UserTurn(int& numTokens, string& activePlayer) {

    int num;

    if(numTokens >= 2) {
        cout << "Your turn. How many tokens do you want to take?"<< endl;
        cout << "(Type 1 or 2, then press Return): ";
        cin  >> num;
        while (num != 1 && num != 2) {
            cout <<  "You must take either 1 or 2." << endl;
            cout << "(Type 1 or 2, then press enter) ";
            cin >> num;
            cout << endl;
        }   numTokens -= num;
    } else {
        cout << "There is only one token left." << endl;
        numTokens = 0;
    }
    cout << endl;
    GameBoard(numTokens, activePlayer);
    cout << endl;

    if (numTokens == 0){
        GameWinner(activePlayer);
    }
    activePlayer = COMPUTER;
    
    return;
}
//Display the gameborad
void GameBoard(int& numTokens, string& activePlayer) {

    if(numTokens != 1) {
        cout <<"There are " << numTokens << " tokens left." << endl;
        if(numTokens != 0) {
            cout << "*";
        } 
        
        for (int i = 1; i < numTokens; i++) {
                 cout << " *";
        }
        } else {
        cout << "There is one Token left." << endl;
        cout << "*" << endl; 
            
    }
 
    

    return;
}
// function for computer turn
void ComputerTurn(int& numTokens, string& activePlayer) {

    if (numTokens % 3 == 1 || numTokens % 3 == 0) {
        numTokens -= 1;
        cout << "Computer takes 1." << endl;
        cout << endl;
    } else { 
        numTokens -= 2;
        cout << "Computer takes 2." << endl;
        cout << endl;
    }
    cout << endl;
    GameBoard(numTokens, activePlayer);
    cout << endl;

    if (numTokens == 0) {
        GameWinner(activePlayer);
    }
    activePlayer = USER;
 
    return;
}

// function for the winner of the game
void GameWinner(string& activePlayer) {

    if (activePlayer == USER) {
        cout << "Congratulations! You won!";
    } else {
        cout << "Sorry! I won that game!";
        }
        cout << endl;
    
    return;
}

