#include <stdio.h>
	int allocatted[5][5], max_needs[5][5], available[5];
	int allocation[5] = {0, 0, 0, 0, 0};
	int maximum_res[5], running[5], safe = 0;
	int count = 0, i, j, exec, resource, process, k = 1;
	 
	int main()
	{
	    printf("\nEnter number of process: ");
	        scanf("%d", &process);
	 
	        for (i = 0; i < process; i++) 
	    {
	            running[i] = 1;
	            count++;
	        }
	 
	        printf("\nEnter number of resource: ");
	        scanf("%d", &resource);
	 
	        printf("\nEnter Claim Vector:");
	        for (i = 0; i < resource; i++) 
	    { 
	            scanf("%d", &maximum_res[i]);
	        }
	 
	       printf("\nEnter allocatted Resource Table:\n");
	        for (i = 0; i < process; i++) 
	    {
	            for(j = 0; j < resource; j++) 
	        {
	              scanf("%d", &allocatted[i][j]);
	            }
	        }
	 
	        printf("\nEnter Maximum Claim Table:\n");
	        for (i = 0; i < process; i++) 
	    {
	            for(j = 0; j < resource; j++) 
	        {
	                    scanf("%d", &max_needs[i][j]);
	            }
	        }
	 
	    printf("\nThe Claim Vector is: ");
	        for (i = 0; i < resource; i++) 
	    {
	            printf("\t%d", maximum_res[i]);
	    }
	 
	        printf("\nThe allocatted Resource Table:\n");
	        for (i = 0; i < process; i++) 
	    {
	            for (j = 0; j < resource; j++) 
	        {
	                    printf("\t%d", allocatted[i][j]);
	            }
	        printf("\n");
	        }
	 
	        printf("\nThe Maximum Claim Table:\n");
	        for (i = 0; i < process; i++) 
	    {
	            for (j = 0; j < resource; j++) 
	        {
	                printf("\t%d", max_needs[i][j]);
	            }
	            printf("\n");
	        }
	 
	        for (i = 0; i < process; i++) 
	    {
	            for (j = 0; j < resource; j++) 
	        {
	                    allocation[j] += allocatted[i][j];
	            }
	        }
	 
	        printf("\nallocatted resource:");
	        for (i = 0; i < resource; i++) 
	    {
	            printf("\t%d", allocation[i]);
	        }
	 
	        for (i = 0; i < resource; i++) 
	    {
	            available[i] = maximum_res[i] - allocation[i];
	    }
	 
	        printf("\nAvailable resource:");
	        for (i = 0; i < resource; i++) 
	    {
	            printf("\t%d", available[i]);
	        }
	        printf("\n");
	 
	        while (count != 0) 
	    {
	            safe = 0;
	            for (i = 0; i < process; i++) 
	        {
	                    if (running[i]) 
	            {
	                        exec = 1;
	                        for (j = 0; j < resource; j++) 
	                {
	                                if (max_needs[i][j] - allocatted[i][j] > available[j]) 
	                    {
	                                    exec = 0;
	                                    break;
	                                }
	                        }
	                        if (exec) 
	                {
	                                printf("\nProcess%d is executing\n", i + 1);
	                                running[i] = 0;
	                                count--;
	                                safe = 1;
	 
	                                for (j = 0; j < resource; j++) 
	                    {
	                                    available[j] += allocatted[i][j];
	                                }
	                            break;
	                        }
	                    }
	            }
	            if (!safe) 
	        {
	                    printf("\nThe process are in unsafe state.\n");
	                    break;
	            } 
	        else 
	        {
	                    printf("\nThe process is in safe state");
	                    printf("\nAvailable vector:");
	 
	                    for (i = 0; i < resource; i++) 
	            {
	                        printf("\t%d", available[i]);
	                    }
	 
	                printf("\n");
	            }
	        }
	        return 0;
	}


