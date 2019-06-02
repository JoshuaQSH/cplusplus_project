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
	while(hour<1){
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  
		Sleep(1);
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

int partsort(int* array, int left, int right)
{
	int key = array[left];
	while(left<right){
		while(left<right && array[left]<=key){
			left++;
		}
		array[right] = array[left];
		while(left<right && array[right]>=key){
			right++;
		}
		array[left] = array[right];
	}
	array[right] = key;
	return right;
}

void quicksort(int* array, int left, int right)
{
	if(left>=right)
		return;
	int index = partsort(array,left,right);
	quicksort(array,left,index-1);
	quicksort(array,index+1,right);
}
	

int main()
{
//	usingclock();
	int *array;
	array = [1,5,6,2];
	quicksort(array,0,array.size()-1);
	return 0;	
}
