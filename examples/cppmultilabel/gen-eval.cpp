#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include "MersenneTwister.h"
using namespace std;


//void load(string& srcfile="./Voc_Cls_Images/all_imagelist", string& label2id = "label2id", string& file2label="file2label")

int main()
{

	ifstream in("./pascal.voc");
	ofstream train("./train.txt");
	ofstream eval("./val.txt");
	string line;
	while(getline(in,line))
	{
		MTRand mtr;
		if(mtr.rand()*9963<500)
			eval<<line<<std::endl;
		else
			train<<line<<std::endl;
	}
	in.close();
	train.close();
	eval.close();
	//void load(string& srcfile="./Voc_Cls_Images/all_imagelist", string& label2id = "label2id", string& file2label="file2label")
}
