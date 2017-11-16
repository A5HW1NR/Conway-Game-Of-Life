/* This code is compiled on g++ -std=c+11
	I used vector containers because the size of the file is determined at runtime
	I read and wrote the vector as strings again to save execution time 
	I did a dimention check as well because, the challenge only specified that the input file will contain 0s and 1s, it did not explicitely state that it will be a square matrix.
	The following program takes a filepath from the user, and displays the next generation as well as creating a output file with the next generation.
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<sstream>
#include<iterator>
using namespace std;

std::vector< std::vector<string> > data;
std::vector< std::vector<string> > res;

void read_file()
{	string filepath;
	std::cout<<"Please enter the filepath: ";
	std::cin >> filepath;
	std::ifstream f(filepath, ios::binary);
	string line;
	
	while(std::getline(f,line))
	{
		std::vector<string> line_data;
		std::istringstream iss(line);
		std::string value;
		while(iss >> value)
			line_data.push_back(value);
		data.push_back(line_data);
	}
	int count = 0;
	
	for (auto row: data)
		for (auto s: row)
			for (char c: s)
				count++;
	if (count % data.size() != 0)
		cout<<"\n The dimentions of the matrix is invalid try again\n";
		
}

void update_generation()
{	res = data;
	int count;
	int max_len = data.size();
	

	for (int i = 0; i < max_len; i++)
		{	res[i].clear();
    		for (int j = 0; j < max_len; j++)
    			{	
					count = 0;
        			for(int k = i-1; k <= i+1; k++)
        				{	
        					if(k<0)  continue;
        					else if (k == max_len)  continue;
        	        		
							for(int l = j-1; l <= j+1; l++)
        					{	
        						if (l<0)  continue; 
        						else if (k==i && l==j)	 continue;
        						else if (l == max_len)  continue;
        						else if (data[k][0][l] == '1'  ) count++;		//checking for live cell neighbors
        					}
						}

					if(data[i][0][j] == '1')									// update generation conditions for a live cell
						{
							if(count>3	) res[i].push_back("0");
							else if (count<2) res[i].push_back("0");
							else res[i].push_back("1");
						}
					else if (count == 3 ) res[i].push_back("1");				// update generation conditions for a dead cell
					else res[i].push_back("0");
    			}

		}		
	
}

void write_file()
{
	ofstream output_file("output.txt");										
	for(auto row:res) 
	{
		std::copy(row.cbegin(), row.cend(), std::ostream_iterator<string>(output_file));
		output_file << "\n";
	}
}

void display()
{
	for(auto row:res)
	{	
		for(auto s:row)
			std::cout<<s;
		std::cout<<"\n"; 
	
	}
	
}

int main()
{
	read_file();
	update_generation();
	write_file();
	display();	
	return 0;
}
