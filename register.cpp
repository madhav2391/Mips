#include<iostream>
#include <string>
//#include<fstream>
#include<vector>
using namespace std;

class registers
{
public:
    int check_regwrite, check_regdst;
    int writereg,readreg1,readreg2;
    string _read_reg1, _read_reg2, _write_reg, _read_data1, _read_data2, _opcode;
    vector<string> regs;
         

    registers(vector<string> reg0,string read_reg1, string read_reg2, string write_reg, int reg_dst, int reg_write)
    {
        _read_reg1 = read_reg1;
        _read_reg2 = read_reg2;
        _write_reg = write_reg;
        check_regwrite = reg_write;
        check_regdst = reg_dst;
        for(int i =0; i<32;i++)
        {
            regs.push_back(reg0[i]);
        }
            //regs[9]="00000000000000000000000000000101";

        writereg = binaryToDecimal(_write_reg);
        readreg2 = binaryToDecimal(_read_reg2);
        readreg1 = binaryToDecimal(_read_reg1);
        read_reg();
        //setreg();
    }

    void setreg( string write_data)
    {
       // int temp1=stoi(_write_reg);
        //cout<<_write_reg;
        
      //  cout<<"check"<<check_regwrite<<endl;
        if(check_regwrite == 1)
        {
           // cout<<endl<<"1";
            if(check_regdst == 1)
            {
                regs[writereg] = write_data; 
            }
    
            else
            {
        //        cout<<readreg2<<endl;
          //      cout<<"write"<<write_data<<endl;
                regs[readreg2] = write_data;
              //  cout<<"2";
            }
    
        }

            //_read_data1 = regs[readreg1];
            //_read_data2 = regs[readreg2];

            //cout << regs[writereg];
            //cout << regs[readreg2];
   
    }

    void read_reg()
    {
        int readreg2 = binaryToDecimal(_read_reg2);
        int readreg1 = binaryToDecimal(_read_reg1);
        _read_data1 = regs[readreg1];
        _read_data2 = regs[readreg2];

    }




    int binaryToDecimal(string n) 
{ 
	string num = n; 
	int dec_value = 0; 

	// Initializing base value to 1, i.e 2^0 
	int base = 1; 

	int len = num.length(); 
	for (int i = len - 1; i >= 0; i--) { 
		if (num[i] == '1') 
			dec_value += base; 
		base = base * 2; 
	} 

	return dec_value; 
} 
    
};
