
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
    

void sort(int values[], int n)
{   
    int OuterIndex,InnerIndex,temporary=0;
    for(OuterIndex=0;OuterIndex<n;OuterIndex++)
    {
        for(InnerIndex=0;InnerIndex<n-OuterIndex-1;InnerIndex++)
            {
                if(values[InnerIndex]>values[InnerIndex+1])
                    {
                        temporary=values[InnerIndex];
                        values[InnerIndex]=values[InnerIndex+1];
                        values[InnerIndex+1]=temporary;
                    }
            }
     }  
    // TODO: implement an O(n^2) sorting algorithm
   // return;
}
