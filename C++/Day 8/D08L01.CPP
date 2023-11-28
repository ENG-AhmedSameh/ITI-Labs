#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

class Point
{ 
    private:
        int x ;
        int y ;
    public:
        Point(){
            x = y = 0 ;
            cout<<"Point default constructor is calling"<<endl;
        }

        Point(int m)
        { 
            x = y = m ;
            cout<<"Point one parameter constructor is calling"<<endl;
        }

        Point(int m, int n)
        { 
            x = m ;
            y = n ;
            cout<<"Point two parameter constructor is calling"<<endl;
        }

        ~Point(){
            cout<<"Point destructor is calling"<<endl;
        }


        void setX(int m)
        { 
            x = m ;
        }

        void setY(int n)
        { 
            y = n ;
        }

        void setXY(int m, int n)
        { 
            x=m;
            y=n;
        }

        int getX()
        { 
            return x ;
        }

        int getY()
        { 
            return y ;
        }

        void print(){
			cout<<"	Point Data: x="<<x<<" y="<<y<<endl;
		}
};

class Line
{
	private:
		Point start;
		Point end;
	public:
		Line() : start() , end()
		{
			cout<<"Line default constructor is calling"<<endl;
		}

		Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
		{
			cout<<"Line constructor with 4 parameters is calling"<<endl;
		}

		~Line(){
			cout<<"Line destructor is calling"<<endl;
		}

		void print()
		{
			cout<<"Start:";
			start.print();
			cout<<"End:";
			end.print();
		}
};

class Circle
{
	private:
		Point center;
		int rad;
	public:
		Circle() : center() , rad(0)
		{
			cout<<"Circle default constructor is calling"<<endl;
		}

		Circle(int x1, int y1, int r) : center(x1, y1), rad(r)
		{
			cout<<"Circle constructor with 3 parameters is calling"<<endl;
		}

		~Circle()
		{
			cout<<"Circle destructor is calling"<<endl;
		}

		void print()
		{
			cout<<"Center:";
			center.print();
			cout<<"Radius = "<<rad<<endl;
		}

};

class Rect
{
	private:
		Point UL;
		Point LR;
	public:
		Rect() : UL() , LR()
		{
			cout<<"Rect default constructor is calling"<<endl;
		}
		Rect(int x1, int y1, int x2, int y2) : UL(x1, y1), LR(x2, y2)
		{
			cout<<"Rect constructor with 4 parameter is calling"<<endl;
		}
		~Rect()
		{
			cout<<"Rect destructor is calling"<<endl;
		}
		void print()
		{
			cout<<"Upper Left:";
			UL.print();
			cout<<"Lower Right:";
			LR.print();
		}
};

int main(){

	clrscr();

	{
	cout<<"************************Line*************************\n";
	Line l1(30,100, 350, 400) ;
	l1.print();
    }

	cout<<"***********************Circle************************\n";
	Circle c1(250,150,100) ;
	c1.print();
    
	cout<<"************************Rect*************************\n";
	Rect r1(10,100,90,350) ;
	r1.print();

	getch();
	return 0;
}