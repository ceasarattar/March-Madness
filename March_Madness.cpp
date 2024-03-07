// Ceasar Attar
// VS Code on MacOS

#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // Allows using the tolower() function
#include <vector>     // For vectors
#include <cstring>    // For C string function strcpy
#include <sstream>    // For reading in CSV file and splitting by commas
#include <algorithm>  // For find(), which searches within a vector\
#include <utility>    // For the utility function in my class
using namespace std;

void displayWelcomeMessage() {  // function that displays the welcome message 
  
  cout << "Program 5: March Madness Frenzy \n"
       << "CS 141, Spring 2022, UIC \n"
       << " \n"
       << "This program reads in data from NCAA Basketball Tournaments (aka March \n"
       << "Madness). It provides overall information regarding the data, allows you to \n"
       << "see the path taken to the championship, uses rankings of teams to determine \n"
       << "which region is expected to win at a given round and to find the best \n"
       << "underdog team, and calculates point differences within the games. You can \n"
       << "also compare the actual brackets to your own predictions! \n";

} // end displayWelcomeMessage()

void menuOptions(int &entrySelection) { // function that displays the menu options 
  
  cout << endl
       << "Select a menu option: \n"
       << "   1. Display overall information about the data \n"  
       << "   2. Display the path of the winning team to the championship \n" 
       << "   3. Determine which region is expected to win the championship based on a \ngiven round \n"
       << "   4. Identify the best underdog within a given round \n"
       << "   5. Find the shoo-in and nail-biting games within a given round, or \noverall \n"
       << "   6. Compare the actual brackets to your predicted brackets \n"
       << "   7. Exit \n"
       << "Your choice --> ";
   cin >> entrySelection;

  if (entrySelection == 7) {  // if statement that checks if the user wants to exit using menu option 7
    
    cout << "Exiting program...";
    exit(0);     // Break out of loop to exit program.
    
  }
  else if (entrySelection > 7) {  // if statement that checks if the user wants to exit using menu option 7
    
    cout << "Invalid value.  Please re-enter a value from the menu options below.\n";
    
  }
}  // end of menuOptions()

class BracketData { // class that holds all of the file data 

  private:
    string region; // intitalizes the region as a string 
    int rank1;  // initializes the rank as an integer 
    string team1; // initializes team1 as a string 
    int score1; // initializes score1 as an integer
    int rank2; // initializes rank2 as an integer
    string team2; // initializes team2 as a string
    int score2; // initializes score2 as an integer
    string winner; // initializes winner as a string
    int roundNum; // initializes roundNum as an integer
    int gameNum; // initializes gameNum as an integer

  public:

    void winnerUtility (vector<BracketData> vecBracketData) {       // utility function 
      cout << "Path to the championship: \n";
    }

    BracketData() { // creates a default constructor and sets the variables to either empty strings or 0 
      region = "";  
      rank1 = 0;
      team1 = "";
      score1 = 0;
      rank2 = 0;
      team2 = "";
      score2 = 0;
      winner = "";
      roundNum = 0;
      gameNum = 0;
    }

      BracketData (string region1, int rank_1, string team_1, int score_1, int rank_2, string team_2, int score_2, string winner_1, int round_Num, int game_Num) : region(region1), rank1(rank_1), team1(team_1), score1(score_1), rank2(rank_2), team2(team_2), score2(score_2), winner(winner_1), roundNum(round_Num), gameNum(game_Num){}
      // default constructor

    string getRegion() {   // getter for the region
      return this -> region;
    }
    int getRank1() {   // getter for rank 1
      return this -> rank1;
    }
    string getTeam1() {   // getter for team 1
      return this -> team1;
    }
    int getScore1() {   // getter for score 1
      return this -> score1;
    }
    int getRank2() {   // getter for rank 2
      return this -> rank2;
    }
    string getTeam2() {   // getter for team 2
      return this -> team2;
    }
    int getScore2() {   // getter for score 2
      return this -> score2;
    }
    string getWinner() {   // getter for the winner
      return this -> winner;
    }
    int getRoundNum() {   // getter for the round number
      return this -> roundNum;
    }
    int getGameNum() {   // getter for the game number
      return this -> gameNum;
    }
    
