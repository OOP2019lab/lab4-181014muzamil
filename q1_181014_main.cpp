#include "Imp.cpp" ;

int main()
{
	CricketTeam Pakistan("cricket.txt");
	CricketTeam otherteam;
	otherteam.setcaptain("Kohli");
	otherteam.setNoMem(11);
	otherteam.setrank(2);
	otherteam.setTeamName("India");
	cout<<"Enter Score for last 10 matches :";
	for(int i=0;i<10;i++)
	{
    int score;
    cin>>score;
	otherteam.inputScore(score);
	}
	otherteam.AveScoreinlast10matches();
	Pakistan.compare(otherteam);
}