#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class CricketTeam
{
public:
string * membernames;
int no_of_members;
char * teamName;
int Scoreinlast10matches[10];
int Rank;
string * captain;
public:
CricketTeam();
CricketTeam(string name, int no_of_members);
CricketTeam(string filename);
string getcaptain ();
void setcaptain(string);
int  getrank();
void setrank(int);
string  getTeamName();
void setTeamName(string);
int  getNoMem();
void setNoMem(int);
void inputTeamMember(string name);
void inputScore(int score);
int AveScoreinlast10matches();
void printTeam();
void printlatestscore();
bool compare(CricketTeam);
~CricketTeam();
};