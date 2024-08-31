#include<stdio.h>
#define N 20
struct RR {
   int pid;
   float tser, twait ,tarriv;
} p[N];
struct RR tmp;
float tq;
int Np;


int NumOfP(){
   int n;
   printf("Enter the number of process: ");
   scanf("%d",&n);
   return n;
}


void inputRR(){
   int i, j;
   Np = NumOfP();
   printf("Enter time quantum of RR Algorithm: ");
   scanf("%f",&tq);
   for(i=0;i<Np;i++) {
      printf("Enter pid of process %d: ",i+1);
      scanf("%d",&p[i].pid);
      if(i==0) p[i].tarriv = 0;
      else {
         printf("Enter arrive time of process %d: ",i+1);
         scanf("%f",&p[i].tarriv);
      }
      printf("Enter service time of process %d: ",i+1);
      scanf("%f",&p[i].tser);
      p[i].twait=0;
   }
   //sort by time arrive of processes
   for(i=0;i<Np-1;i++)
      for(j=i+1;j<Np;j++)
         if(p[i].tarriv>p[j].tarriv) {
            tmp=p[i];
            p[i]=p[j];
            p[j]=tmp;
     }  
}


void RRAlgorithm(){
   int i, j, Count = Np;
   float tremain[N], t=0, tr;
   for(i=0;i<Np;i++)
      tremain[i] = p[i].tser;
   while(Count > 0){
      for(i=0;i<Np;i++){
         if((p[i].tarriv <= t) && (tremain[i] > 0)){
            if(tremain[i] > tq)
           tr = tq;
        else tr = tremain[i];
        tremain[i] -= tr;
        t += tr;
            for(j=0;j<Np;j++)
               if((j!=i)&&(tremain[i]>0))
                  p[j].twait += tr;
        if(tremain[i]==0){
               Count--;
           p[i].twait -= p[i].tarriv;
        }
        printf("|P%0d=%0.2f",p[i].pid,tr);
     }
      }
   }
   printf("|\n");
}


void main() {
   int i;
   float totwait = 0, tturn = 0, avwait, aturn;


   inputRR();
   RRAlgorithm();
   for(i=0;i<Np;i++){
      totwait += p[i].twait;
      tturn += p[i].twait + p[i].tser;
   }
   avwait = totwait/Np;
   aturn = tturn/Np;
   printf("TOTAL WAITING TIME: %4.2f\n",totwait);
   printf("AVERAGE WAITING TIME: %4.2f\n",avwait);
   printf("TOTAL TURNAROUND TIME: %4.2f\n",tturn);
   printf("AVERAGE TURNAROUND TIME: %4.2f\n",aturn);
}

