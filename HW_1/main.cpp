#include <iostream>
#include <cstdlin>

using namespace std;

int rollDice();
void betMenu();
void betMenu2();
int betPlace(int& playerBal, int min, int max);

int main(){
  int playerBal = 500;
  int minBet = 10;
  int maxBet = 200;
  int playerChoice;
  bool comeoutPhase = 1;
  bool pointPhase = 0;
  int diceSum;
  int come;
  int dontcome;
  int pass;
  int dontpass;
  int point;
  
  while(playerBal > 10 || playerChoice != 4){

    bool pointRoll = 0;
    
    while(comeoutPhase == 1 || playerChoice != 4){
      bool cont = 0;
      
      while(cont == 0 || playerChoice != 4){
	betMenu();
	cout << "Your Choice? ";
	cin >> playerChoice;
	
	if(playerChoice == 1){
	  pass = betPlace(playerBal, minBet, maxBet);
	}
	else if(playerChoice == 2){
	  dontpass = betPlace(playerBal, minBet, maxBet);
	}
	else if(playerChoice == 3){
	  diceSum = rollDice();
	  cont = 1;
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
	if(pass > 0){
	  playerBal += pass;
	}
	pass = 0;
	dontpass = 0
      }

      else if(diceSum == 2 || diceSum == 3 || diceSum == 12){
	cout << "Don't pass line bet wins" << endl;
	if(dontpass > 0){
	  playerBal += dontpass;
	}
	dontpass = 0;
	pass = 0
      }

      else{
	point = diceSum;
	comeoutPhase = 0;
	pointPhase = 1;
      }
    }

    bool next = 0;
    while(pointPhase == 1 || playerChoice !=4){
      bool cont = 0;
      
      if(point == 4){
	cout << "on ";
      }
      cout << "4" << endl;
      if(point == 5){
        cout << "on ";
      }
      cout << "5" << endl;
      if(point == 6){
        cout << "on ";
      }
      cout << "6" << endl;
      if(point == 8){
        cout << "on ";
      }
      cout << "8" << endl;
      if(point == 9){
        cout << "on ";
      }
      cout << "9" << endl;
      if(point == 10){
        cout << "on ";
      }
      cout << "10" << endl;

      while(cont == 0 || playerChoice != 4){
	betMenu();
	cout << "Your Choice? ";
	cin >> playerChoice;
	if(playerChoice == 1){
	  come = betPlace(playerBal, playerBet, minBet, maxBet);
	}
	else if(playerChoice == 2){
	  dontcome = betPlace(playerBal, playerBet, minBet, maxBet);
	}
	else if(playerChoice == 3){
	  diceSum = rollDice();
	  cont = 1;
	}
	else if(playerChoice == 4){
	  cout << "Quiting" << endl;
	}
	else{
	  cout << "Invalid Entry" << endl;
	}
      }
      
      if(diceSum == point){
	pointRoll = 1;
      }
      if(diceSum == 7){
	pointPhase = 0;
	cout << "Shooter rolled 7. " << endl;
      }
      
      if(pointRoll == 1 && pointPhase == 1){
	cout << "Pass line bet wins." << endl;
	if(pass > 0){
          playerBal += pass;
        }
        pass = 0;
        dontpass = 0
      }
      if(pointRoll == 0 && pointPhase == 0){
	cout << "Dont pass line bet wins." << endl;
	if(dontpass > 0){
          playerBal += dontpass;
        }
        pass = 0;
        dontpass = 0
      }

      
      if(next == 0){
	if(diceSum == 7 || diceSum == 11){
	  cout << "Come bet wins." << endl;
	  if(come > 0){
	    playerBal += come;
	  }
	  come = 0;
	  dontcome = 0;
	}

	else if(diceSum == 2 || diceSum == 3 || diceSum == 12){
	  cout << "Dont come bet wins." << endl;
          if(dontcome > 0){
            playerBal = dontcome*2;
          }
          come = 0;
          dontcome = 0;
	}
	else{
	  point = diceSum;
	}
	next = 1;
      }
      else{
	if(diceSum == point && pointPhase == 1){
	  cout << "Come bet wins." << endl;
	  if(come > 0){
	    playerBal += come;
	  }
	  come = 0;
	  dontcome = 0;
	}
	else if (pointPhase == 0 && pointRoll == 0){
	  cout << "Dont come bet wins." << endl;
          if(dontcome > 0){
            playerBal = dontcome*2;
          }
          come = 0;
          dontcome = 0;
	}
      }
      
    }
  }
  
  return 0;
}

int betPlace(int& playerBal, int min, int max){
  int playerBet
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

  return playerBet;
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
