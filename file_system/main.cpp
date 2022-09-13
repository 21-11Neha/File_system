#include<bits/stdc++.h>
#include "my_file_system.h"

using namespace std;


//main function
int main()
{
	//for random number genertion 
	//random inode value generation
	srand(time(0));
	//extra command to exit from the program 
	cout<<"Command to terminate the program :: exit \n";
	cout<<endl;
	cout<<"--------------------------------------------------------\n";
	//option to test different command lines different number of times
	while(1)
	{
		cout<<">>Enter the command\n\n";
		string command;
		getline(cin,command);
		//calling create_file function for splitting and storing files into different disk blocks
		char operation=command[0];
		if(operation=='m')
		{
			create_file(command);
		}
		//calling delete_file for deleting a file given by user
		else if(operation == 'd')
		{
			delete_file(command);
		}
		//for renaming a file
		else if(operation=='r')
		{
			rename(command);
		}
		
		else if(operation=='p')
		{
			display(command);
		}
		//for listing all the files
		else if(operation=='l')
		{
			ls();
		}
		//for terminating the program
		else if(operation=='e')
		{
			break;
		}
		else
		{
			cout<<"Invalid Input\n";
		}
		cout<<endl;	
	}
	return 0;
					
}
