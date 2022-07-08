#include<string>
#include<iostream>
using namespace std;
class control_unit
{
    public:
        string opcode;            
        int reg_write = 0;        
        int alu_src=0;
        int mem_write = 0;
        int mem_read = 0;
        int reg_dst = 0;
		int mem_reg=0;
        int branch;
        control_unit(string s)
        {
            opcode = s;
			//cout << opcode;
            set_signals();
        }

        void set_signals()
        {
            if(opcode == "000000")          // R-Type
            {
                reg_dst = 1;
				mem_reg=0;
				reg_write=1;
				mem_read=0;
				mem_write=0;
				branch=0;
				alu_src=0;
            }

            /*if(opcode != "000000" && opcode != "000100")        // not branches
            {
                reg_write = 1;
                reg_dst = 0;
            }*/

            else if(opcode == "101011")                              //store
            {
                //reg_dst = 1; dont care
				//mem_reg=0;
				reg_write=0;
				mem_read=0;
				mem_write=1;
				branch=0;
				alu_src=1;            
			}

            else if(opcode == "100011")                              // load word
            {
                reg_dst = 0;
				mem_reg=1;
				reg_write=1;
				mem_read=1;
				mem_write=0;
				branch=0;
				alu_src=1;
            }
			else if (opcode=="000100")
			{ 	//beq
				//reg_dst = 0; dont care
				//mem_reg=1;
				reg_write=0;
				mem_read=0;
				mem_write=0;
				alu_src=0;
				branch=1;
			}
			
			else if (opcode=="000101"){ //bne
				//reg_dst = 0; dont care
				//mem_reg=1;
				reg_write=0;
				mem_read=0;
				mem_write=0;
				branch=1;
				alu_src=0;
			}

            if(opcode == "111110")    
            {
                reg_dst = 1;
				mem_reg=0;
				reg_write=1;
				mem_read=0;
				mem_write=0;
				branch=0;
				alu_src=0;

            }
			if (opcode=="001000")
			{ //addi
				//cout<<"xyz";
		  		reg_dst = 0;
				mem_reg=0;
				reg_write=1;
				mem_read=0;
				mem_write=0;
				branch=0;
				alu_src=1;

			}
        }
};
