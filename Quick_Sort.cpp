#include<iostream>
#include"stdlib.h"

using namespace std;

void quickSort(int s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r,x=s[l];
		while(i<j)
		{
			while(i<j && s[j]>=x)
				j--;
			if(i<j)
				s[i++]=s[j];
			while(i<j && s[i]<x)
				i++;
			if(i<j)
				s[j--]=s[i];
		}
		s[i]=x;
		quickSort(s,l,i-1);
		quickSort(s,i+1,r);
	}
}

void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void insertSort(int data[],int n)
{
	for(int i=1,j;i<n;i++)
	{
		int tmp=data[i];
		for(j=i;j>0 && data[j-1]>tmp;j--)
			data[j]=data[j-1];
		data[j]=tmp;
	}
}

void selectSort(int data[],int n)
{
	for(int i=0,j,min;i<n-1;i++)
	{
		for(j=i+1,min=i;j<n;j++)
		{
			if(data[j]<data[min])
				min=j;
		}
		swap(data[i],data[min]);
	}
}

void bubleSort(int data[],int n)
{
	for(int i=n-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(data[j]>data[j+1])
				swap(data[j],data[j+1]);
		}
	}
}


void printArr(int arr[])
{
	for(int i=0;i<20;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[20]={0};
	for(int i=0;i<15;i++)
		arr[i]=rand()%100;
	printArr(arr);
//	quickSort(arr,0,19);
//	selectSort(arr,20);
	bubleSort(arr,15);
	printArr(arr);
}
