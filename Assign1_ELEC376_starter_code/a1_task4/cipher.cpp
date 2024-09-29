// Substitution Cipher

#include <iostream>
#include <string>
using namespace std;

//encrypting function
string userEncrypt(const string& message, const string& alphabet, const string& key) {

    //string that contains the encrypted message
    string encryptedMessage;

    //looping through all the characters in the message
    for (char c : message) {

        //finding the index of the current char in the alphabet list
        int i = alphabet.find(c); 
        

        //if the current index actually has a position, then it can be encrypted
        if (i != string::npos) {

            //adding the encrypted key to the message at the index
            encryptedMessage += key[i];
        } 
        
        else {

            //if it can't be found, then its probably a space or something, so we leave it
            encryptedMessage += c;
        }
    }

    //returning the message
    return encryptedMessage;
}

//decrypting the user message function
string userDecrypt(const string& encrypted_message, const string& alphabet, const string& key) {
    
    //string that contains the dencrypted message
    string decryptedMessage;

    //looping through all the characters in the message
    for (char c : encrypted_message) {

        //finding the index of the current char in the key list
        int i = key.find(c); 

        //if the current index actually has a position, then it can be decrypted
        if (i != string::npos) {
            
            //adding the decrypted key to the message at the index
            decryptedMessage += alphabet[i];
        } 
        
        else {
            
            //if it can't be found, then its probably a space or something (like last time)
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};


    //asking the user to enter their message
    string message;
    cout << "Enter your message to encrypt: ";
    getline(cin, message);

    //encrypting the users message
    string encryptedMessage = userEncrypt(message, alphabet, key);
    cout << "The encrypted message is: " << encryptedMessage << endl;

    //decrypting the message
    string decryptedMessage = userDecrypt(encryptedMessage, alphabet, key);

    //outputting the decrypted mesage
    cout << "The decrypted message is: " << decryptedMessage << endl;

    return 0;

}
