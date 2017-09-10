#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

std::vector<int> col_ord;

bool sortcol(const vector<string>& v1, const vector<string>& v2) 
{
	for(int i=0;i<col_ord.size(); i++)
	{
		if(v1[col_ord[i]] != v2[col_ord[i]])
		{
			return v1[col_ord[i]] < v2[col_ord[i]];
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int mem_size = atoi(argv[3])*1000;
	int tup_size = 100;
	int n_cols = argc - 6 + 1;
	int col_sizes[3] = {10,32,52};

	// cout << argc << endl;

	//Get column sort order
	for(int i=0;i<n_cols;i++)
	{
		int j = int(argv[5+i][1] - '0');
		col_ord.push_back(j);
	}
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
			int j=0;
			for(int i=0;i<3;i++)
			{
				v.push_back(line.substr(j,col_sizes[i]));
				j+=col_sizes[i]+2;
			}
			stringVec.push_back(v);
			// cout << v[2] << endl;
		}
	}

	//sort them

	sort(stringVec.begin(), stringVec.end(), sortcol);

	for(int i=0;i<stringVec.size();i++)
		cout << stringVec[i][0] << endl;

	//put them in a file

	//get parts from all files

	//sort them

	//put them in output file
	return 0;
}