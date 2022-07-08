#include<iostream>
#include <string>
#include<vector>
#include<fstream>
using namespace std;

class instruction_mem
{
public:
    int _pc;                                                                // input
    string _instruction, _opcode, _rs, _rt, _rd, _func, _shamt, _immediate; //output
    vector<string> instructions;

    instruction_mem(int pc)
    {
            _pc = pc;
            instruction();
    }

    void instruction()
    {
        string str;
        ifstream in("instruction.txt");
        while (getline(in, str))
        {
            if (str.size() > 0)
            {
                instructions.push_back(str);
               // cout << str;
            }
        }

        _instruction = instructions[_pc];
        _opcode = _instruction.substr(0,6);

        if(_opcode == "000000" || _opcode == "111110")
        {
            _rs = _instruction.substr(6,5);
            _rt = _instruction.substr(11,5);
            _rd = _instruction.substr(16,5);
            _shamt = _instruction.substr(21,5);
			_func = _instruction.substr(26,6);
           // cout<<"func"<<_func<<endl;
            _immediate="0000000000000000";
        }

        else
        {
            _rd="00000";
            _func="000000";
            _shamt="00000";
            _rt = _instruction.substr(11,5);
			_rs = _instruction.substr(6,5);
			_immediate = _instruction.substr(16,16);
        }

    }
};
