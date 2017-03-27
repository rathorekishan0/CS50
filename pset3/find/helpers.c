/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include<stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
        int mid,left=0,right=n-1;
    if(n<0)
    return false;
    else
    {
        while(left<=right)
        {
            mid=(left+right)/2;
            if(values[mid]==value)
            return true;
            else if(value<values[mid])
            right=mid-1;
            else 
            left=mid+1;
        }
    
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i,m=0,l;
    for(i=1,l=values[0];i<n;i++)
    {
        if(l<values[i]
        l=values[i];
    }
    l=l+1;
    int a[l];
    for(i=0;i<l;i++)
    a[i]=0;
    for(i=0;i<n;i++)
    {
        a[values[i]]++;
    }
    for(i=0;i<l;i++)
    {
        if(a[i]!=0)
        {
            while(a[i]!=0)
            {
                values[m++]=i;
                a[i]--;
            }
        }
    }
    // TODO: implement an O(n^2) sorting algorithm
    return;
}