/* 
 * Last Edited: 4/30/2024
 * This program creates a palindrome detector. The user inserts a phrase, and the program outputs whether it is a palindrome or not
 * Only numbers and letters are checked when determining if a phrase is a palindrome
*/ 

#include <iostream>
#include <cstring>

using namespace std;

//function prototype
bool palindrome(int inputLength, int strCount, int str2Count, char input[], char str[], char str2[]); 

int main()
{
  //collection type: array, strings do not exist in C++ so we must use arrays of characters
  //initialize variables and all arrays to hold 81 characters (need space for 80 and null character) 
  char input[81];
  char str[81];
  char str2[81];
  
  char running = 'y';
  
  //runs until user wants to quit (running is not equal to y)
  while(running == 'y'){

    bool notValid = true; //reset variable
    
    //go through all arrays and set all characters to null character to clear memory
    for (int i = 0; i < 81; i++){
      input[i] = '\0';
      str[i] = '\0';
      str2[i] = '\0';
    }

    cout << "This is a Palindrome Detector" << endl;
    cout << "Please enter a word or phrase that is to be checked: " << endl;
    cout << endl;

    //user input, reads into the collection type (array)
    //gets up to 81 characters from input and puts them in an array
    cin.get(input, 81);
    cin.get();
    int inputLength = strlen(input) - 1; //length of user inputted phrase
    int strCount = 0;
    int str2Count = 0;

    cout << endl;

    //method call, if returns true we have a palindrome
    if (palindrome(inputLength, strCount, str2Count, input, str, str2) == true){
      cout << "THIS IS A PALINDROME!" << endl;
    
    }
    //if true was not returned, false was returned and it is not a palindrome
    else {
      cout << "THIS IS NOT A PALINDROME!" << endl; 
    }
    cout << endl;
    cout << "Would you like to enter another word or phrase?" << endl;

    //while loop that asks if user wants to enter another phrase
    while(notValid == true){
      cout << "(y)es or (n)o? ";
      cout << "(Please only enter one character)" << endl;
      //gets user input
      cin.get(running);
      cin.get();
      //if the input was 'y', this is valid and palindrome will run again
      if(running == 'y'){
	notValid = false;
	cout << endl;
      }
      //if the input was 'n', this is valid but palindrome will end
      else if(running == 'n'){
	notValid = false;
	cout << "Goodbye..." << endl;
      }
      //otherwise, the input was not valid and the user must enter a valid character
      else{
	cout << endl;
	cout << "Please enter either y or n." << endl;
      }
    }
  }
}

//palindrome function/method/procedure, checks if the user inputted word or phrase is a palindrome
bool palindrome(int inputLength, int strCount, int str2Count, char input[], char str[], char str2[]){

  //iterates through input array, converts to lowercase and removes punctuation and adds to new array
  for (int i = 0; i < inputLength + 1; i++){ 
    if(isalpha(input[i]) || isdigit(input[i])){
      str[strCount] = tolower(input[i]);
      strCount++;
    }
  }

  //iterate backwards through the array with no punctuation and adds the elements to new array (this new array is the reverse of the original) 
  for (int i = inputLength; i > -1; i--){
    if(isalpha(str[i]) || isdigit(str[i])){
      str2[str2Count] = str[i];
      str2Count++;
    }
  }
  
  //add null character to both arrays
  str2[str2Count] = '\0';
  str[strCount] = '\0';

  //when compared, if the value of strcmp is 0 they are the same, if the value is not 0, they are different
  if(strcmp(str, str2) == 0){  
    return true; //palindrome
  }
  else {
    return false; //not a palindrome
  }
}
