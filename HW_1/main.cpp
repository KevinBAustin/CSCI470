#include <iostream>

using namespace std;

int rollDice();
void betMenu();
void betMenu2();
void betPlace(int& playerBal, int& playerBet, int min, int max);

int main(){
  int playerBal = 500;
  int minBet = 10;
  int maxBet = 200;
  int playerChoice;
  bool comeoutPhase = 1;
  bool pointPhase = 0;
  int diceSum;
  int betType;
  int playerBet;
  int point;
  
  while(playerBal > 10 || playerChoice != 4){

    while(comeoutPhase == 1 || playerChoice != 4){
      bool continue = 0;
      
      while(continue == 0 || playerChoice != 4){
	betMenu();
	cout << "Your Choice? ";
	cin >> playerChoice;
	if(playerChoice == 1){
	  betType = 1;
	  betPlace(playerBal, playerBet, minBet, maxBet);
	}
	else if(playerChoice == 2){
	  betType = 2;
	  betPlace(playerBal, playerBet, minBet, maxBet);
	}
	else if(playerChoice == 3){
	  diceSum = rollDice();
	  continue = 1;
	}
	else if(playerChoice == 4){
	  cout << "Quiting" << endl;
	}
	else{
	  cout << "Invalid Entry" << endl;
	}
      }
      
      if(diceSum == 7 || diceSum == 11){
	cout << "Pass line bet wins" << endl;
	if(betType == 1)
	  playerBal += playerBet;
      }

      else if(diceSum == 2 || diceSum == 3 || diceSum == 12){
	cout << "Don't pass line bet wins" << endl;
	if(betType == 2)
	  playerBal += playerBet;
      }

      else{
	point = betSum;
	comeoutPhase = 0;
	pointPhase = 1;
      }
    }

    while(pointPhase == 1 || playerChoice !=4){
      
    }

    
  }
  
  return 0;
}

void betPlace(int& playerBal, int& playerBet ,int min, int max){
  cout << "Your balance is $" << playerBal << ". How much do you want to bet?";
  bool continue = 0;
  while(continue == 0){
    cin >> playerBet;
    if(playerBet > min && playerBet < max){
      continue = 1;
      cout << "Bet placed" << endl;
      playerBal -= playerBet;
    }
    else{
      cout << "Bet is outside betting bounds. Minimum bet is " << min << " Maximum bet is " << max << " Try again." << endl;
    }
  }
}

int rollDice(){
  srand((unsigned) time(NULL));
  int dice = 2 + (rand()%11); //rand int bewtween 2 and 12
  return dice;
}

int betMenu(){
  cout << "Bet Menu:" << endl;
  cout << "1. Bet Pass line" << endl;
  cout << "2. Don't Pass Line Bet" << endl;
  cout << "3. Roll the Dice" << endl;
  cout << "4. Quit" << endl;
}

int betMenu2(){
  cout << "Bet Menu:" << endl;
  cout << "1. Come Line Bet" << endl;
  cout << "2. Don't Come Line Bet" << endl;
  cout << "3. Roll the Dice" << endl;
  cout << "4. Quit" << endl;
}