    void setRegion(string region) {   // setter for the region
      this -> region = region;
    }
    void setRank1(int rank1) {   // setter for rank 1
      this -> rank1 = rank1;
    }
    void setTeam1(string team1) {   // setter for team 1
      this -> team1 = team1;
    }
    void setScore1(int score1) {   // setter for score 1
      this -> score1 = score1;
    }
    void setRank2(int rank2) {   // setter for rank 2
      this -> rank2 = rank2;
    }
    void setTeam2(string team2) {   // setter for team 2
      this -> team2 = team2;
    }
    void setScore2(int score2) {   // setter for score 2
      this -> score2 = score2;
    }
    void setWinner(string winner) {    // setter for the winner
      this -> winner = winner;
    }
    void setRoundNum(int roundNum) {   // setter for the round number
      this -> roundNum = roundNum;
    }
    void setGameNum(int gameNum) {   // setter for the game number
      this -> gameNum = gameNum;
    }

};

void readFile(string csvFileBracket, vector<BracketData>& vecBracketData) { // function to read in file 

  ifstream inStream;   // ifstream to open the file 
  inStream.open(csvFileBracket);  // opens the file depending on the input 
  assert(inStream.fail() == false);
  string headerRow;
  getline(inStream, headerRow); // read in header from file, and ignore

  // read in each line of the file
  while (getline(inStream, headerRow)) {
      stringstream s_stream(headerRow); //create string stream from the string
      BracketData Data;

      // separate the line by commas into each column
      int colNum = 1;
      while (s_stream.good()) {
          string columnVal;
          getline(s_stream, columnVal, ','); //get first string delimited by comma

          // use the substring to fill in the appropriate part of the class
          switch (colNum) {
              case 1:
                Data.setRegion(columnVal);  // sets the region to the column value 
                break;
              case 2:
                if (columnVal != "") { Data.setRank1(stoi(columnVal)) ; }  // sets the rank 1 to the column value 
                  else { Data.setRank1(-1); }   // sets the rank 1 to -1 for the else statement 
                  break;
              case 3:
                Data.setTeam1(columnVal);  // sets the team 1 to the column value 
                break;
              case 4:
                if (columnVal != "") { Data.setScore1(stoi(columnVal)); } // sets the score 1 to column value 
                  else { Data.setScore1(-1); } // sets the score 1 to -1 for the else statement 
                  break;
              case 5:
                if (columnVal != "") { Data.setRank2(stoi(columnVal)); }  // sets the rank 2 to column value 
                  else { Data.setRank2(-1); }   // sets the rank 2 to -1 for the else statement
                  break;
              case 6:
                Data.setTeam2(columnVal);  // sets the team 2 to column value
                break;
              case 7:
                if (columnVal != "") { Data.setScore2(stoi(columnVal)); }  // sets the score 2 to the column value 
                  else { Data.setScore2(-1); }  // sets the score 2 to -1 for the else statement  
                  break;
              case 8:
                Data.setWinner(columnVal);  // sets the winner to column 
                break;
              case 9:
                if (columnVal != "") { Data.setRoundNum(stoi(columnVal)); }  // sets the round number to the column value 
                  else { Data.setRoundNum(-1); }  // sets the round number to -1 for the else statement  
                  break;
              case 10:
                if (columnVal != "") { Data.setGameNum(stoi(columnVal)); }  // sets the game number to the column value 
                  else { Data.setGameNum(-1); }  // sets the game number to -1 for the else statement   
                  break;
      }
      colNum++;  // increments colNum 
    }
    vecBracketData.push_back(Data);  // pushes back Data into the vector vecBracketData
  } 
  
}

void displayInfo(vector<BracketData> &vecBracketData) { // menu option 1
  
  cout << "Total number of games played in tournament: " << vecBracketData.size() << endl;  // gets the total number of games played based on the size of vecBracketData
  cout << "The Final Four contestants are: \n";
  
 for (int i = 0; i < vecBracketData.size(); i++ ) {    // for loop that prints out the winner 
   if (vecBracketData.at(i).getRoundNum() == 4 ) {     // checks if the round number is 4 and then prints out the winner 
     cout << vecBracketData.at(i).getRegion() << " region: " << vecBracketData.at(i).getWinner() << endl;
   }
 }
  
}

