#include <iostream> // Includes the standard input/output stream library for using cin, cout, cerr, etc.
#include <fstream>  // Includes the file stream library for reading from and writing to files.
#include <string>   // Includes the string library to use string data types.

using namespace std; // Allows usage of standard library functions without prefixing them with "std::".

int main() { // Main function, the entry point of the program.

    ifstream inData;  // Declares an input file stream object named 'inData' for reading from a file.
    ofstream outData; // Declares an output file stream object named 'outData' for writing to a file.

    string inVar1; // Declares a string variable 'inVar1' to store the first word read from the input file.
    string inVar2; // Declares a string variable 'inVar2' to store the second word read from the input file.

    cout << endl << "This program reads from an input file, file_input.txt," 
         << endl << " and writes to an output file, file_output.txt" << endl;
    // Prints a message to the console explaining what the program does.

    inData.open("input.txt"); // Opens the file named "input.txt" for reading.
    if (!inData) { // Checks if the file "input.txt" failed to open.
        cerr << "** Problem: cannot open file_input.txt, ending program." << endl;
        // If the file cannot be opened, an error message is printed to the standard error stream.
        return 1; // Ends the program with a non-zero exit code, indicating an error occurred.
    }

    outData.open("output.txt"); // Opens the file named "output.txt" for writing.
    if (!outData) { // Checks if the file "output.txt" failed to open.
        cerr << "** Problem: cannot open file_output.txt, ending program." << endl;
        // If the file cannot be opened, an error message is printed to the standard error stream.
        return 1; // Ends the program with a non-zero exit code, indicating an error occurred.
    }

    inData >> inVar1 >> inVar2; // Reads two strings from the input file into 'inVar1' and 'inVar2'.

    while (inData) { // Loops while the input stream is in a good state (no errors or end-of-file).
        outData << inVar2; // Writes the second string (inVar2) to the output file.
        outData << " "; // Writes a space after inVar2.
        outData << inVar1; // Writes the first string (inVar1) to the output file.
        outData << endl; // Inserts a newline in the output file.

        inData >> inVar1 >> inVar2; // Reads the next two strings from the input file.
    } // End of the while loop.

    inData.close(); // Closes the input file to release resources.
    outData.close(); // Closes the output file to release resources.

} // End of the main function.