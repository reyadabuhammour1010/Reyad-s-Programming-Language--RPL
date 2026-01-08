#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class clsReadAndSplitCode
{
    string _Code;
    string _FirstLine;
    vector <string> _vCodeWords;

public :

    string Code() {
        return _Code;
    }

    vector <string> CodeWords() {
        return _vCodeWords;
    }

   

    //get the code from user as one line and return it to store

     string ReadCode() {

         cout << "==============================================================================\n";
         cout << "\t\tWelcome To \"Reyad's Programming Language (RPL)\" \n";
         cout << "==============================================================================\n";
         cout << "\nEnter your Code Here : \n";
         cout << "ATTENTION: This Enviroment is in BETA mode, so, you can Expect Errors!\n\n";
         cout << "==============================================================================\n";

         _Code.clear();

         string Line = "";
        
        while (true) {

            getline(cin, Line);

            if (Line != "End") {
                _Code += Line + " ";
            }

            else
                break;
        }


        return _Code;
        
    }

     //split the user code from one line to many words and store every code in the vector 
     vector <string>& GetCodeWords() {
         string Word = "";
         
         _vCodeWords.clear();

         for (char& c : _Code) {
             if (c != ' ')
                 Word += c;
             else {
                 if (!Word.empty())
                     _vCodeWords.push_back(Word);
                 Word = "";
             }
         }
         if (!Word.empty()) _vCodeWords.push_back(Word);
         return _vCodeWords;
     }


};

