






#include <iostream>
using namespace std;

class Calendar
{
	private:
		int firstDay;
		int totalDays;
		
	public:
		Calendar(int f, int t);
		void drawCalendar();
};

Calendar::Calendar(int f, int t)
{
	firstDay=f;
	totalDays=t;
}

void Calendar::drawCalendar()
{
	        cout<<"Sun    Mon    Tue    Wed    Thu    Fri    Sat"<<endl;
	        
	        
	
	switch(firstDay)
	{
		case 1:
			cout<<"       *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
		case 2:
			cout<<"              *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
		case 3:
			cout<<"                     *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
		case 4:
			cout<<"                            *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
		case 5:
			cout<<"                                   *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
		case 6:
			cout<<"                                          *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
			
		case 0:
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
	}
	
	int left=totalDays+firstDay-28;
	
	switch(left)
	{
		case 1:
			cout<<"*"<<endl;
			break;
		case 2:
			cout<<"*      *"<<endl;
			break;
		case 3:
			cout<<"*      *      *"<<endl;
			break;
		case 4:
			cout<<"*      *      *      *"<<endl;
			break;
		case 5:
			cout<<"*      *      *      *      *"<<endl;
			break;
		case 6:
			cout<<"*      *      *      *      *      *"<<endl;
			break;
		case 7:
			cout<<"*      *      *      *      *      *      *"<<endl;
			break;
			
	}
	
	
}


int main()
{
	cout<<"Calendar of year 2020"<<endl;
	
	Calendar months[12]=
	{Calendar(3,31),
	Calendar((3+31)%7,29),
	Calendar((3+31+29)%7,31),
	Calendar((3+31+29+31)%7,30),
	Calendar((3+31+29+31+30)%7,31),
	Calendar((3+31+29+31+30+31)%7,30),
	Calendar((3+31+29+31+30+31+30)%7,31),
	Calendar((3+31+29+31+30+31+30+31)%7,31),
	Calendar((3+31+29+31+30+31+30+31+31)%7,30),
	Calendar((3+31+29+31+30+31+30+31+31+30)%7,31),
	Calendar((3+31+29+31+30+31+30+31+31+30+31)%7,30),
	Calendar((3+31+29+31+30+31+30+31+31+30+31+30)%7,31)};
	
	for(int i=0;i<12;i++)
	{
		switch(i+1)
		{
			case 1:
				cout<<"Jan"<<endl;
				break;
			case 2:
				cout<<"Feb"<<endl;
				break;
			case 3:
				cout<<"Mar"<<endl;
				break;
			case 4:
				cout<<"Apr"<<endl;
				break;
			case 5:
				cout<<"May"<<endl;
				break;
			case 6:
				cout<<"Jun"<<endl;
				break;
			case 7:
				cout<<"Jul"<<endl;
				break;
			case 8:
				cout<<"Aug"<<endl;
				break;
			case 9:
				cout<<"Sep"<<endl;
				break;
			case 10:
				cout<<"Oct"<<endl;
				break;
			case 11:
				cout<<"Nov"<<endl;
				break;
			case 12:
				cout<<"Dec"<<endl;
				break;
		}
		months[i].drawCalendar();
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
