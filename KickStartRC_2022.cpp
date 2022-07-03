#include <iostream>
#include <string>
#include <regex>
#include <cstring>
#include <ctime>


using namespace std;

regex regx("[@#&*]");


int main(){

    int tstCasesNo, pwLen = 0;
    string pw, specialChar = "@#&*";
    // set a new starting point for rand() function to generate a new sequence of numbers every time the program runs
    srand(time(0));
    // conditions
    bool lengthGreaterThan7 = false, upperCaseExist = false, lowerCaseExist = false, digitsExist = false, specialCharExist = false;
    // read the number of testcases
    cin >> tstCasesNo;
    // read the test cases
    for(int tstNo = 0; tstNo < tstCasesNo; tstNo++){
        cin >> pwLen;
        cin >> pw;
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
            cout << ("Case: #" + to_string(tstNo) + pw) << endl;
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

        cout << ("Case: #" + to_string(tstNo) + pw) << endl;
    }

    return 0;
}
