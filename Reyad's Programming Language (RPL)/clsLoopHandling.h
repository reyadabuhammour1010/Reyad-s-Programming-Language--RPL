#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class clsLoopHandling
{

    vector <string> &CodeWords;

public : 

    clsLoopHandling(vector <string>& codeWords) : CodeWords(codeWords){}


    bool isNumber(string& s) {
        for (char& c : s)
            if (!isdigit(c)) return false;
        return true;
    }


    void LoopHandling(int i) {

        if (i + 3 >= CodeWords.size()) {
            cout << "\nSyntax Error: Incomplete Loop statement\n";
            return;
        }

        int start, end;

        if (CodeWords[i + 2] == "to") {

            if (isNumber(CodeWords[i + 1]))
                start = stoi(CodeWords[i + 1]);

            else {
                cout << "\n\nSyntax Error : Defining the loop in the code was done incorrectly.\n\n";
                return;
            }

            if (isNumber(CodeWords[i + 3]))
                end = stoi(CodeWords[i + 3]);
            else {
                cout << "\n\nSyntax Error : missing an integral value, Loop requires numeric start and end\n\n";
                return;
            }

            if (start > end) {
                cout << "\n\nAn Error Occured : The Final Number cant be greater than First Number\n\n";
                return;
            }
            for (int j = start; j <= end; j++) {
                cout << j << endl;
            }
        }
        else {
            cout << "\n\nSyntax Error : Loop without \"to\"\n\n";
            
        }
    }

    void ExcuteTheCode() {


        for (int i = 0; i < CodeWords.size(); i++) {

            if (i >= CodeWords.size()) {
                cout << "\nAn Error Occured, there is no statements in your code.\n";
                break;
            }


            if (CodeWords[i] == "Loop") {
                LoopHandling(i);
                i += 4;
            }

        }


    }




};

