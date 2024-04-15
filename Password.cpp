#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string word) {
    bool has_upper = false;
    bool has_lower = false;

    for (char c : word) {
        if (isupper(c)) {
            has_upper = true;
        }
        if (islower(c)) {
            has_lower = true;
        }
        // If both conditions are met, no need to continue checking
        if (has_upper && has_lower) {
            return true;
        }
    }

    return false;  // Return false if not both uppercase and lowercase are found
}


