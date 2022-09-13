# Description
When the contents of a file are given as input in the command line, the file system creates as many disk blocks as necessary with the contents of the file in the form of .txt files with disk numbers as their names. Every file have an inode pointing to all the disk blocks that store the file. When a file is renamed, it still have the same inode number. When a file is deleted, all the corresponding disk blocks are deleted from the file system and its meta-data (name and inode number) is deleted from the directory. When a file is read, all the contents of the input file are retrieved correctly. <br/>Implemented a file system that takes the following commands as inputs:
<br/>1. mf file-name “filecontents”: creates the file with the given file-name and file contents. Example : mf File1 “This is file 1”
<br/>2. df file-name : delete the file from the directory. Example : df File1 
<br/>3. rf file-name1 file-name2: rename the file from file1 to file2.
<br/>4. pf file-name : displays all the contents of the file correctly. Example : “This is file 1”.
<br/>5. ls : displays all the file-names and their inode number correctly.

# Assumptions
<br/>There is only a single level root directory.
<br/>The root directory can have any number of files of any size.
<br/>Each file has a unique name.
<br/>Each disk block which stores the file is of size 4 Bytes.
<br/>A file can be created, deleted, or renamed at any time.
# File_system
 implemented commands like mf (creation), df (deletion), rf (renaming), pf (displaying content) and ls(listing) for files
#Steps to execute the program :

	1 . Download and extract the folder .

	2 . To run the program using Makefile
		a . Open the downloaded folder .
		b . Open terminal in this folder .
		c . Type 'make' in the terminal .
		d . Then 'final' file will be created . Run this using './final' command .
		e . Follow the instructions .
		
	3 . To run the program without Makefile
		a . Open the downloaded folder .
		b . Open terminal in this folder .
		c . type 'g++ main.cpp -o final1 my_file_system.h my_file_system.cpp' .
		d . then new file 'final1' will be created . Run this using './final1' command .
		e . Follow the instructions .
		
Note: Types of command supported
	mf file-name “filecontents”
	df file-name
	rf file-name1 file-name2
	pf file-name
	ls
  
  
# Screenshots
![file1](https://user-images.githubusercontent.com/47311900/189842004-666c0890-eec9-4766-b73d-f199928bbacc.PNG)
![file2](https://user-images.githubusercontent.com/47311900/189842012-b4a4f940-d830-4553-a6c9-a946efbb9ae1.PNG)
![file3](https://user-images.githubusercontent.com/47311900/189842021-15609ad1-325b-462d-bdbe-43fab78df2eb.PNG)
      
