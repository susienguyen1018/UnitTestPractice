#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase)
{
  int repetition = 1;
  int index = 0;
  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}

void Password::set(string new_password) {
    if (new_password.length() < 8 || new_password.length() > 20)
        return;

    if (count_leading_characters(new_password) > 3)
        return;

    if (!has_mixed_case(new_password))
        return;

    for (const string& old_password : pass_history) {
        if (old_password == new_password)
            return;
    }
    pass_history.push_back(new_password);
}


bool Password::authenticate(string password) {
    if (pass_history.empty())
        return false; 
    return pass_history.back() == password; 
}

