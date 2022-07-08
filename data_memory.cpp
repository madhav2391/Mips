#include <string>
#include <fstream>
#include <vector>
using namespace std;

class data_memory
{
public:
    string _read_data, _write_data;
    int _address, _mem_write, _mem_read;
    data_memory(string address, string write_data, int mem_write, int mem_read)
    {
        _address = binaryToDecimal(address);
        _write_data = write_data;
        _mem_write = mem_write;
        _mem_read = mem_read;
    }

    void write_to_mem()
    {
        vector<string> mem_vec;
        string str;
        ifstream in("memory.txt");
        while (getline(in, str))
        {
            if (str.size() > 0)
            {
                mem_vec.push_back(str);
            }
        }

        if (_mem_write == 1)
        {
            mem_vec[_address] = _write_data;
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

};