void displayWinnerPath(vector<BracketData> &vecBracketData) { // display the winner path (menu option 2)
  
  string winner;
  
  vecBracketData[0].winnerUtility(vecBracketData);
  // cout << "Path to the championship: \n";
  for (int i = 0; i < vecBracketData.size(); i++) {             // for loop that prints the winner 
    if (vecBracketData.at(i).getRegion() == "Championship") {   // only if the region at i yields "Championship"
      winner = vecBracketData.at(i).getWinner();                // sets the winner to the vector element at i 
    }
  }

 

  for (int i = vecBracketData.size(); i > 0; i--) {   // reverse for loop to print out the winner path 
    if (vecBracketData.at(i-1).getWinner() == winner) { // checks if get winner in reverse yields the same winner we got earlier
      cout << "Round " << vecBracketData.at(i-1).getRoundNum() << ", Game " << vecBracketData.at(i-1).getGameNum() << ": " << vecBracketData[i-1].getTeam1() << " vs " << vecBracketData[i-1].getTeam2() << ". Winner: " << vecBracketData[i-1].getWinner() << endl;
    }           // and then prints out the info using getters
  }
  
}

void runThroughRegion(vector<int> &round, int regionStart, int regionEnd ) {
for (int i = regionStart; i < regionEnd;i++){
  round.push_back(i);
}
}

