#include<conio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n, i, Asum=0, Bsum=0; 
    

    cout<<"\nEnter the total number of voters: ";
        cin>>n;

    for(i=1; i<=n; i++)
    {
        system("cls");
        cout<<"\n We are collecting votes for two Parties , TEAM Alpha and TEAM Beta \n";
        cout<<"Voters please cast your vote for your favourite team.\n";
        cout<<"Press 'A' for TEAM Alpha, 'B' for TEAM Beta, or '0' for no vote.\n";

        char vote, confirm;
        bool voted = false;
        do {
            cout<<"\n Voter "<<i<<" please enter your vote: ";
                cin>>vote;

            if(vote == 'A' || vote == 'a' || vote == 'B' || vote == 'b' || vote == '0')
            {
                cout<<"\nYou selected: "<<vote<<". Confirm? (Y/N): ";
                    cin>>confirm;

                if(confirm == 'Y' || confirm == 'y')
                {
                    if(vote == 'A' || vote == 'a')
                    {
                        Asum++;
                    }
                    else if(vote == 'B' || vote == 'b')                       
                    {
                        Bsum++;
                    }
                    // for '0', do nothing             
                    system("cls");
                    voted = true;
                }
                else
                {
                    cout<<"Vote not confirmed. Please try again.\n";
                }
            }
            else
            {
                cout<<"Invalid input! Please enter A, B, or 0.\n";
            }
        } while(!voted);
    }

    cout<<"\n\n Total votes for TEAM ALPHA: "<<Asum;
    cout<<"\n Total votes for TEAM BETA: "<<Bsum;

    if(Asum > Bsum)
    {
        cout<<"\n\n TEAM Alpha wins the election with "<<Asum<<" votes!\n\n";
    }
    else if(Bsum > Asum)
    {
        cout<<"\n\n TEAM Beta wins the election with "<<Bsum<<" votes!\n\n";
    }
    else
    {
        cout<<"\n\n It's a tie!\n\n";
    }


}