#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

#define Min(A,B) ((A)<=(B)?(A):(B))

void usingclock()
{
	HANDLE hStdout;    
    COORD cursorPos;   
	int hour=0,min=0,sec=0;
	while(hour<99){
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  
		Sleep(1000);
		sec++;
		if(sec == 60){
			sec = 0;
			min++;
			if(min == 60){
				min = 0;
				hour++;
			}
		}
		
		cout << setfill('0') << setw(2) << hour << ":";
		cout << setfill('0') << setw(2) << min << ":";
		cout << setfill('0') << setw(2) << sec << endl;
		cursorPos.X = 0;
		cursorPos.Y = 0;
		SetConsoleCursorPosition(hStdout,cursorPos);
	} 
	CloseHandle(hStdout);
}

int main()
{
	usingclock();
	return 0;	
}
