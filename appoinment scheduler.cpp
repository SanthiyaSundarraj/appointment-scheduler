#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define clrscr system("cls");
using namespace std;

struct tym
{
	int h,m;	
};
struct slot
{
	struct tym a;
	string id;
	bool st=0;
}s[20];
int n,z=0;
void viewAppointment()
{
	cout<<"\nTIME-SLOT  Visitor-ID  STATUS\n\n";
	for(int i=0;i<20;i++)
	{
		cout<<s[i].a.h<<":"<<s[i].a.m<<"	"<<s[i].id<<"		";
		if(s[i].st==0)
			cout<<"Available\n";
		else
			cout<<"Booked\n";
	}
}
void getApp(int h,int m);
void doSearch(int x,int h,int m)
{
	int i,j,c1=0,c2=0,idx1,idx2,op;
	for(i=x-1;i>=0;i--)
	{	
		c1++;
		if(s[i].st!=1)
		{
			idx1=i;
			break;
		}
	}
	for(i=x+1;x<20;x++)
	{
		c2++;
		if(s[i].st!=1)
		{
			idx2=i;
			break;
		}
	}
	if(c1>c2)
	{
		cout<<"The nearest Available Time Slot is "<<s[idx1].a.h<<":"<<s[idx1].a.m<<"\n";
		cout<<"Do you want to Get appointmnet on that slot ?\n\t Yes - press 1 [or] No - press 2\nEnter your choice : ";
		cin>>op;
		if(op==1)
		{
			z=1;
			getApp(s[idx1].a.h,s[idx1].a.m);
		}
		else
			cout<<"\nTry for an another Slot\n\n";
	}
	else if(c1<c2)
	{
		cout<<"The nearest Available Time Slot is "<<s[idx2].a.h<<":"<<s[idx2].a.m<<"\n";
		cout<<"Do you want to Get appointmnet on that slot ?\n\t Yes - press 1 [or] No - press 2\nEnter your choice : ";
		cin>>op;
		if(op==1)
		{
			z=1;
			getApp(s[idx2].a.h,s[idx2].a.m);
		}
		else
			cout<<"\nTry for an another Slot\n\n";
	}
	else 
	{
		cout<<"The nearest Available Time Slot is "<<s[idx1].a.h<<":"<<s[idx1].a.m<<" and "<<s[idx2].a.h<<":"<<s[idx2].a.m<<"\n";
		cout<<"Which slot do you want to Get appointmnet ?\n\t if first - press 1 ,else if second slot - press 2 ,else press 3\nEnter your choice : ";
		cin>>op;
		if(op==1)
		{
			z=1;
			getApp(s[idx1].a.h,s[idx1].a.m);
			z=0;
		}
		if(op==2)
		{
			z=1;
			getApp(s[idx2].a.h,s[idx2].a.m);
			z=0;
		}
		
		else
			cout<<"\nTry for an another Slot\n\n";
	}
}

void getApp(int h,int m)
{
	int h1,m1;
	if(z==0)
	{
		cout<<"Enter the time slot you want : (hh:mm)";
		scanf("%d:%d",&h,&m);
	}
	for(int i=0;i<20;i++)
	{
		if(s[i].a.h==h && s[i].a.m==m)
		{
			if(s[i].st==0)
			{
				cout<<"The Slot is Available\n\tEnter Visitor id : ";
				cin>>s[i].id;
				s[i].st=1;
				cout<<"The desired slot is allocated for Visitor id-"<<s[i].id<<"\n\n";
			}
			else
				doSearch(i,h,m);
			break;
		}
	}
}
void search()
{
	int i, num, first, last, middle,v;
	int h,m;
	cout<<"Enter the slot that you want to search:"; 
     scanf("%d:%d",&h,&m);
     num=(h*60)+m;
	first = 0;
	last = 20-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		v=(s[middle].a.h * 60)+s[middle].a.m;
	   if(v < num)
	   {
		first = middle + 1;

	   }
	   else if(v == num)
	   {
	   	if(s[middle].st==0)
	   	{
			cout<<"The Time Slot is available\n"; 
               break; 
          }
          else
          {
          	cout<<"The Time Slot is Already booked by Visitor ID - "<<s[middle].id<<"\n";
		}
	   }
          else{ 
                last = middle - 1; 
          } 
           middle = (first + last)/2; 
        } 
        if(first > last)
	{
	   cout<<"\nThe time slot is not found\n\n";
	}

}
int main()
{
	int i,j,f=0,op,q=3,e=0;
	for(i=0;i<20;i++)
	{
		s[i].a.h=q;
		s[i].a.m=e;
		e+=15;
		if(e>=60)
		{
			q++;
			e=0;
		}
	}
	while(f==0)
	{
		clrscr;
        	cout<<"\n\n\t\t\t\t************CLINIC  TOKEN  GENERATION  SYSTEM**************";
		cout<<"\n\n\t\t1.View Appointment Schedule\n\t\t2.Get an appointment\n\t\t3.Search for Availablity\n\t\t4.Exit\n\tEnter your choice : ";
		cin>>op;
		if(op==1)
		{
			clrscr;
			cout<<"\n\n\t\t\t\tAPPOINTMENT RESULT\n\n";
			viewAppointment();
			cout<<"\n\n\nEnter any continue....\n";
               getch();               
		}
		else if(op==2)
		{
			clrscr;
			cout<<"\n\n\t\t\t\tGET APPOINTMENT\n\n";
			getApp(0,0);
			n++;
			cout<<"\n\n\nEnter any continue....\n";
          	getch();               
		}
		else if(op==3)
		{
			clrscr;
			cout<<"\n\n\t\t\t\t\tSEARCHING A Visitor\n\n";
			search();
			cout<<"\n\n\nEnter any continue....\n";
               getch();               
		}
		else if(op==4)
		{
			f=1;
			cout<<"\n\n\n\n\n\t\t\t\t\t\tThank you for visiting\n\n\n";
		}
	}
}


