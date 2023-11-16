#include <iostream>
#include <Windows.h>
using namespace std;



void sh(HANDLE pheap) 
{
	PROCESS_HEAP_ENTRY phe;
	phe.lpData = NULL;
	int count = 1;
	while (HeapWalk(pheap, &phe)) 
	{
		// R - начало непрерывной области
		// U - нераспределенная область 
		// B - распределенная область
		cout << count << " -- address = " << showbase << hex << phe.lpData <<
			", size = " << dec << phe.cbData <<
			((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "") <<
			((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "") <<
			((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "") << "\n";
		count++;
	}
}



int main() 
{
	HANDLE pheap = GetProcessHeap();
	cout << "\n==================  BEFORE  ==================\n\n";
	sh(pheap);

	int size = 300000;
	int* m = new int[size];
	cout << "-- m = " << showbase << hex << m << ", size = " << dec << size << '\n';

	cout << "\n\n==================  AFTER  ==================\n\n";
	sh(pheap);
}