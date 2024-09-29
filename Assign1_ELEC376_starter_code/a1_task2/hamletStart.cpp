#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // For ispunct, tolower
#include <sstream> // For stringstream to handle splitting
using namespace std;


int wordOccurrence(ifstream &file, const string &searchingWord, int &totalWords);

//this function will clean each word by removing any punctuation and converting it to lowercase
string cleanWord(const string &word) {

    //creating a string variable for the cleaned version of the word
    string cleanedWord;

    //storing the word length in an int variable
    int len = word.length();
    
    //loopig through each character in the word
    for (int i = 0; i < len; ++i) {

        char ch = word[i];
        
        //this if statement will keep the character if its an alphabetic character/number
        //it will also keep it if its an internal hyphen/apostrphe
        if (isalnum(ch) || (ch == '-' && i > 0 && i < len - 1) || (ch == '\'' && i > 0 && i < len - 1)) {
            
            //if so,we convert it to lowercase and add it to the cleaned up version of the word
            cleanedWord += tolower(ch);
        }
    }

    //this while loop will remove any leading punctuation  
    while (!cleanedWord.empty() && ispunct(cleanedWord.front())) {
        cleanedWord.erase(cleanedWord.begin());
    }
    
    //this while loop will remove the trailing punctuation
    while (!cleanedWord.empty() && ispunct(cleanedWord.back())) {
        cleanedWord.pop_back();
    }

    //after all cleaning operations, we can return the cleaned word now
    return cleanedWord;
}

//this function will count the number of occurences of the searching word in the file
int wordOccurrence(ifstream &file, const string &searchingWord, int &totalWords) {

    //string variable for the searching word
    string word;

    //initializing the occurences to be 0 
    int occurrences = 0;

    //cleaning and normalizing the search word
    string cleanedSearchWord = cleanWord(searchingWord);

    //while there are words to read from the input file
    while (file >> word) {

        //we will clean the word first
        string cleanedWord = cleanWord(word);

        //if the cleaned word contains a hyphen, we will split it and check both parts
        int hyphenPos = cleanedWord.find('-');

        //if the 
        if (hyphenPos != string::npos) {
            
            //since the hyphen is found, the word will be split into two parts
            
            //this is the part of the word before the hyphen
            string firstPart = cleanedWord.substr(0, hyphenPos);

            //this is part of the word after the hyphen
            string secondPart = cleanedWord.substr(hyphenPos + 1);

            //we'll count both parts as individual words (which will lead to the total word count being larger than it should be)
            totalWords += 2;

            //if either of the first part or second part of the word, matches the searched word then...
            if (firstPart == cleanedSearchWord || secondPart == cleanedSearchWord) {

                //the number of occurences will be incremented
                occurrences++;
            }
        } else {

            //if no hyphen is found
            totalWords++;

            //if the cleaned word is the same as the cleaned search word, then...
            if (cleanedWord == cleanedSearchWord) {

                //the number of occurences is incremented
                occurrences++;
            }
        }
    }

    //once all searching is done, the number of occurences is returned
    return occurrences;
}

int main() {

    string word;
    string filePath = "hamlet.txt"; // Hardcoded file name

    cout << "Hi there! This outputs the number of times" << endl
         << "a word appears in Hamlet by William Shakespeare." << endl;
    cout << "Please enter the word to search for:" << endl;
    cin >> word;

    // Opening the file hamlet.txt
    ifstream inFile(filePath);

    // Checking if the file has been properly opened 
    if (!inFile) {
        cerr << "The file hamlet.txt cannot be opened." << endl;
        return 1;
    }

    int totalWords = 0;

    // Finding the number of occurrences by calling the function on the word
    int occurrences = wordOccurrence(inFile, word, totalWords);

    // Closing the file
    inFile.close();

    // Outputting the final message
    cout << totalWords << " words were searched and the word \"" << word << "\" was found " << occurrences << " times." << endl;

    return 0;
}

