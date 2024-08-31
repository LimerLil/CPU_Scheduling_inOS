#include<stdio.h>


struct process
{
    char name;
    int AT,Burst_Time,Waiting_Time,TurnAround_Time,RT,CT;
}


Q1[10],Q2[10],Q3[10];


int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].AT>Q1[j].AT)
                    {
                          temp=Q1[i];
                          Q1[i]=Q1[j];
                          Q1[j]=temp;
                    }
            }
    }
}


int main()
{
     int i,j,k=0,r=0,time=0,tq1=5,tq2=8,flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nEnter the arrival time and burst time of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].AT,&Q1[i].Burst_Time);
         Q1[i].RT=Q1[i].Burst_Time;


    }
sortByArrival();
time=Q1[0].AT;
printf("Process in first queue following RR with qt=5");
printf("\nProcess\t\tRT\t\tWaiting_Time\t\tTurnAround_Time\t\t");
for(i=0;i<n;i++)
{


  if(Q1[i].RT<=tq1)
  {


       time+=Q1[i].RT;
       Q1[i].RT=0;
       Q1[i].Waiting_Time=time-Q1[i].AT-Q1[i].Burst_Time;
       Q1[i].TurnAround_Time=time-Q1[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].Burst_Time,Q1[i].Waiting_Time,Q1[i].TurnAround_Time);


  }
  else
  {
      Q2[k].Waiting_Time=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].Burst_Time=Q1[i].RT;
      Q2[k].RT=Q2[k].Burst_Time;
      Q2[k].name=Q1[i].name;
      k=k+1;
      flag=1;
   }
}
if(flag==1)
 {printf("\nProcess in second queue following RR with qt=8");
  printf("\nProcess\t\tRT\t\tWaiting_Time\t\tTurnAround_Time\t\t");
}for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].RT;
       Q2[i].RT=0;
       Q2[i].Waiting_Time=time-tq1-Q2[i].Burst_Time;
       Q2[i].TurnAround_Time=time-Q2[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].Burst_Time,Q2[i].Waiting_Time,Q2[i].TurnAround_Time);


    }
    else
    {
      Q3[r].AT=time;
      time+=tq2;
      Q2[i].RT-=tq2;
      Q3[r].Burst_Time=Q2[i].RT;
      Q3[r].RT=Q3[r].Burst_Time;
      Q3[r].name=Q2[i].name;
      r=r+1;
      flag=2;
    }
  }


{if(flag==2)
printf("\nProcess in third queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            Q3[i].CT=Q3[i].Burst_Time+time-tq1-tq2;
        else
            Q3[i].CT=Q3[i-1].CT+Q3[i].Burst_Time;


}


for(i=0;i<r;i++)
    {
        Q3[i].TurnAround_Time=Q3[i].CT;
        Q3[i].Waiting_Time=Q3[i].TurnAround_Time-Q3[i].Burst_Time;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q3[i].name,Q3[i].Burst_Time,Q3[i].Waiting_Time,Q3[i].TurnAround_Time);


    }


}



