#include <iostream>
using namespace std;

class Date
{
	private:
		int year;
		int month;
		int day;
		
	public:
		//bool isCorrect(int y, int m, int d);
		bool isLeapYear(int y);
		Date(int y, int m, int d);
		void change();
		int getYear();
		int getMonth();
		int getDay();
};

Date::Date(int y, int m, int d)
{
	year=y;
	month=m;
	day=d+1;
	change();
}

bool Date::isLeapYear(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void Date::change()
{
	
	
	
	if(year>=1812&&year<=3000)
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			if(day<1||day>31)
			{
				day-=31;
				month+=1;
			}
		}
		
		else if(month==4||month==6||month==9||month==11)
		{
			if(day<1||day>30)
			{
				day-=30;
				month+=1;
			}
			
		}
		
		else if(month==2)
		{
			if(isLeapYear(year))
			{
				if(day>29)
				{
					day-=29;
					month+=1;
				}
			}
			
			else
			{
				if(day>28)
				{
					day-=28;
					month+=1;
				}
			}
		}
	}
	
	if(month>12)
	{
		month-=12;
		year+=1;
	}
	

}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}


Date NextDate(int y,int m,int d);





int main()
{
	int y,m,d;
	cout<<"Please input the year, the month and the day."<<endl;
	cin>>y>>m>>d;
	Date date2=NextDate(y,m,d);
	cout<<date2.getYear()<<"Äê"<<date2.getMonth()<<"ÔÂ"<<date2.getDay()<<"ÈÕ"<<endl; 
	
}

Date NextDate(int y,int m,int d)
{
	Date date2(y,m,d);
	return date2;
}
