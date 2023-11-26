#include<stdio.h>
#include<time.h>
int main()
{
	time_t now;
	struct tm *timenow;
	timenow = localtime(&now);
	printf("%s", asctime(timenow));
}