#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

unsigned long long a[8],b[8];

void *f(void *n)
{
	for(;;)
	{
		++a[(long long)n];
	}	
	pthread_exit(0);
}

typedef struct thread
{
	void *data;
	pthread_t thr;
} thread;

int main(void)
{
	int N = 2;
	pthread_t threads[N];
	long long i = 0;
	for(;i^N;++i)
	{
		//threads[i].data = (int *)(i+1);
		pthread_create(&threads[i],NULL,f,(void*)i);
		//pthread_join(threads[i].thr,NULL);
	}

	unsigned long long sumA = 0,sumB=0;
	i=0;
	for(;;)
	{
		for(i=0;i^N;++i)
		{
			sumA += a[i];
			sumB += b[i];
		}
		printf("\ec");
		printf("%lluM\n", (sumA - sumB)/1000000);
		sumB = sumA;
		for(i=0;i^N;++i)
		{
			b[i] = a[i];
		}
		sleep(1);
	}

	return 0;
}