void expectedWinner(vector<BracketData> &vecBracketData) { // menu option 3 TODO
  
  int menuOption3Input;
  vector<BracketData> vecBracketData2;
  string winningRegion;
  int prevIndex = 0;
  int prevRank = 0;
  string regionOne = vecBracketData.at(3).getRegion();
  vector<int> regionOneVecRankIdxs;
  runThroughRegion(regionOneVecRankIdxs, 3, 18 );
  string regionTwo = vecBracketData.at(18).getRegion();
  vector<int> regionTwoVecRankIdxs;
  runThroughRegion(regionTwoVecRankIdxs, 18, 33 );
  string regionThree = vecBracketData.at(33).getRegion();
  vector<int> regionThreeVecRankIdxs;
  runThroughRegion(regionThreeVecRankIdxs, 33, 48 );
  string regionFour = vecBracketData.at(48).getRegion();
  vector<int> regionFourVecRankIdxs;
  runThroughRegion(regionFourVecRankIdxs, 48, 62 );
  int regionOneTotalRound1 = 0;
  int regionTwoTotalRound1 = 0;
  int regionThreeTotalRound1 = 0;
  int regionFourTotalRound1 = 0;
  
  
  cout << "Enter a round to be evaluated: \n";
  cout << "   Select 2 for round 2 \n";
  cout << "   Select 3 for round 3 'Sweet 16' \n";
  cout << "   Select 4 for round 4 'Elite 8' \n";
  cout << "   Select 5 for round 5 'Final 4' \n";
  cout << "Your choice --> ";
  cin >> menuOption3Input;
  cout << "\nAnalyzing round " << menuOption3Input << "... \n\n";
  cout << "The region expected to win is: ";
  
   if (menuOption3Input <= 4 && menuOption3Input  >= 2) { 
       for (int i = 0; i < vecBracketData.size(); i++ ) {
      //start of for loop
     if (vecBracketData.at(i).getRoundNum() == menuOption3Input){
       
       if (vecBracketData.at(i).getRegion() == regionOne){
        if (vecBracketData.at(i).getWinner() ==vecBracketData.at(i).getTeam1())
         regionOneTotalRound1 += vecBracketData.at(i).getRank1();
       else
         regionOneTotalRound1 += vecBracketData.at(i).getRank2();
     }
  
     if (vecBracketData.at(i).getRegion() == regionTwo){
       if (vecBracketData.at(i).getWinner() ==vecBracketData.at(i).getTeam1())
         regionTwoTotalRound1 += vecBracketData.at(i).getRank1();
       else
         regionTwoTotalRound1 += vecBracketData.at(i).getRank2();
     }
     if (vecBracketData.at(i).getRegion() == regionThree){
       if (vecBracketData.at(i).getWinner() ==vecBracketData.at(i).getTeam1())
         regionThreeTotalRound1 += vecBracketData.at(i).getRank1();
       else
         regionThreeTotalRound1 += vecBracketData.at(i).getRank2();
     }
     if (vecBracketData.at(i).getRegion() == regionFour){
       if (vecBracketData.at(i).getWinner() ==vecBracketData.at(i).getTeam1())
         regionFourTotalRound1 += vecBracketData.at(i).getRank1();
       else
         regionFourTotalRound1 += vecBracketData.at(i).getRank2();
     }
       }
       if ((regionOneTotalRound1 <= regionTwoTotalRound1) && (regionOneTotalRound1 <= regionThreeTotalRound1) && (regionOneTotalRound1 <= regionFourTotalRound1))
       {
         winningRegion = regionOne;
       }
       else if ((regionTwoTotalRound1 <= regionOneTotalRound1) && (regionTwoTotalRound1 <= regionThreeTotalRound1) && (regionTwoTotalRound1 <= regionFourTotalRound1)){
        winningRegion = regionTwo;
         }
       
       else if ((regionThreeTotalRound1 <= regionOneTotalRound1) && (regionThreeTotalRound1 <= regionTwoTotalRound1) && (regionThreeTotalRound1 <= regionFourTotalRound1)){
         winningRegion = regionThree;
       }
       else if ((regionFourTotalRound1 <= regionOneTotalRound1) && (regionFourTotalRound1 <= regionTwoTotalRound1) && (regionFourTotalRound1 <= regionThreeTotalRound1)){
         winningRegion = regionFour;
      }
       }
    }
  else if (menuOption3Input == 5){
    int lowestScore = 0;
    string winner;

        lowestScore = (vecBracketData.at(1).getRank1());
        winner = vecBracketData.at(1).getTeam1();
        if(vecBracketData.at(1).getRank2() < lowestScore){
          lowestScore = vecBracketData.at(1).getRank2();
          winner = vecBracketData.at(1).getTeam2() ;   
          }
      if(vecBracketData.at(2).getRank1() < lowestScore){
        lowestScore = (vecBracketData.at(2).getRank1());
        winner = vecBracketData.at(2).getTeam1();
        }
        if(vecBracketData.at(2).getRank2() < lowestScore){
          lowestScore = vecBracketData.at(2).getRank2();
          winner = vecBracketData.at(2).getTeam2() ;      
          }
  
    for(int i = 0; i < vecBracketData.size(); i++)
    if ((vecBracketData.at(i).getRoundNum() == 1) && (vecBracketData.at(i).getWinner() == winner)){
      winningRegion = vecBracketData.at(i).getRegion();
    }
  }

  cout << winningRegion << endl;
  }

void roundUnderdog(vector<BracketData> &vecBracketData) { //  gets the round under dog  (menu option 4)
  
  int menuOption4Input;
  string underdogTeam;
  int underdogRank = 0;
  
  cout << "Enter a round to be evaluated: \n"; 
  cout << "   Select 2 for round 2 \n";  
  cout << "   Select 3 for round 3 'Sweet 16' \n";
  cout << "   Select 4 for round 4 'Elite 8' \n";
  cout << "   Select 5 for round 5 'Final 4' \n";
  cout << "   Select 6 for round 6 'Championship' \n";
  cout << "Your choice --> ";
  cin >> menuOption4Input;    //  asks for the round input 
  for (int i= 0; i < vecBracketData.size(); i++) {
    if (vecBracketData.at(i).getRoundNum() == menuOption4Input) { // for loop that loops throught the vector size and gets round num, rank 1, and team 1
      if (vecBracketData.at(i).getRank1() > underdogRank) {
        underdogRank = vecBracketData.at(i).getRank1();
        underdogTeam = vecBracketData.at(i).getTeam1();
      }
      if (vecBracketData.at(i).getRank2() > underdogRank) {  // for loop that loops throught the vector size and gets round num, rank 1, and team 1
        underdogRank = vecBracketData.at(i).getRank2();
        underdogTeam = vecBracketData.at(i).getTeam2();
      }
    }
  }
  cout << "The best underdog team is " << underdogTeam << " which has rank " << underdogRank << ". \n";
  
}

