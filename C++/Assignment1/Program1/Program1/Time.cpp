#include<iostream>
using namespace std;
class Time
{
	int hours;
	int minute;
	int seconds;
  public:
	Time()
	{
		hours = minute = seconds = 0;
	}
	Time(int hr, int min, int sec)
	{
		hours = hr;
		minute = min;
		seconds = sec;
		if (minute >= 60)
		{
			minute = minute - 60;
			hours++;
		}

		if (seconds >= 60)
		{
			seconds = seconds - 60;
			minute++;
		}
	}
	void Display()
	{
		printf("\n %d:%d:%d",hours,minute,seconds);
	}
	void addTime(Time &t1, Time &t2)
	{
		hours =t1.hours+t2.hours;
		minute = t1.minute + t2.minute;
		seconds = t1.seconds + t2.seconds;
	if (minute >= 60)
		{
			minute = minute-60;
			hours++;
		}

		if (seconds >= 60)
		{
			seconds = seconds-60;
			minute++;
		}

	}
};
int main()
{
	Time t1(12, 2, 3);
	Time t2(13, 59, 4);
	Time t3;
	t1.Display();
	t2.Display();
	t3.addTime(t1, t2);
	t3.Display();
	system("pause");
	return 0;
	
}
