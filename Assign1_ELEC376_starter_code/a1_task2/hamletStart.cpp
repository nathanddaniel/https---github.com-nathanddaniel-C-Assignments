/* The program allows users to find and report the frequency 
 * of a specific word within the text of "Hamlet." 
 * The program prompts the user to enter a word, 
 * reads the text from the "hamlet.txt" file, and searches
 * for occurrences of the word within the words of the text. 
 * It then displays the total number of words searched and the count 
 * of how many times the word was found within those words. */

#include <iostream>
#include <fstream>
using namespace std; 

//function protoype here
int wordOccurrence(ifstream &file, const string &searchingWord, int &totalWords);

int main() {
    string word{};
    cout << endl;
    cout << "Hi there! this outputs the number of times" << endl
         << "a word appears in Hamlet by William Shakespeare" << endl;
    cout << endl;
    cout << "Please enter the word to search for:" << endl;
    cin >> word;

    //opening the file
    ifstream inFile("hamlet.txt");

    //checks if the file has been successfully opened
    if (!inFile) {
        cerr << "The file cannot be opened properly." << endl;
        return 1;
    }

    int totalWords = 0;

    //calling the function that finds the word provided by the user
    int occurrences = wordOccurrence(inFile, word, totalWords);

    //closing the file
    inFile.close();

    //outputting the final message just like how it is displayed in the assignment
    cout << totalWords << " words were searched and the word \"" << word << "\" was found " << occurrences << " times." << endl;

    return 0;
}

//function to convert a character to lowercase
char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {

        //converts uppercase letters to lowercase
        return ch + 32;
    }
    return ch;
}

//function to remove punctuation from a word
string removePunctuation(const string &word) {

    //passing in the string as input and created a new empty string
    string newWord;

    //for loop that loops through each character in the string
    for (char ch : word) {

        //if the character is not a punctionation mark, add it to the string
        if (!ispunct(ch)) {
            newWord += ch;
        }
    }

    //we will reutrn a clean up word minus all punctuation
    return newWord;
}

//function that converts a string to all lowercase
string toLowerCaseWord(const string &str) {

    //passing in the string
    string lowerStr;
    
    //for each charatcter in the string, covert each character to lowercase using the lowercase function
    for (char ch : str) {
        lowerStr += toLowerCase(ch);
    }

    return lowerStr;
}

//this function will count the # of occureneces of a word in the file
int wordOccurrence(ifstream &file, const string &searchingWord, int &totalWords) {
    string word;
    int occurrences = 0;

    //converting the search word to lowercase for case-sensitive comparisons
    string lowerCaseSearchWord = toLowerCaseWord(searchingWord);

    //while loop while there are strings left in the input file to read
    while (file >> word) {
        
        //converting the word currently being looked at to lower case
        string lowerCaseWord = toLowerCaseWord(word);

        //removing the punctuation from the word to accurately match
        lowerCaseWord = removePunctuation(lowerCaseWord);

        totalWords++;

        //checking if the current word matches the search word
        if (lowerCaseWord == lowerCaseSearchWord) {

            //if it matches, increment the # of occurrences 
            occurrences++;
        }
    }

    //returning the # of occurences now that the entire file has been parsed through
    return occurrences;
}
