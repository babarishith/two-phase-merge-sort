#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <fstream>
using namespace std;

std::vector<int> col_ord;

bool sortcol(const vector<int>& v1, const vector<int>& v2) 
{
	return v1[1] > v2[1];
}

int main(int argc, char const *argv[])
{
	int mem_size = atoi(argv[3])*1000;
	int tup_size = 100;
	int n_cols = 6 - argc;
	int col_sizes[3] = {10,32,52};

	//Get number of tuples that fit
	int num = mem_size/tup_size;

	//get them from file
	vector< vector<string> > stringVec;
	fstream file;
	string line;
	file.open("input.txt");
	if(file.is_open())
	{
		while(getline(file, line))
		{
			std::vector<string> v;
			// boost::split(v , line, boost::is_any_of(" "));
			// stringVec.push_back(v);
			int j=0;
			for(int i=0;i<3;i++)
			{
				v.push_back(line.substr(j,col_sizes[i]));
				j+=col_sizes[i]+2;
			}
			stringVec.push_back(v);
			cout << v[2] << endl;
		}
	}

	//sort them

	//put them in a file

	//get parts from all files

	//sort them

	//put them in output file
	return 0;
}