void nailBiterGame(vector<BracketData> &vecBracketData) {  // menu option 5 DONE 
  
  int menuOption5Input = 0; 
  int menuOption5Score1 = 0;
  int menuOption5Score2 = 0;
  int menuOption5RoundNum = 0;
  int menuOption5GameNum = 0;
  int maxDiff = 0;    // Shoo - in game
  int maxIndex = 0;
  int minIndex = 0;
  int minDiff = 1000; // nail biting 
  int currentDiff = 0;
  
  cout << "Enter a round to be evaluated: \n";
  cout << "   Select 1 for round 1 \n";
  cout << "   Select 2 for round 2 \n";
  cout << "   Select 3 for round 3 'Sweet 16' \n";
  cout << "   Select 4 for round 4 'Elite 8' \n";
  cout << "   Select 5 for round 5 'Final 4' \n";
  cout << "   Select 6 for round 6 'Championship' \n";
  cout << "   Select 7 for the overall tournament \n";
  cout << "Your choice --> ";
  cin >> menuOption5Input;

  if (menuOption5Input > 7) {
    cout << "Invalid value.  Please re-enter a value from the menu options below.\n";
  }
  
  else if (menuOption5Input <= 6) {
  for (int i = 0; i < vecBracketData.size(); i++) {
    if (vecBracketData.at(i).getRoundNum() == menuOption5Input) {
      currentDiff = abs(vecBracketData.at(i).getScore2() - vecBracketData.at(i).getScore1());
      if (currentDiff > maxDiff) {
        maxDiff = currentDiff;
        maxIndex = i;
      }
    }
  }
    for (int i = 0; i < vecBracketData.size(); i++) {
      if (vecBracketData.at(i).getRoundNum() == menuOption5Input) {
        currentDiff = abs(vecBracketData.at(i).getScore2() - vecBracketData.at(i).getScore1());
        if (currentDiff < minDiff) {
          minDiff = currentDiff;
          minIndex = i;
        }
      }
    }
    cout << "Analyzing round " << menuOption5Input << "... \n\n";
    cout << "The shoo-in game was: \n";
    cout << "Round " << menuOption5Input << ", Game " << vecBracketData.at(maxIndex).getGameNum() << ": " << vecBracketData.at(maxIndex).getTeam1() << " vs " << vecBracketData.at(maxIndex).getTeam2() << ". Winner: " << vecBracketData.at(maxIndex).getWinner() << endl;
    cout << "The difference was " << maxDiff << " points. \n\n";
    cout << "The nail-biting game was: \n";
    cout << "Round " << menuOption5Input << ", Game " << vecBracketData.at(minIndex).getGameNum() << ": " << vecBracketData.at(minIndex).getTeam1() << " vs " << vecBracketData.at(minIndex).getTeam2() << ". Winner: " << vecBracketData.at(minIndex).getWinner() << endl;
    cout << "The difference was " << minDiff << " points. \n\n";
    }

  else {
    for (int i = 0; i < vecBracketData.size(); i++) {
    currentDiff = abs(vecBracketData.at(i).getScore2() - vecBracketData.at(i).getScore1());
    if (currentDiff > maxDiff) {
      maxDiff = currentDiff;
      maxIndex = i;
    }
  }
    for (int i = 0; i < vecBracketData.size(); i++) {
      currentDiff = abs(vecBracketData.at(i).getScore2() - vecBracketData.at(i).getScore1());
      if (currentDiff < minDiff) {
        minDiff = currentDiff;
        minIndex = i;
      }
    }
    cout << "Analyzing the overall tournament...\n\n";
    cout << "The shoo-in game was: \n";
    cout << "Round " << vecBracketData.at(maxIndex).getRoundNum() << ", Game " << vecBracketData.at(maxIndex).getGameNum() << ": " << vecBracketData.at(maxIndex).getTeam1() << " vs " << vecBracketData.at(maxIndex).getTeam2() << ". Winner: " << vecBracketData.at(maxIndex).getWinner() << endl;
    cout << "The difference was " << maxDiff << " points. \n\n";
    cout << "The nail-biting game was: \n";
    cout << "Round " << vecBracketData.at(minIndex).getRoundNum() << ", Game " << vecBracketData.at(minIndex).getGameNum() << ": " << vecBracketData.at(minIndex).getTeam1() << " vs " << vecBracketData.at(minIndex).getTeam2() << ". Winner: " << vecBracketData.at(minIndex).getWinner() << endl;
    cout << "The difference was " << minDiff << " points. \n\n";
    }
  
}

