#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;
int count;
struct student{
	string name;
	bool choose;
};
vector <student> stu;
student temp;
void ReadName(const string &filename)//读入文件 
	{
		ifstream file(filename);
		string line;
		assert(file.is_open());
	while (getline(file, line)){
	    //assert(getline(file, line));
		stringstream ss(line);
		ss >> temp.name;
		stu.push_back(temp);
			}
			file.close();
	}
void OutName(const string &filename)
	{
		ofstream file(filename);
		string line;
		assert(file.is_open());
	    file<<"点名的人数: "<<count<<endl; 
	    file.close();
	}

int main(){
    srand(time(NULL));
    //种下随机种子，否则rand()函数返回的是伪随机数
    string myfile="名单.txt";
    ReadName(myfile);
    
    while(getchar()!='q'){
    system("cls");
    int n=rand()%stu.size();
    if(!stu[n].choose)
    {cout<<"中奖了:      "<<stu[n].name<<" ";
	stu[n].choose=true;count++;
	}
	 OutName("count.txt");
	}
   
    return 0;
}
