#include <iostream>
#include <string>
#include <regex>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;

regex regx("[@#&*]");

// define input file object
ifstream myfile;
ofstream results;

// function to write results in a file
void writeResults(string);

int main(){

    // delete the results file if exist to have the result of the program one at at time per program run
    if (remove("results.txt") == 0) cout << "results file deleted successfully :)" << endl;
    else cout << "results file couldn't be deleted, the file not exist!" << endl;

    int tstCasesNo, pwLen = 0;
    string pw, specialChar = "@#&*";
    // set a new starting point for rand() function to generate a new sequence of numbers every time the program runs
    srand(time(0));
    // conditions
    bool lengthGreaterThan7 = false, upperCaseExist = false, lowerCaseExist = false, digitsExist = false, specialCharExist = false;
    // read the number of testcases

    myfile.open("testCase.txt");
    string cases;
    if (myfile.is_open()){
        getline(myfile, cases);

        //cin >> tstCasesNo;
        // read the test cases
        tstCasesNo = stoi(cases);

        for(int tstNo = 0; tstNo < tstCasesNo; tstNo++){
            string pwLength;
            getline(myfile, pwLength);
            getline(myfile, pw);
            pwLen = stoi(pwLength);
            // check for the password constraints
            (pwLen == 7? lengthGreaterThan7 = true : lengthGreaterThan7 = false);
            (regex_search(pw, regx) != 0? specialCharExist = true : specialCharExist = false);
            for (int i = 0; i < pw.length(); i++){
                (isupper(i)? upperCaseExist = true : upperCaseExist = false);
                (islower(i)? lowerCaseExist = true : lowerCaseExist = false);
                (isdigit(i)? digitsExist = true : digitsExist = false);
            }
            // if the pw meets the constraints then prin it
            if (lengthGreaterThan7 && upperCaseExist && lowerCaseExist && digitsExist && specialCharExist)
                writeResults("Case: #" + to_string(tstNo) + " " + pw);
                //cout << ("Case: #" + to_string(tstNo) + pw) << endl;
            // if not, optimize it
            else{
                //newPw = oldPw;
                // Add random upper case char
                if (upperCaseExist == false) {pw += 'A' + rand() % 26; upperCaseExist = true;}
                if (lowerCaseExist == false) {pw += 'a' + rand() % 26; lowerCaseExist = true;}
                if (specialCharExist == false) {pw += specialChar[rand() % 3]; digitsExist = true;}
                if (digitsExist == false) {pw += rand() % 10; digitsExist = true;}
                while(pwLen < 7){
                    pw += pw[0];
                    pwLen = pw.length();
                }
            }

            writeResults("Case: #" + to_string(tstNo) + " " + pw);
            //cout << ("Case: #" + to_string(tstNo) + pw) << endl;
        }

        myfile.close();


    }else{
        cout << "File Couldn't be open" << endl;
    }




    return 0;
}

void writeResults(string res){
    // open the File

    results.open("results.txt", fstream::app);
    if (results.is_open()){

        results << res << endl;

        results.close();

    }else{

        cout << "Results file couldn't be open!";
    }
}
