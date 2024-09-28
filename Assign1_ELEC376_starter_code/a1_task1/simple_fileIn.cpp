
// including the standard input and output stream library for using cin, cout, cerr 
#include <iostream>

// including the file stream library that allows us to read from and write to files
#include <fstream>

// includes the string lirbary to use string data types
#include <string>

// allows us to use standard library functions without prefixing them with std::
using namespace std;


//the main function
int main() {

   //creating a input file stream object called inData, this will read from a file
   ifstream inData;

   //creating an output file stream object called outData, this will write to a file
   ofstream outData;

   //creating two string variables called inVar1 and inVar2
   string inVar1;
   string inVar2;


   //cout is used to essentially print text to the output, and endl is like an operator that pressed "enter"
   //we're outputting two lines of text, hence the two endl
   cout << endl << "This program reads from an input file, file_input.txt,"
	<< endl << " and writes to an output file, file_output.txt" << endl;

   //we're opening the file "input.txt" for reading (basically like storing it within the ifstream inData)
   inData.open("input.txt");

   //if the input file has failed to open then, we will
   if (!inData) {

      //print an error message with the standard error stream
      cerr << "** Problem: cannot open file_input.txt, ending program."
      << endl;

      //we return with a non-zero exit code, meaning that an error has happened
      return 1;
   }

   //we will open a file called "output.txt" which is meant for writing to
   outData.open("output.txt");
   
   //if we can't properly open the file, then 
   if (!outData) {

      //we will print an error message using the standard error file stream
      cerr << "** Problem: cannot open file_output.txt, ending program."
	   << endl;
      return 1;
   }

   //this will read two strings (the first two strings to be exact) from the input file into our two strings we declared earlier
   inData >> inVar1 >> inVar2;

   //while the input file is in a "good state", which means no errors or that we've reached the end of the file
   while (inData){

      //We will write the second string to the output file
      outData << inVar2;

      //we will write a space after the second string has been typed
      outData << " ";

      //we will then write the first string now to the output file
      outData << inVar1;     

      //then we print out a new line in the output file
      outData << endl;     

      //we will read the next two strings from the input file
      inData >> inVar1 >> inVar2;

   } // end while
    
   //we will close the input file to release resources
   inData.close();

   //we will then close the output file to release resources as well
   outData.close();

} // end main