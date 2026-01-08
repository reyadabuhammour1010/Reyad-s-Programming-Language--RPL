#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "clsVariablesHandling.h"
using namespace std;


class clsPrintHandling 
{

    vector <string> &_vCodeWords;

    clsVariablesHandling &vars;




public: 

    clsPrintHandling(vector <string> &codeWords, clsVariablesHandling& _var) : _vCodeWords(codeWords),
        vars(_var){

    }

    int GetVariableValue(string Name) {

        return vars.GetValueOfVariable(Name);
    }


    int OperationResult(int num1, int num2, char operation) {

        switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;

        }
        return 0;
    }



    void PrintHandling(int i) {

        if (i + 1 >= _vCodeWords.size()) {
            cout << "\nSyntax Error: Print statement incomplete\n";
            return;
        }

        string PrintedStatement = "";

        PrintedStatement = _vCodeWords[i + 1];

        if (vars.IsVariableExist(PrintedStatement)) {
            PrintedStatement = to_string(GetVariableValue(_vCodeWords[i + 1]));
            cout << PrintedStatement << endl;
        }

        else {
            cout << PrintedStatement << endl;
        }
    }


    void PrintOperationHandling(int i) {

        if (i + 4 >= _vCodeWords.size()) {
            cout << "\nSyntax Error: Not enough arguments for operation\n";
            return;
        }

        int num1 = 0, num2 = 0;
        char operation = '+';

        char op = _vCodeWords[i + 3][0];

        if (op != '+' && op != '-' && op != '/' && op != '*') {
            cout << "\n\nAn Error Occured : Invalid Operation\n\n";
            return;
        }



        if (vars.IsVariableExist(_vCodeWords[i + 2]) && vars.IsVariableExist(_vCodeWords[i + 4])) {

            int FirstNumber = GetVariableValue(_vCodeWords[i + 2]);
            int LastNumber = GetVariableValue(_vCodeWords[i + 4]);

            if (!((_vCodeWords[i + 3][0] == '/') && (stoi(_vCodeWords[i + 4]) == 0)))
                cout << OperationResult(FirstNumber, LastNumber,
                    _vCodeWords[i + 3][0]) << endl;

            else
                cout << "\nAn Error Occured : Cannot Divide on Zero\n\n";
        }

        else if (vars.IsVariableExist(_vCodeWords[i + 2]) && vars.isNumber(_vCodeWords[i + 4])) {

            int FirstNumber = GetVariableValue(_vCodeWords[i + 2]);

            if (!((_vCodeWords[i + 3][0] == '/') && (stoi(_vCodeWords[i + 4]) == 0)))
                cout << OperationResult(FirstNumber, stoi(_vCodeWords[i + 4]),
                    _vCodeWords[i + 3][0]) << endl;

            else
                cout << "\nAn Error Occured : Cannot Divide on Zero\n\n";
        }

        else if ((vars.isNumber(_vCodeWords[i + 2])) && vars.IsVariableExist(_vCodeWords[i + 4])) {

            int LastNumber = GetVariableValue(_vCodeWords[i + 4]);

            if (!((_vCodeWords[i + 3][0] == '/') && (stoi(_vCodeWords[i + 4]) == 0)))
                cout << OperationResult(stoi(_vCodeWords[i + 2]), LastNumber,
                    _vCodeWords[i + 3][0]) << endl;

            else
                cout << "\nAn Error Occured : Cannot Divide on Zero\n\n";
        }

        else if ((vars.isNumber(_vCodeWords[i + 2]) && vars.isNumber(_vCodeWords[i + 4]))) {

            if (!((_vCodeWords[i + 3][0] == '/') && (stoi(_vCodeWords[i + 4]) == 0)))
                cout << OperationResult(stoi(_vCodeWords[i + 2]), stoi(_vCodeWords[i + 4]),
                    _vCodeWords[i + 3][0]) << endl;

            else
                cout << "\nAn Error Occured : Cannot Divide on Zero\n\n";
        }

        else
            cout << "\nAn Error Occured : This mathematical operation cannot be performed without numerical values," <<
            "Or, This mathematical operation has more than 2 numeric values.\n\n";
    }



    void ExcuteTheCode() {


        for (int i = 0; i < _vCodeWords.size(); i++) {

            if (i >= _vCodeWords.size()) {
                cout << "\nAn Error Occured, there is no statements in your code.\n";
                break;
            }


            if (_vCodeWords[i] == "Print" && _vCodeWords[i + 1] != "Op") {

                PrintHandling(i);
            }

            if (_vCodeWords[i] == "Print" && _vCodeWords[i + 1] == "Op") {
                PrintOperationHandling(i);
            }


        }


    }




};

