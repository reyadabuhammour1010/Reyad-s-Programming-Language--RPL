#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "clsVariablesHandling.h"
#include "clsPrintHandling.h"
#include "clsLoopHandling.h"

using namespace std;

class clsInterpreter
{
    vector<string>& _vCodeWords;

    clsVariablesHandling VariablesHandler;
    clsPrintHandling PrintHandler;
    clsLoopHandling LoopHandler;

public:
    clsInterpreter( vector<string>& codeWords)
        : _vCodeWords(codeWords),
        VariablesHandler(_vCodeWords),
        PrintHandler(_vCodeWords, VariablesHandler),
        LoopHandler(_vCodeWords)
    {
    }

    void Excute()
    {


        for (int i = 0; i < _vCodeWords.size();)
        {
            string word = _vCodeWords[i];

            if (word == "Int")
            {
                if (!VariablesHandler.AnalyzingVariables(i))
                {
                    break;
                }
                i += 4; 
            }
            else if (word == "Print")
            {
                if (i + 1 < _vCodeWords.size() && _vCodeWords[i + 1] == "Op")
                {
                    PrintHandler.PrintOperationHandling(i);
                    i += 5; 
                }
                else
                {
                    PrintHandler.PrintHandling(i);
                    i += 2; 
                }
            }
            else if (word == "Loop")
            {
                LoopHandler.LoopHandling(i);
                i += 4; 
            }

            else if (word == "End")
            {
                break;
            }
           
        }
    }
};
