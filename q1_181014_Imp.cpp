#include"class.h";

CricketTeam::CricketTeam()  //default constructor
{
	membernames=nullptr;
    no_of_members=-1;
	teamName=nullptr;
	for(int i=0;i<10;i++)
    Scoreinlast10matches[i]=-10;
    Rank=-1;
    captain=nullptr;
}

CricketTeam::CricketTeam(string filepath)
{
ifstream fin(filepath);
char array[500];
int size=500;
if(!fin)
{
cout<<"Could not open file"<<endl;
}
else
{
	fin.getline(array,size,':');   //discarding  TeamName:
	fin.getline(teamName,size,'\n');               
	fin.getline(array,size,':');   //discarding  Total Members:
	fin.getline(array,size,'\n');
	no_of_members=atoi(array);
	membernames=new string[no_of_members];
	for(int i=0;i<no_of_members;i++)
	{
		getline(fin,membernames[i]);
	}
	fin.getline(array,size,':');   //discarding  Rank:
	fin.getline(array,size,'\n');
	Rank=atoi(array);
	fin.getline(array,size,':');   //discarding Captain:
	fin.getline(array,size,'\n');
	captain =new string;
	string s(array);
    *captain=s;
	fin.getline(array,size,':');   //discarding score:
	for(int i=0;i<10;i++)
	{
		fin.getline(array,size,',');
		Scoreinlast10matches[i]=atoi(array);
	}
}
}

void CricketTeam::setcaptain(string cap)
{
	cout<<"Enter The Name Of Captain "<<endl;
	if(captain!=nullptr)
	{
		delete [] captain;
	}
	else
	{ 
     *captain=cap;
	}
}

string CricketTeam::getcaptain()
{
	return  * captain;
}

void CricketTeam::setTeamName(string name)
{
	cout<<"Enter The Name Of Team "<<endl;
	if(teamName!=nullptr)
	{
		delete [] teamName;
	}
	else
	{
		int size=name.length();
		teamName=new char[size+1];
		strcpy(teamName,name.c_str());
	}
}

string CricketTeam::getTeamName()
{
	return teamName;
}

void CricketTeam::setrank(int ran)
{
	cout<<"Enter the Rank of the team"<<endl;
if(ran>=0)
	Rank=ran;
else
	cout<<"You Entered Incorect input"<<endl;
}

int CricketTeam::getrank()
{
	return Rank;
}

void CricketTeam::setNoMem(int num)
{
	cout<<"Enter the Number of members"<<endl;
if(num>=0)
	no_of_members=num;
else
	cout<<"You Entered Incorect input"<<endl;
}

int CricketTeam::getNoMem()
{
	return no_of_members;
}

void CricketTeam::inputTeamMember(string name)
{
	for(int i=0;i<no_of_members;i++)
	{
		if(membernames!=nullptr)
		{
			membernames[i]=name;
		}
		else
			cout<<"Array Is full"<<endl;
	}
}

void CricketTeam::inputScore(int score)
{
	for(int i=0;i<10;i++)
	{
		Scoreinlast10matches[i]=Scoreinlast10matches[i+1];
	}
	Scoreinlast10matches[9]=score;
}

int CricketTeam::AveScoreinlast10matches()
{   int sum=0;
    int average =0;	
    for(int i=0;i<10;i++)
	{
		sum=sum+(A.Scoreinlast10matches[i]);
	}
	average=sum/10;
	return average;
}

void CricketTeam::printlatestscore()
{
	cout<<"Latest Score :"<<Scoreinlast10matches[9]<<endl;
    cout<<"Team Name :";
	for(int i=0;teamName[i]!='\0';i++)
	{
		cout<<teamName[i];
	}
	cout<<endl;
	cout<<"Captain :"<<captain<<endl;
}

void CricketTeam::printTeam()
{
	for(int i=0;teamName[i]!='\0';i++)
	cout<<"Team Name :"<<teamName[i]<<endl;
	cout<<"Total Members"<<no_of_members<<endl;
	for(int i=0;i<no_of_members;i++)
	{
		cout<<"Members :"<<endl<<membernames[i]<<endl;
	}
	cout<<"Rank :"<<Rank<<endl;
	cout<<"Captain :"<<captain<<endl;
	cout<<"Score :"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<Scoreinlast10matches[i]<<",";
	}
}

bool CricketTeam::compare(CricketTeam otherteam)
{
	if(otherteam.AveScoreinlast10matches() > AveScoreinlast10matches())
	{
	return false;
	cout<<"Other Team Is Better"<<endl;
	}
	else
	{
    return true;
	cout<<"My Team Is Better"<<endl;
	}
}

CricketTeam:: ~CricketTeam()
{
	delete[] membernames;
	delete [] teamName;
	delete [] captain;
}
