#include"my_file_system.h"
#include<bits/stdc++.h>
using namespace std;

map<string,pair<int,int> > m;
//function for adding files
void create_file(string cmd)
{
	//vector storing the vector of string
	vector<string>v;
    string temp = "";
    int mark=0;
	
	//code for splitting command into three parts filename,content and operation
	string s=cmd.substr(3);
	
	for(int i=0;i<s.length();++i){
		
		if(s[i]==' '&&mark==0){
			v.push_back(temp);
			temp = "";
			mark=1;
			
		}
		else if(mark==1)
		{
			v.push_back(s.substr(i+1));
			break;
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	//end of the code for splitting command into three parts filename,content and operation
	char filename[1000];
	for(int i=0;i<v[0].length();i++)
		filename[i]=v[0][i];
	string content=v[1].substr(0,v[1].size()-1);
	//filenme contains file
	//content conatains the text to be stored
	//no_block represents number of blocks required t store the text 
	//1 block=4Byte
	int no_blocks=0;
    if(content.size()%4!=0)
    	no_blocks=content.size()/4+1;
    else
    	no_blocks=content.size()/4;
    //randomly generating inode for each file
	int inode=1+ (rand() % 10) ;
	//storing into map
	m[filename]=make_pair(inode,no_blocks);
	//dividing files into different parts and storing them into diff blocks
	for(int i=0;i<no_blocks;i++)
	{
		char f_b[100];
		sprintf(f_b,"%d_%d.txt",inode,i);
		FILE *pointer=fopen(f_b,"w");
		string b_s=content.substr(i*4,4);
		for(int j=0;j<b_s.size();j++)
			fprintf(pointer,"%c",b_s[j]);
		fclose(pointer);
	}
	cout<<"File is successfully created\n";
}
//function for deleting specific file
void delete_file(string command)
{
	
	string filename=command.substr(3);
	if(m.find(filename)==m.end())
	{
		cout<<"File is not present\n";
		return ;
	}
	int inode_delete=m[filename].first;
	int blocks_delete=m[filename].second;
	//for removing each blocks of file
	for(int i=0;i<blocks_delete;i++)
	{
		char f_b[100];
		sprintf(f_b,"%d_%d.txt",inode_delete,i);
		int result=remove(f_b);
		
	}
	//for deleting meta data
	m.erase(filename);	
	cout<<"File is deleted successfully\n";
}
//function for renaming of specific file
void rename(string command)
{
	vector<string> v;
	string temp = "";
	string s=command.substr(3);
	for(int i=0;i<s.length();++i){
		
		if(s[i]==' '){
			v.push_back(temp);
			temp = "";
			
		}
		else{
			temp.push_back(s[i]);
		}	
	}
	v.push_back(temp);
	string old_file=v[0];
	string new_file=v[1];
	if(m.find(old_file)==m.end())
	{
		cout<<old_file<<" is not present\n";
		return ;
	}
	pair<int,int> old_pairs;
	old_pairs=m[old_file];
	m[new_file]=old_pairs;
	m.erase(old_file);
	cout<<old_file<<" is renamed to "<<new_file<<endl;
}
//function for displaying the file content by merging the content of all disk blocks
void display(string command)
{
	string filename=command.substr(3);
	pair<int,int>my_pair;
	//storing number of blocks and inode in the corresponding file to be displayed into my_pair
	if(m.find(filename)==m.end())
	{
		cout<<"File is not present\n";
		return;
	}
	my_pair=m[filename];
	int no_blocks=my_pair.second;
	int inode=my_pair.first;
	string result="";
	cout<<"\"";
	//for merging and printing the content of file into the console
	for(int i=0;i<no_blocks;i++)
	{
		int count=0;
		char file[100];
		sprintf(file,"%d_%d.txt",inode,i);
	
		FILE *f=fopen(file,"r");
		//if unable to open the file
		if(f==NULL)
		 cout<<"error in openning the file";
		do
    	{
        char c = fgetc(f);
        if (feof(f))
            break ;
 
        printf("%c", c);
    	}  while(1);//repeating while there are enough characters
		
	}
	cout<<"\"";
	cout<<endl;
}
//printing the names of all the files of directory
void ls()
{
	//iterating over map and printing file and inode
	if(m.size()==0)
		cout<<"No files are present\n";
	cout<<"Following files are present \n";
	cout<<"Filename      "<<"inode\n";
	for(auto it:m)
	{
		cout<<it.first;
		cout<<"           ";
		cout<<it.second.first;
		cout<<endl;
	}
}
