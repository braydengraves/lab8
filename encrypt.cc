/**
 *   @file: encryption.cc
 * @author: Brayden Graves
 *   @date: 10/20/2023
 *  @brief: Encrypt and Decrypt an input
 * 
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdlib>


using namespace std;

void displayMenu(); // Function that displays the menu
int obtainKey(int key); // Function that allows user to set key
void encrypt(int key); // Encryption Function that allows users to take a file and encrypt it
void decrypt(int key); // Decryption Function that allows users to take a file and decrypt it


int main() {
    int choice;
    int key = 3; // Declaring variables
    do { // Function that displays menu and checks which funtion the user would like to call
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            key = obtainKey(key); // First option that takes them to the Set Key function
        }
        else if (choice == 2) {
            encrypt(key); // Second option that takes them to the Encryption Function
        }
        else if (choice == 3) {
            decrypt(key);  // Third option that takes them to the Deccryption Function
        }
    } while (choice != 4); // Fourth option that exits everything
}

void displayMenu() { // Displays the menu so users can input the number for the type of function they wish to call
    cout << "------------------------------------------------------------ \n";
    cout << "1 = Set Key    2 = Encryption    3 = Decryption    4 = Exit \n";
    cout << "------------------------------------------------------------ \n";
}

int obtainKey(int key){ 
    do { // Makes sure the value the user inputs is between 1 and 10
        cout << "Please Enter Key Value between 1 - 10 \n";
        cin >> key;
    }while (!(key > 0 && key < 11));
    return key; // Returns the key value
}


void encrypt(int key) { // Encryption Function
    char c;
    string text;
    string eoutput_file;
    string einput_file;  // Defining variables
    cout << "Please Enter The Input File Name \n";
    cin >> einput_file;
    cout << "\nPlease Enter The Output File Name \n";
    cin >> eoutput_file; // Inputting file names
    
    ifstream ins; // Sets ins to ifstream
    ins.open(einput_file); // opens up the input text file
    while (ins.get(c)){ // takes all of the users inputs and takes each character and adds it to the key and then adds it to the text
        c += key;
        text += c;    
    }
    ins.close(); // closes the text file

    ofstream ons; // Sets ons to ofstream
    ons.open(eoutput_file); // Opens the output text file
    ons << text; // inserts the text that was encrypted into the file
    ons.close(); // closes the file

}

void decrypt(int key){
    char c;
    string text;
    string doutput_file;
    string dinput_file; // Defining variables
    cout << "Please Enter The Input File Name \n";
    cin >> dinput_file;
    cout << "\nPlease Enter The Output File Name \n";
    cin >> doutput_file; // Inputting file names
    
    ifstream ins; // Sets ins to ifstream
    ins.open(dinput_file);// opens up the input text file
    while (ins.get(c)){ // takes all of the users inputs and takes each character and subtracts it from the key and then adds it to the text
        c -= key;
        text += c;    
    }
    ins.close(); // closes the text file

    ofstream ons; // Sets ons to ofstream
    ons.open(doutput_file); // Opens the output text file
    ons << text; // inserts the text that was encrypted into the file
    ons.close(); // closes the text file
}