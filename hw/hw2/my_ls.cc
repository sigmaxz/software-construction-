#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

bool greaterthan(char* a, char* b)
{
	if( strcasecmp(a,b) > 0)
		return true;
	return false;
}

void sort(char** & sm, size_t size)
{
	char* temp;
	for(size_t i = 0; i < size-1; i++)
	{
		temp = sm[i];
		for(size_t j = i+1; j < size-1; j++)
		{
			if( greaterthan(temp,sm[j]) )
			{
				temp = sm[j];
				sm[j] = sm[i];
				sm[i] = temp;
			}
		}
	}
}

int main(int argc ,char* argv[] )
{
	char* dirName = new char[50];
	if(argc != 1)
		dirName = argv[1];
	else
		dirName = ".";
		

	DIR* dirp;
	if(!(dirp = opendir(dirName)))
	{
		cerr << "Error(" << errno << ") opening " << dirName << endl;
		return errno;
	}
	
	dirent* direntp;
	cout << dirName << endl;
	direntp = readdir(dirp);
	char** list = new char*[20];
	int size = 0;
	while((direntp = readdir(dirp)))
	{
		list[size] = direntp->d_name;
		//cout << "   " << list[size] << endl;
		size++;
	}

	

	sort(list, size);

	for (int i = 0; i < size ; i++)
	{
			cout << "    " << list[i] ;
		struct stat* sm;
		if( !stat( list[i] , sm))
		{
			if( !S_ISDIR( sm->st_mode) )
			{
			cout << "  " << sm->st_mode << " "; 
				cout << sm->st_nlink << " " << sm->st_size << " "; 
				cout << sm->st_mtime;
			}
		}
		
		cout << endl;
	}
	closedir(dirp);
	return 0;
}
