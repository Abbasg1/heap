#include <iostream>
#include <fstream>
#include <cstring>

/**
Ghazi A
cpp data structures spring sem
sources:
The hash tables assignment which had us use file input, basically copied over to here
https://www.youtube.com/watch?v=sf_9w653xdE&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q

*/

using namespace std;

const int MSIZE = 100;
int parent(int i);
int leftC(int i);
int rightC(int i);
void swapUp(int h[] , int i);
void swapDown(int h[] , int i, int s);
void insert(int h[], int& s, int num);
int getMax(int h[] , int& s);
void remAll(int h[], int& s);
void print(int h[] , int s);
void swap(int& a, int& b); // not sure if it would be allowed to just used the stdlib one
int main()
{
    int heap[MSIZE];
    int size = 0;

    char cmd;
    cout << "[M] for manual or [F] for file " << endl;
    cin >> cmd;

    if(cmd == 'm' || cmd == 'M')
    {
        int num;
        cout << "enter numbers one by one, when u want to stop enter -1" << endl;
        while(num != -1)
        {
            cin>> num;
            insert(heap, size, num);

        }


    } else if(cmd == 'f'||cmd == 'F')
    {
        char fileName[43];
        cout << "input file name: "<< endl;
        cin >> fileName;

        ifstream file(fileName);
        int num;
        while(file >> num)
        { 
            insert(heap, size, num);
        }
        file.close();
    } else 
    {
        cout << "invalid char entered" << endl;
    }

    cout << "Tree: " << endl;
    print(heap, size);
    cout << " removals:" << endl;
    remAll(heap, size);
}

int parent(int i)
{
    return (i-1)/2;
}
int leftC(int i)
{
    return 2* i +1;
}
int rightC(int i)
{
    return 2 * i+ 2;
}
void swapUp(int h[] , int i)
{
    while(i>0 && h[parent(i)] < h[i])
    {
        swap(h[parent(i)], h[i]);
        i = parent(i);
    }
}
void swapDown(int h[] , int i, int s)
{
    int left = leftC(i);
    int right = rightC(i);
    int bigger = i;
    if(left < s && h[left] > h[bigger])
    {
        bigger = left;        
    }
    if(right < s && h[right] > h[bigger])
    {
        bigger = right;
    }
    if(bigger != i)
    {
        swap(h[i], h[bigger]);
        swapDown(h, bigger, s);
        
    }

}
void insert(int h[], int& s, int num)
{
    if (s == MSIZE) 
    {
        cout << "Heap is full" << endl;
        return;
    }

    s++;
    h[s - 1] = num;
    swapUp(h, s - 1);   

}
int getMax(int h[] , int& s)
{
    if (s == 0) 
    {
        cout << "Heap is empty" << endl;
        return -1;
    }

    int max = h[0];
    h[0] = h[s - 1];
    s--;
    swapDown(h, 0, s);
    return max;
}
void remAll(int h[], int& s)
{
    while(s>0)
    {
        cout << getMax(h, s)<< endl;

    }
    cout << endl;//genius
}
void print(int h[] , int s)
{
  for(int x=0; x<s; ++x)
  {
    cout << h[x] << endl;
  }
}
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
