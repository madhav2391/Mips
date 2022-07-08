#include <string>
#include<iostream>
#include<algorithm>
using namespace std;
class alu
{
public:
    int _opcode, _alu_control, _rs, _rt, _immediate, _result, go_branch, _alu_src;
    string result_string;

    alu(string opcode, string alu_control, string rs, string rt,string immediate, int alu_src)      // result and go_branch are outputs;  
    {
        _opcode = binaryToDecimal(opcode);
        _alu_control = binaryToDecimal(alu_control);
        //cout<<"alu c"<<_alu_control<<endl;
        //set_immediate(immediate);
       _immediate = binaryToDecimal(immediate);
       if(immediate.at(0) == '1')
        {
            //cout << "hi";
            string s = TwosComplement(immediate);
            int i = binaryToDecimal(s);
            
            _immediate = -1*i;
           
        }
        // cout<<endl<<"imme"<<_immediate<<endl;
        
       _alu_src = alu_src;
        _rs = binaryToDecimal(rs);
        _rt = binaryToDecimal(rt);
        //cout<<"alu rs"<<_rs<<endl;
        //cout<<"alu_rt"<<_rt<<endl;
        //cout << "alusrc" << _alu_src<<endl;
        calculate();
    }
    void calculate()
    {
        if(_alu_src == 0 && _opcode==5)
        {
           
                    _result = (_rs - _rt);
                    
                //    cout<<"case5"<<_rs<<"case5"<<_rt<<endl;
                    result_string = decToBinary(_result);
                    if(_result != 0)
                    {
                        go_branch = 1;
                    }
                    else
                    {
                        go_branch = 0;
                    }
                    
        }
        else if (_alu_src == 0)
        {
            switch (_alu_control)
            {
                case(32):               //add
                    _result = _rs + _rt;
                    result_string = decToBinary(_result);
                    break;
            
                case(34):               //sub
                    _result = _rs - _rt;
                    result_string = decToBinary(_result);
                    break;

                case(62):  
             //   cout<<"mult"; 
              //  cout<<_rs<<"rs"<<endl<<"rt"<<endl;           //multiply
                    _result = _rs * _rt;
                    result_string = decToBinary(_result);   
                    break;

                        
            }
        }

        else if(_alu_src == 1)
        {
            switch(_opcode)
            {
                case(8): 
                    //cout<<endl<<_rs<<endl;
                    //cout<<_immediate;                //addi
                    _result = _rs + _immediate;
                    result_string = decToBinary(_result);
                    go_branch=0;
                    break;
                


            }

        }

       
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

string decToBinary(int n) 
{ 
    // array to store binary number 
    string binaryNum; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) 
    { 
    
        // storing remainder in binary array 
        binaryNum.insert(i,to_string(n%2)); 
        n = n / 2; 
        i++; 
    }
reverse(binaryNum.begin(),binaryNum.end());
return binaryNum;
   
} 

char flip(char c) 
{
    return (c == '0')? '1': '0';
}

string TwosComplement(string st) 
{ 
    int n = st.length(); 
    int i; 
  
    string ones, twos; 
    ones = twos = ""; 
  
    //  for ones complement flip every bit 
    for (i = 0; i < n; i++) 
        ones += flip(st[i]); 
  
    //  for two's complement go from right to left in 
    //  ones complement and if we get 1 make, we make 
    //  them 0 and keep going left when we get first 
    //  0, make that 1 and go out of loop 
    twos = ones; 
    for (i = n - 1; i >= 0; i--) 
    { 
        if (ones[i] == '1') 
            twos[i] = '0'; 
        else
        { 
            twos[i] = '1'; 
            break; 
        } 
    } 
  
    // If No break : all are 1  as in 111  or  11111; 
    // in such case, add extra 1 at beginning 
    if (i == -1) 
        twos = '1' + twos;


        return twos; 
}

};
