#include <iostream>

// Checks that all characters in a string are letters and ensures
// there are no spaces present
bool stringIsWord(std::string input) {
  for (int index = 0; index < input.size(); index++) {
    if (!isalpha(input[index]) || isspace(input[index])) {
      return false;
    }
  }
  return true;
}

// Gets a single word from the user
std::string wordInput() {
  std::string input;
  std::getline(std::cin, input);
  while (!stringIsWord(input)) {
    std::cout << "Invalid word. Please enter a single word without spaces:\n";
    std::getline(std::cin, input);
  }
  return input;
}

// Reverses a string eg. Hello becomes olleH
std::string reverse(std::string word) {
  std::string returnString = "";
  for (int index = word.size() - 1; index > -1; index--) {
    returnString += word[index];
  }
  return returnString;
}

// Converts a string to lowercase eg. HeLLo becomes hello
std::string lower(std::string word) {
  std::string returnString = "";
  for (int index = 0; index < word.size(); index++) {
    returnString += tolower(word[index]);
  }
  return returnString;
}

int main() {
  std::cout << "Please enter a word: ";
  std::string word = wordInput();
  if (reverse(lower(word)) == lower(word)) {
    std::cout << "Yes, '" << word << "' is a palindrome";
  } else {
    std::cout << "Sorry, '" << word << "' is not a palindrome.";
  }
}
