#include<stdio.h>

struct time {
	int hour, min, sec;
};

int main() {
	struct time s, e, d;
	int stotal = 0;
	int etotal = 0;
	int total = 0;
	printf("시작시간(시, 분, 초):");
	scanf("%d%d%d", &s.hour ,&s.min , &s.sec);
	printf("종료시간(시, 분, 초):");
	scanf("%d%d%d", &e.hour ,&e.min , &e.sec);
	
	stotal = (s.hour*60*60) + (s.min * 60) + s.sec;
	etotal = (e.hour*60*60) + (e.min * 60) + e.sec;
	total = etotal - stotal;
	d.hour = total /3600;
	total %= 3600;
	d.min = total / 60;
	total %= 60;
	d.sec = total;
	printf("소요시간: %d:%d:%d", d.hour, d.min, d.sec);
	return 0;
} 
