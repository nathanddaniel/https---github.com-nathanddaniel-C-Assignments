#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//function that calculates the score for each employee
int calculateScore(const string &answerKey, const string &response) {

    //if the employee's reponse length isn't equal to the answer key then their response is incomplete
    if (response.length() != answerKey.length()) {
        
        //we'll return -1 since its imcomplete
        return -1;
    }

    //initialize their score as 0 before we start checking
    int score = 0;

    //looping through each letter in each employee response
    for (int i = 0; i < answerKey.length(); i++) {

        //if each letter is correct, increment the employee's score
        if (response[i] == answerKey[i]) {
            score++;
        }
    }

    //return the employee total score
    return score;
}

//function that calculates the average score
double calculateAverage(int totalScore, int validScores) {
    double average;
    
    if (validScores > 0) {
        average = totalScore / validScores;
    } 
    else {
        average = 0;
    }
    return average;
}

int main() {

    //opening the input file
    ifstream inputFile("QuizResponses.txt"); 

    //opening the output file where the table will be written
    ofstream outputFile("QuizResults.txt");   

    //checking if either of the files were successfully opened
    if (!inputFile) {
        cerr << "Error: Unable to open input file 'QuizResponses.txt'." << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error: Unable to open output file 'QuizResults.txt'." << endl;
        return 1;
    }

    //string variable to contain the answer key that will be used to check for correctness
    string answerKey;

    //reading the answer key from the first line
    getline(inputFile, answerKey); 

    //variables for line, employee ID and their corresponding response
    string line;
    string employeeID;
    string response;

    //initializing values for total score, number of valid scores, and line number for the table
    int totalScore = 0;
    int validScores = 0;
    int lineNumber = 1;

    //creating the title for the table in the output file
    outputFile << setw(30) << "Employee Quiz Responses" << endl;

    //creating the column headers for Employee ID, Score, and Redo Quiz
    outputFile << left << setw(15) << "Employee ID" << setw(8) << "Score" << setw(12) << "Redo Quiz" << endl;

    //creating the dashed line seprator 
    outputFile << string(40, '-') << endl;

    //read each line from the file and determine if it's an ID or response
    while (getline(inputFile, line)) {
        
        //if the line is empty, we'll skill 
        if (line.empty()) {
            continue;  
        }

        // checking if an employee ID or response is needed
        if (employeeID.empty()) {

            //setting the line as employee ID
            employeeID = line;  
        } else {

            //setting this line as the response
            response = line;  

            //calculating the score based on employee response
            int score = calculateScore(answerKey, response);

            //string which determines whether employee has to retake the quiz
            string redoQuiz;

            //if employee score is less than three OR is incomplete, then the employee will have to redo the quiz
            if (score < 3 || score == -1) {
                redoQuiz = "yes";
            } 

            //otherwise, they dont have to retake
            else {
                redoQuiz = "no";
            }

            //outputting the results with line numbers, employee ID, score, and redo quiz value
            outputFile << left << lineNumber << " " << setw(15) << employeeID << setw(8) << score << setw(12) << redoQuiz << endl;

            //if the employee response isn't incomplete, we will add their score to total scores
            if (score != -1) {
                totalScore += score;
                validScores++;
            }

            //incrementing the line number for the next employee
            lineNumber++;

            //we will reset these values for the next employee
            employeeID.clear();
            response.clear();
        }
    }

    //once all the employees values are added, we will create a dashed line seperator
    outputFile << string(40, '-') << endl;  

    //calculating and printing the average score for all employees
    double average = calculateAverage(totalScore, validScores);

    outputFile << left << setw(10) << "Average" << right << setw(8) << fixed << setprecision(2) << average << endl;

    //closing both input and output files
    inputFile.close();  
    outputFile.close();  

    return 0; 
}