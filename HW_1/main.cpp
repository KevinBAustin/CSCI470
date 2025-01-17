#include <iostream>
#include <cstdlib>

using namespace std;

int rollDice();
void setupPhase(int playerBal);
void betMenu(int phase);
int betPlace(int& playerBal, int min, int max);

int main(){
  int playerBal = 500;
  int minBet = 10;
  int maxBet = 200;
  int playerChoice;
  bool comeoutPhase = 1;
  bool pointPhase = 0;
  int diceSum;
  int come = 0;
  int dontcome = 0;
  int pass = 0;
  int dontpass = 0;
  int origpoint;
  int point;
  bool playing = 1;
  
  while(playing == 1){
    setupPhase(playerBal);
    bool pointRoll = 0;
    comeoutPhase = 1;

    if(playerBal < 10){
      playing = 0;
    }
    while(comeoutPhase == 1 && playing == 1){
      bool cont = 0;
      
      while(cont == 0){
	betMenu(1);
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
	  cout << "Don't Pass: " << dontpass << endl;
	  cout << "Pass: " << pass << endl;
	}
	else if(playerChoice == 4){
	  cout << "Quiting" << endl;
	  cont = 1;
	  playing = 0;
	}
	else{
	  cout << "Invalid Entry" << endl;
	}
      }

      
      if(playing == 1){
	if(diceSum == 7 || diceSum == 11){
	  cout << "Pass line bet wins" << endl;
	  if(pass > 0){
	    playerBal += pass;
	  }
	  pass = 0;
	  dontpass = 0;
	}
	
	else if(diceSum == 2 || diceSum == 3 || diceSum == 12){
	  cout << "Don't pass line bet wins" << endl;
	  if(dontpass > 0){
	    playerBal += dontpass;
	  }
	  dontpass = 0;
	  pass = 0;
	}
	
	else{
	  point = diceSum;
	  origpoint = diceSum;
	  comeoutPhase = 0;
	  pointPhase = 1;
	}
      }
    }
    
    bool next = 0;
    
    if(playing == 1){
      while(pointPhase == 1 && playing == 1){
	bool cont = 0;
	cout << "Original Point: " << origpoint << endl;
	cout << "Point    Come    Don't Come" << endl
	     << "-----    ----    ----------" << endl;
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
	cout << "Don't Pass: " << dontpass << endl
	     <<"Pass: " << pass << endl;

	while(cont == 0){
	  betMenu(2);
	  cout << "Your Choice? ";
	  cin >> playerChoice;
	  if(playerChoice == 1){
	    come = betPlace(playerBal, minBet, maxBet);
	  }
	  else if(playerChoice == 2){
	    dontcome = betPlace(playerBal, minBet, maxBet);
	  }
	  else if(playerChoice == 3){
	    diceSum = rollDice();
	    cont = 1;
	  }
	  else if(playerChoice == 4){
	    cout << "Quiting" << endl;
	    cont = 1;
	    playing = 0;
	  }
	  else{
	    cout << "Invalid Entry" << endl;
	  }
	}
	

	if(diceSum == 7){
	  cout << "Shooter rolled 7." << endl;
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
	  
	  if(diceSum == 2 || diceSum == 3 || diceSum == 12){
	    cout << "Dont come bet wins." << endl;
	    if(dontcome > 0){
	      playerBal += dontcome;
	    }
	    come = 0;
	    dontcome = 0;
	  }
	  if(diceSum == 7){
	    cout << "Don't Pass line bet wins" << endl;
	    if(dontpass > 0){
	      playerBal += dontpass;
	    }
	    dontpass = 0;
	    pass = 0;
	    pointPhase = 0;
	  }
	  if(diceSum == origpoint){
	    cout << "Pass line bet wins" << endl;
            if(pass > 0){
              playerBal += pass;
            }
            dontpass = 0;
            pass = 0;
	  }
	  
	  point = diceSum;
	  next=1;
	}
	else{
	  if(diceSum == point && pointRoll == 0){
	    cout << "Come bet wins." << endl;
	    if(come > 0){
	      playerBal += come;
	    }
	    come = 0;
	    dontcome = 0;
	    pointRoll = 1;
	  }
	  if(diceSum == 7 && pointRoll == 0){
	    cout << "Dont come bet wins." << endl;
	    if(dontcome > 0){
	      playerBal += dontcome;
	    }
	    come = 0;
	    dontcome = 0;
	  }
	  if(diceSum == 7){
            cout << "Don't Pass line bet wins" << endl;
            if(dontpass > 0){
              playerBal += dontpass;
            }
            dontpass = 0;
            pass = 0;
            pointPhase = 0;
          }
          if(diceSum == origpoint){
            cout << "Pass line bet wins" << endl;
            if(pass > 0){
              playerBal += pass;
            }
            dontpass = 0;
            pass = 0;
          }
	}
      }
    }
    
    
  }

  if(playerBal < 10){
    cout << "You are out of money" << endl;
  }
  cout<<"Game over" << endl;
  return 0;
}

int rollDice(){
    srand((unsigned) time(NULL));
    int dice = 2 + (rand()%11); //rand int bewtween 2 and 12
    cout << "Outcome of dice roll is " << dice << endl;
    return dice;
}

void setupPhase(int playerBal){
  cout << "Chips Balance: $" << playerBal << endl << endl;
}

void betMenu(int phase){
  if(phase == 1){
    cout << "Bet Menu:" << endl;
    cout << "1. Bet Pass line" << endl;
    cout << "2. Don't Pass Line Bet" << endl;
    cout << "3. Roll the Dice" << endl;
    cout << "4. Quit" << endl;
  }
  else if(phase == 2){
    cout << "Bet Menu:" << endl;
    cout << "1. Come Line Bet" << endl;
    cout << "2. Don't Come Line Bet" << endl;
    cout << "3. Roll the Dice" << endl;
    cout << "4. Quit" << endl;
  }
}

int betPlace(int& playerBal, int min, int max){
  int playerBet;
  cout << "Your balance is $" << playerBal << ". How much do you want to bet?";
  bool cont = 0;
  while(cont == 0){
    cin >> playerBet;
    if(playerBet >= min && playerBet <= max){
      cont = 1;
      cout << "Bet placed" << endl;
      playerBal -= playerBet;
    }
    else{
      cout << "Bet is outside betting bounds. Minimum bet is " << min << " Maximum bet is " << max << " Try again." << endl;
    }
  }
  return playerBet;
}
