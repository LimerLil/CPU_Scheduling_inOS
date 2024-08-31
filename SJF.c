#include<stdio.h>
struct ff {
   int pid,ser,wait;
} p[20];
struct ff tmp;


void main() {
   int i, n, j, tot=0, totwait=0, tturn=0;
   float avwait, aturn;
   printf("Enter the number of process: ");
   scanf("%d",&n);
   for(i=0;i<n;i++) {
      printf("Enter pid of process %d: ",i+1);
      scanf("%d",&p[i].pid);
      printf("Enter service time of process %d: ",i+1);
      scanf("%d",&p[i].ser);
      p[i].wait=0;
   }


   for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
         if(p[i].ser>p[j].ser) {
            tmp=p[i];
            p[i]=p[j];
            p[j]=tmp;
     }


   printf("PID\tSER\tWAIT\tTOT\n");
   for(i=0;i<n;i++) {
      p[i].wait=tot;
      tot=tot+p[i].ser;
      tturn=tturn+tot;
      totwait=totwait+p[i].wait;
      printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].ser,p[i].wait,tot);
   }
   avwait=totwait*1.0/n;
   aturn=tturn*1.0/n;
   printf("TOTAL WAITING TIME: %d\n",totwait);
   printf("AVERAGE WAITING TIME: %4.2f\n",avwait);
   printf("TOTAL TURNAROUND TIME: %d\n",tturn);
   printf("AVERAGE TURNAROUND TIME: %4.2f\n",aturn);
}

