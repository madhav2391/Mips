#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include"instruction_mem.cpp"
#include"control_unit.cpp"
#include"alu.cpp"
#include"register.cpp"
#include"data_memory.cpp"

using namespace std;
int clk=0, pc=0;
    string instruction, opcode, rs, rt, rd, func, address, immediate;
    int reg_write, reg_dst, mem_read, mem_write, mem_reg, branch,alu_src,alu_branch;
    string rs_data, rt_data, mem_read_data, out;
string  write_data;
/*  
    addi $t1,$0,1  #output reg
    addi $t0,$0,n  #(here inp is 5 )
    LOOP:mult $t1,$t1,$t0 #mult is a function which multiplies $t1=$t1*$t0 
    addi $t0, $t0,-1
    bne $t0,$0, LOOP
*/
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

vector<string> regs_m;

int main()
{
      for(int i =0; i<32;i++)
        {
            regs_m.push_back("00000000000000000000000000000000");
        }
    //int clk=0, pc=1;
    //string instruction, opcode, rs, rt, rd, func, address, immediate;
    //int reg_write, reg_dst, mem_read, mem_write, mem_reg, branch,alu_src;
    //string write_data, rs_data, rt_data, mem_read_data, out;
while(pc<5)
    {
    instruction_mem inst(pc);
    opcode = inst._opcode;
    func = inst._func;
    immediate = inst._immediate;
    rs = inst._rs;
    rt = inst._rt;
    rd = inst._rd;
  //  cout<<"rt"<<rt<<endl<<rs<<"rs"<<endl<<"rd"<<rd<<endl;
    //cout<<"pcdone";
    
    control_unit control(opcode);
    reg_write = control.reg_write;
    reg_dst = control.reg_dst;
    mem_read = control.mem_read;
    mem_write = control.mem_write;
    branch = control.branch;
    mem_reg = control.mem_reg;
    alu_src=control.alu_src;
    
    //cout<<"reg write"<<reg_write<<endl;
    
    registers reg(regs_m,rs, rt, rd, reg_dst, reg_write);
    rs_data = reg._read_data1;
    rt_data = reg._read_data2;
    //cout<<rs_data<<"rs_D"<<endl;
    //cout<<rt_data<<"rt_d"<<endl;
    //cout<<"reg done";
   
   
    alu alu(opcode, func, rs_data, rt_data,immediate,alu_src);
    write_data =alu.result_string;
    alu_branch = alu.go_branch;
 //   cout<<write_data<<"wr"<<endl;
    reg.setreg(write_data);

   // cout<<"branch"<<alu_branch<<endl;
    //cout<<endl<<regs_m[9]<<"999999999"<<endl;
    for(int i =0; i<32;i++)
        {
      //      cout<<"forcheck";
            regs_m[i]=reg.regs[i];
          //  cout<<regs_m[i]<<"  "<<reg.regs[i]<<endl;
        }
    
    

    data_memory memory(rt,write_data,mem_write,mem_read);
    mem_read_data = memory._read_data;
    
    //cout<<"mem done";
    
    pc++;
    clk++;

    if(alu.go_branch == 1 && branch == 1)
    {

        string s = TwosComplement(immediate);
        int i = binaryToDecimal(s);
        pc = pc - i;
        //cout<<"branch done";
    }
    //cout << rs_data << endl << rt_data << endl;
    //cout << reg._read_reg1<<endl<<reg._read_reg2<<endl;
    //cout<<rt_data<<endl<<rs_data;
    //cout << control.alu_src << endl << alu_src<<endl;
    // cout<<control.branch<<endl<<branch<<endl;
    // cout<<control.reg_write<<endl<<reg_write<<endl;
    // cout<<control.reg_dst<<endl<<reg_dst<<endl;
    // cout<<control.mem_read<<endl<<mem_read<<endl;
    // cout<<control.mem_write<<endl<<mem_write<<endl;
    // cout<<control.mem_reg<<endl<<mem_reg<<endl;
    // cout << reg._read_data1<<endl<<rs_data;
    // cout<<reg._read_data2<<endl<<rt_data;

    //cout << alu._rs<<endl;
    //cout << alu._rt<<endl;
    //cout << alu._opcode << endl;
    //cout << alu._alu_src << endl;
    //cout << alu.go_branch << endl;
    //cout << alu._result << endl;
    //cout << endl;
    //cout<<alu_branch<<" "<<branch<<endl;
    //cout<<pc;
    
   // cout<<"loop exxit";
   }
   // cout<<"a";
    cout<<"data stored in reg :"<<regs_m[9]<<endl;
    string fff= regs_m[9];
    int q=binaryToDecimal(regs_m[9]);
    cout<<"integer value of same :"<<q<<endl;
    cout<<"no of clock cycles :"<<clk<<endl;
    return 0;

}
