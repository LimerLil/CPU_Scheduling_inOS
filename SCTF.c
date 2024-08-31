#include<stdio.h>
#include<stdbool.h>


int pn[10];
int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], id[10], remain[10], i, n, run[10];
int totwt=0, tottat=0, totrp=0;
int i,j;


bool chk_remain(){
    for (i = 0; i<n; i++)
        if (remain[i]>0) return true;
    return false;
}


void main(){
    printf("Enter the number of processes:");
    scanf("%d",&n);


    for(i=0;i<n;i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
        remain[i] = bur[i];
        id[i] = i;
        star[i] = -1; finish[i] = 0; tat[i] = 0; wt[i] = 0;
        run[i] = arr[i];
    }
   
    //s?p x?p l?i cac ti?n trinh theo th? t? Arrival time t?ng d?n (ch? s?p x?p m?ng id)
    for (i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if ((arr[id[i]] > arr[id[j]])||(arr[id[i]] == arr[id[j]] && remain[id[i]] > remain[id[j]]))
            {
                int temp = id[i];
                id[i] = id[j];
                id[j] = temp;
            }
   
    star[id[0]]=arr[id[0]]; 
   
    while (chk_remain())
    {
        
        if (star[id[0]] == -1)
            star[id[0]] = run[id[0]];


        int min_gr = 0;
        int min_sm = 0;
       
        if (remain[id[0]]>0)
        {
          
            for (i=1;i<n;i++)
            {
                if (remain[id[i]] > 0)
                {
                    if (run[id[i]] < run[id[0]] + remain[id[0]] && run[id[i]] > run[id[0]] &&
                    remain[id[i]] < remain[id[0]] - run[id[i]] + run[id[0]]){
                        if (min_gr == 0)
                            min_gr = i;
                        else{
                            if ((run[id[min_gr]] > run[id[i]])||(run[id[min_gr]] == run[id[i]]
                            && remain[id[min_gr]] > remain[id[i]]))
                                min_gr = i;
                        }
                    }
               
                }
            }
           
           
            remain[id[0]] = remain[id[0]] - run[id[min_gr]] + run[id[0]];
            run[id[0]] = run[id[min_gr]];
            int temp = id[min_gr];
            id[min_gr] = id[0];
            id[0] = temp;
        }
       
        if(min_gr == 0){
            //vong l?p for s? tim process ti?p theo ???c th?c thi
            for (i=1;i<n;i++)
            {
                if (remain[id[i]] > 0)
                {
                    if (run[id[i]] <= run[id[0]] + remain[id[0]]){
                        if (min_sm == 0)
                            min_sm = i;
                        else{
                            if (remain[id[min_sm]] > remain[id[i]])
                                min_sm = i;
                        }
                    }
           
                }
            }
           
            run[id[0]] += remain[id[0]];
            finish[id[0]] = run[id[0]];
            tat[id[0]] = finish[id[0]] - arr[id[0]];
            remain[id[0]] = 0;
            wt[id[min_sm]] += (finish[id[0]] - run[id[min_sm]]);
            run[id[min_sm]] = finish[id[0]];
            int temp = id[min_sm];
            id[min_sm] = id[0];
            id[0] = temp;
        }
       
        if (min_gr == 0 && min_sm == 0)
        {
            int min_run = 0;
            for (i=1; i<n; i++)
                if(remain[id[i]]>0){
                    if (min_run == 0) min_run = i;
                    else if ((run[id[min_run]] > run[id[i]])||(run[id[min_run]] == run[id[i]]
                            && remain[id[min_run]] > remain[id[i]])) min_run = i;
                }

            run[id[0]] += remain[id[0]];
            finish[id[0]] = run[id[0]];
            tat[id[0]] = finish[id[0]] - arr[id[0]];
            remain[id[0]] = 0;
            int temp = id[min_run];
            id[min_run] = id[0];
            id[0] = temp;
        }
    }
   
   
    printf("\nPName\tArrtime\tBurtime\tResponse\tWaiting\tTAT\tFinish");
    for(i=0;i<n;i++) {
        printf("\n%d\t%d\t%d\t%d\t\t%d\t%d\t%d",pn[i],arr[i],bur[i],star[i]-arr[i],wt[i],tat[i],finish[i]);
        totrp+=(star[i]-arr[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage response time = %f", (totrp*1.0/n));
    printf("\nAverage waiting time = %f", (totwt*1.0/n));
    printf("\nAverage turnaround time = %f", (tottat*1.0/n));
    printf("\n");
}



