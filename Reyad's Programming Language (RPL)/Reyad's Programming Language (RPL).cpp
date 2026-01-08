#include <iostream>
#include<string>
#include<vector>
#include"clsReadAndSplitCode.h"
#include "clsValidateCode.h"
#include"clsVariablesHandling.h"
#include "clsPrintHandling.h"
#include "clsLoopHandling.h"
#include "clsInterpreter.h"

using namespace std;

int main()
{
    

    clsReadAndSplitCode Reader;

    string Code = Reader.ReadCode();

    vector <string>& codeWords = Reader.GetCodeWords(); //get every word in user code

    clsInterpreter Interpreter(codeWords);

    Interpreter.Excute();



}
