#include <stdio.h>
#include<time.h>
#include <sys/time.h>
void time_zone_test();
void get_time_test();
int main(int argc, char **argv) {
	get_time_test();
	time_zone_test();
	return 0;
}

void get_time_test(){
	printf("[time(NULL)]:%ld\n", time(NULL)); 

	struct timeval tv;
	struct timespec ts;
	//绝对时间戳
	gettimeofday(&tv, NULL);
	printf("gettimeofday : sec=>tv_sec=%ld, microseconds=>tv_usec=%d\n", tv.tv_sec, tv.tv_usec);

	clock_gettime(CLOCK_REALTIME,&ts);
	printf("clock_gettime real time from 1970 sec=>tv_sec=%ld, nanoseconds=>tv_nsec=%ld\n", ts.tv_sec, ts.tv_nsec);

	struct tm t;
	char date_time[64];
	strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime_r(&ts.tv_sec, &t));
	printf("clock_gettime : date_time=%s, tv_nsec=%ld\n", date_time, ts.tv_nsec);
	//系统运行时间
	clock_gettime(CLOCK_MONOTONIC,&ts);
	printf("clock_gettime os up time sec=>tv_sec=%ld, nanoseconds=>tv_nsec=%ld\n", ts.tv_sec, ts.tv_nsec);
	//进程运行时间
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&ts);
	printf("process run time sec=>tv_sec=%ld, nanoseconds=>tv_nsec=%ld\n", ts.tv_sec, ts.tv_nsec);
}

void time_zone_test(){

}