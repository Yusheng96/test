#include"func.h"
void* printime(void *p1)
{
	    time_t t;
        t=time(NULL);
        struct tm *p;
        p=gmtime(&t);
        printf("child thread:%04d-%02d-%02d %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		sleep(5);
		printf("child thread:%04d-%02d-%02d %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
}
int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,printime,NULL);
	sleep(2);
	time_t t;
	t=time(NULL);
	struct tm *p;
    p=gmtime(&t);
    printf("main thread:%04d-%02d-%02d %02d:%02d:%02d\n",p->tm_year+1900,p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
   pthread_join(pthid,NULL);

}

