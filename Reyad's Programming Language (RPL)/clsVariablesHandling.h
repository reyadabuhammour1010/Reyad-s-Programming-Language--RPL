#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class clsVariablesHandling 
{

    vector <string>& _vCodeWords;


    struct Variable {
        string Name;
        int Value;
    };

    vector <Variable> Variables;

   

public:

    clsVariablesHandling( vector<string>& codeWords)
        : _vCodeWords(codeWords) { }
    

    int GetValueOfVariable(string Name) {

        for (Variable& c : Variables) {
            if (c.Name == Name)
                return c.Value;
        }
        cout << "Error: Variable " << Name << " not found\n";
        return 0;
    }

    bool isNumber(string& s) {
        for (char& c : s)
            if (!isdigit(c)) return false;
        return true;
    }


    bool IsVariableExist(string Name) {


        for (Variable& v : Variables) {
            if (v.Name == Name)
                return true;
        }
        return false;
    }


    bool IsVariableNameValid(string Name) {

        //Check if First Thing in variable is NOT number

        if (isdigit(Name[0]))
            return false;

        if (Name == "End" || Name == "Int" || Name == "Loop" ||
            Name == "to" || Name == "Op" || Name == "Print")
            return false;

        for (char& c : Name) 
            if (c == '-' || c == ' ' || c == '!' || c == '(' || c == ')' || c == '{' || c == '}' || c == '['
                || c == ']' || c == '\'' || c == '\"' || c == '&' || c == '*' || c == '^' || c == '%' ||
                c == '$' || c == '#' || c == '@' || c == '~' || c == '/' || c == '+' || c == '`' ||
                c == '?' || c == '>' || c == '<') 
                return false;
            

        return true;
    }


    void StoreTheVariable(int i) {
        Variable a;

        a.Name = _vCodeWords[i + 1];

        if (isNumber(_vCodeWords[i + 3])) {

            a.Value = stoi(_vCodeWords[i + 3]);
            Variables.push_back(a);
        }
        else {
            cout << "\n\nSyntax Error : An Integral Value required\n\n";
            return;
        }

    }


    bool VariableSyntaxValidation(int index) {

        if (index + 3 >= _vCodeWords.size()) {
            cout << "\nSyntax Error : Incomplete variable decleration.\n";
            return false;
        }

        if (_vCodeWords[index + 2] != "=") {
            cout << "\nSyntax Error : Expected '=' after variable name\n";
            return false;
        }

        if (!IsVariableNameValid(_vCodeWords[index + 1])) {
            cout << "\nSyntax Error : variable name : "
                << _vCodeWords[index + 1] << " does not conform to the variable naming rules.\n";
            return false;
        }

        if (IsVariableExist(_vCodeWords[index + 1])) {

            cout << "\nSyntax Error : variable with name : " << _vCodeWords[index + 1] << " exist.\n";
            return false;

        }

        StoreTheVariable(index);

        return true;
    }
    

    bool AnalyzingVariables(int& i) {

        if (_vCodeWords[i] == "Int") {
            if (!VariableSyntaxValidation(i))
                return false;
        }
        return true;
    }

 
    void ExcuteTheCode() {


        for (int i = 0; i < _vCodeWords.size(); i++) {


            if (i >= _vCodeWords.size()) {
                cout << "\nAn Error Occured, there is no statements in your code.\n";
                break;
            }


            if (!AnalyzingVariables(i)) {
                break;
            }

            


        }


    }




};


