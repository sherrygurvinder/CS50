
#include "helpers.h"

int search(int value, int values[], int n)
{
    
    int MidOfElement,EndOfElement,BeginningOfElement=0;
    EndOfElement=n;
    MidOfElement=(BeginningOfElement+EndOfElement)/2;
    while((value!=values[MidOfElement])&&(BeginningOfElement<MidOfElement))
    {
        if(values[MidOfElement]<value)
        {
            BeginningOfElement=MidOfElement;
            MidOfElement=(BeginningOfElement+EndOfElement)/2;
        }
        else
        {
            EndOfElement=MidOfElement;
            MidOfElement=(BeginningOfElement+EndOfElement)/2;
        }
    }
    if(value==values[MidOfElement])
    {
         return 1;
    }
    else
    {
        return 0;
    }
}
    

void sort(unsigned int values[], int n)
{   
    unsigned int Index=0,Index1=0;
    unsigned int Temp_Array[n];
    int count[65536];
    
    for(Index=0;Index<n;Index++)
    {
        count[values[Index]]++;
    }
    for(Index=1;Index<=65536;Index++)
    {
        count[Index]=count[Index]+count[Index-1];
    }    
    for(Index=0;Index<n;Index++)
    {
        Index1=count[values[Index]];
        Temp_Array[Index1-1]=values[Index];
        --count[values[Index]];
    }
    for(Index=0;Index<n;Index++)
    {
       values[Index]=Temp_Array[Index];
   
    }
    
    // TODO: implement an O(n^2) sorting algorithm
   // return;
}
