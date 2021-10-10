#include <stdio.h>
#include<time.h>
#include <sys/time.h>
void time_zone_test();
void get_time_test();
int main(int argc, char **argv) {
//	get_time_test();
	time_zone_test();
	return 0;
}
static int is_leap_year(time_t year) {
    if (year % 4) return 0;         /* A year not divisible by 4 is not leap. */
    else if (year % 100) return 1;  /* If div by 4 and not 100 is surely leap. */
    else if (year % 400) return 0;  /* If div by 100 *and* not by 400 is not leap. */
    else return 1;                  /* If div by 100 and 400 is leap. */
}

void nolocks_localtime(struct tm *tmp, time_t t, time_t tz, int dst) {
    const time_t secs_min = 60;
    const time_t secs_hour = 3600;
    const time_t secs_day = 3600*24;

    t -= tz;                            /* Adjust for timezone. */
    t += 3600*dst;                      /* Adjust for daylight time. */
    time_t days = t / secs_day;         /* Days passed since epoch. */
    time_t seconds = t % secs_day;      /* Remaining seconds. */

    tmp->tm_isdst = dst;
    tmp->tm_hour = seconds / secs_hour;
    tmp->tm_min = (seconds % secs_hour) / secs_min;
    tmp->tm_sec = (seconds % secs_hour) % secs_min;

    /* 1/1/1970 was a Thursday, that is, day 4 from the POV of the tm structure
     * where sunday = 0, so to calculate the day of the week we have to add 4
     * and take the modulo by 7. */
    tmp->tm_wday = (days+4)%7;

    /* Calculate the current year. */
    tmp->tm_year = 1970;
    while(1) {
        /* Leap years have one day more. */
        time_t days_this_year = 365 + is_leap_year(tmp->tm_year);
        if (days_this_year > days) break;
        days -= days_this_year;
        tmp->tm_year++;
    }
    tmp->tm_yday = days;  /* Number of day of the current year. */

    /* We need to calculate in which month and day of the month we are. To do
     * so we need to skip days according to how many days there are in each
     * month, and adjust for the leap year that has one more day in February. */
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    mdays[1] += is_leap_year(tmp->tm_year);

    tmp->tm_mon = 0;
    while(days >= mdays[tmp->tm_mon]) {
        days -= mdays[tmp->tm_mon];
        tmp->tm_mon++;
    }

    tmp->tm_mday = days+1;  /* Add 1 since our 'days' is zero-based. */
    tmp->tm_year -= 1900;   /* Surprisingly tm_year is year-1900. */
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
    /* Obtain timezone and daylight info. */
    tzset(); /* Now 'timezome' global is populated. */
    time_t t = time(NULL);
    struct tm *aux = localtime(&t);
    int daylight_active = aux->tm_isdst;

    struct tm tm;
    char buf[1024];

    nolocks_localtime(&tm,t,timezone,daylight_active);
    strftime(buf,sizeof(buf),"%d %b %H:%M:%S",&tm);
    printf("[timezone: %d, dl: %d] %s\n", (int)timezone, (int)daylight_active, buf);
}