void bracketVsPrediction(vector<BracketData> &vecBracketData) { // menu option 6 compares predicitons with the bracket
  
  vector<BracketData> scorePredictions;
  string menuOption6Input;
  int count = 0;
  int score = 0;
  
  cout << "Enter the name of the file with your predicted brackets: \n";
  cin >> menuOption6Input;
  readFile(menuOption6Input, scorePredictions);   // reads in the file 

    for (int i= 0; i < vecBracketData.size(); i++) {                                  // for loop that  gets the winner then 
      if (scorePredictions.at(i).getWinner() == vecBracketData.at(i).getWinner()) {   // increments count after each win 
        count++;
        score += 5*(scorePredictions.at(i).getRoundNum());                            // gets the score by multiplying the round number by 5 
      }
    }
  cout << "\nYou correctly predicted the winner for " << count << " games. \n"; 
  cout << "This means that you have a score of " << score <<". \n";                   // outputs count and score variables 
  if (score >= 250) {
    cout << "Great job! You could consider entering your predictions to win money! \n"; // after calculating them and storing them as variables
  }
  else {
    cout << "You may want to learn more about basketball to improve your predictions next year.";
  }
  
}

int main() { 
  
  displayWelcomeMessage();  // displays the welcome message 
  int entrySelection = 0;

  // Prompt user for the name of the file with the data
  string csvFileBracket;
  string fileName;
  vector<BracketData> vecBracketData;  // creates a vector called vecBracketData
  
  cout << endl
       << "Enter the name of the file with the data for the NCAA tournament: \n";
   cin >> csvFileBracket;              // asks for the csv filename
  
  readFile(csvFileBracket, vecBracketData);  // reads in the file 
  
  while (true) {
    menuOptions(entrySelection);     // calls the menu options
    
    if (entrySelection == 1) {       // if the entry selection is 1, then it calls displayInfo (menu option 1)
      displayInfo(vecBracketData);
      continue;
    }

    else if (entrySelection == 2) {       // if the entry selection is 2, then it calls displayWinnerPath (menu option 2)
      displayWinnerPath(vecBracketData);
      continue;
    }

    else if (entrySelection == 3) {       // if the entry selection is 3, then it calls expectedWinner (menu option 3)
      expectedWinner(vecBracketData);
      continue;
    }

    else if (entrySelection == 4) {       // if the entry selection is 4, then it calls roundUnderdog (menu option 4)
      roundUnderdog(vecBracketData);
      continue;
    }

    else if (entrySelection == 5) {       // if the entry selection is 5, then it calls nailBiterGame (menu option 5)
      nailBiterGame(vecBracketData);
      continue;
    }

    else if (entrySelection == 6) {       // if the entry selection is 6, then it calls bracketVsPrediction (menu option 6)
      bracketVsPrediction(vecBracketData);
      continue;
    }

    else if (entrySelection == 8) {       // if the entry selection is 6, then it calls bracketVsPrediction (menu option 6)
      cout<<"\nTest:\n";
      for (int i = 0; i < vecBracketData.size(); i ++)
        {
          cout<<"Test for " << i << ":" << vecBracketData.at(i).getRegion() << endl;
        }
      continue;
    }
  }
  
}
