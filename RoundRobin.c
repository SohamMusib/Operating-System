#include<stdio.h>
#include<conio.h>

void main()
{
	int n,i,qt,count=0 ,temp,sq=0, bt[10],wt[10],tat[10],rem_bt[10];   //n=no.of processes, qt=quantum time, count=it gets incremented when one process gets executed, temp ans sq are temporary variables, bt=burst time array, wt= waiting time array, tat= turn arround time array, rem_bt= remaining burst time array
	float awt=0, atat=0;  //awt= average waiting time, atat= average turn arround time
	printf("Enter the total number of processes : ");
	scanf("%d",&n);
	printf("Enter the burst time for the processes :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	}
	printf("Enter quantum time : ");
	scanf("%d",&qt);
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp=qt;
			if(rem_bt[i]==0)
			{
				count++;
				continue;
			}
			if(rem_bt[i]>qt)
				rem_bt[i]=rem_bt[i]-qt;
			else
				if(rem_bt[i]>=0)
				{
					temp=rem_bt[i];
					rem_bt[i]=0;
				}
				sq=sq+temp;
				tat[i]=sq;
		}
		if(n==count)
		{
			break;
		}
	}
	printf("\nProcess\tBurst Time\tTurn Arround Time\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		awt=awt+wt[i];
		atat=atat+tat[i];
		printf("\n%d\t%d\t\t%d\t\t\t%d\n",i+1,bt[i],tat[i],wt[i]);
	}
	awt=awt/n;
	atat=atat/n;
	printf("Average Waiting Time : %f\n",awt);
	printf("Average Turn Arround Time : %f",atat);
}
