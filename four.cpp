#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
#define w 35
#define h 20
#define d_k 80
#define u_k 72
#define l_k 75
#define r_k 77
class pro2;
class pro1
{
	private:
		COORD p;
		int l;
		char d;
		vector<COORD> b;
	public:
		pro1(COORD q)
		{
			p = q;
			l = 1;
			b.push_back(p);
		}
		COORD fun1()
		{
			return p;
		}
		void fun2(char a)
		{
			d = a;
		}
		void fun3()
		{
			switch(d)
			{
				case 'u':
					{
						p.Y--;
						break;
					}
				case 'd':
					{
						p.Y++;
						break;
					}
				case 'l':
					{
						p.X--;
						break;
					}
				case 'r':
				{
					p.X++;
					break;
				}
			}
			b.push_back(p);
			if(b.size()>l)
			{
				b.erase(b.begin());
			}
		}
		bool fun4()
		{
			if(p.X==w+1 || p.X==0 || p.Y==h+1 || p.Y==0)
			{
				return true;
			}
			return false;
		}
		bool fun5(pro2 s2);
		void fun6()
		{
			l++;
		}
		vector<COORD> fun7()
		{
			return b;
		}
		bool fun8()
		{
			for(int i=0;i<b.size()-1;i++)
			{
				if(p.X==b[i].X && p.Y==b[i].Y)
				{
					return true;
				}
			}
			return false;
		}
};
class pro2
{
	private:
		COORD p1;
	public:
		pro2()
		{
			srand(time(NULL)); //srand is inbuild function used to get random value based on current time or we give constents to get random value
			fun1();
		}
		void fun1()
		{
			p1.X = rand() % w + 1;
			p1.Y = rand() % h + 1;
		}
		COORD fun2()
		{
			return p1;
		}
};
bool pro1::fun5(pro2 s2)
{
	if(p.X == s2.fun2().X && p.Y == s2.fun2().Y)
	{
		return true;
	}
	return false;
}
pro1 s1({w/2,h/2});
pro2 s2;
void a()
{
	vector<COORD> v = s1.fun7();
	for(int i=0;i<=h+1;i++)
	{
		COORD sp = s1.fun1();
		COORD sp1 = s2.fun2();
		cout<<"\t\t\t\t\t*";
		for(int j=0;j<=w+1;j++)
		{
			if(i==0 || i==h+1)
			{
				cout<<"*";
			}
			else if(sp.Y==i && sp.X==j)
			{
				cout<<"o";
			}
			else if(sp1.Y==i && sp1.X==j)
			{
				cout<<"@";
			}
			else
			{
				bool r = false;
				for(int c=0;c<v.size();c++)
				{
					if(j==v[c].X && i==v[c].Y)
					{
						cout<<">";
						r = true;
						break;
					}
				}
				if(!r)
				{
					cout<<" ";
				}
			}
		}
		cout<<"*"<<endl;;
	}
}
int main()
{
	int fr = 0;
	while(true)
	{
		Sleep(50);
		a();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
		if(kbhit()) //If anything user can press in the keyboard it's become true
		{
			switch(getch()) //getch() used to get the value for the key if user press up arrow it return 72
			{
				case u_k:
					{
						s1.fun2('u');
						break;
					}
				case d_k:
					{
						s1.fun2('d');
						break;
					}
				case l_k:
					{
						s1.fun2('l');
						break;
					}
				case r_k:
					{
						s1.fun2('r');
						break;
					}
			}
		}
		s1.fun3();
		if(s1.fun4() || s1.fun8())
		{
			cout<<"Game Over"<<endl;
			cout<<"Final Score : "<<fr;
			break;
		}
		if(s1.fun5(s2))
		{
			s1.fun6();
			fr++;
			s2.fun1();
		}
	}
	return 0;
}
