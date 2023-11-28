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
        void setStart(int x,int y){
            start.setXY(x,y);
        }
        void setEnd(int x,int y){
            end.setXY(x,y);
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
        void setCenter(int x, int y){
            center.setXY(x,y);
        }
        void setRadius(int r){
            rad = r;
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
        void setUpperLeft(int x,int y){
            UL.setXY(x,y);
        }
        void setLowerRight(int x,int y){
            UL.setXY(x,y);
        }
};

class Picture
{
    private :
        int cNum ;
        int rNum ;
		int lNum ;
		Circle* pCircles;
		Rect* pRects;
		Line* pLines;
    public :
        Picture()
        {
            cNum=0;
            rNum=0;
            lNum=0;
            pCircles = NULL ;
            pRects = NULL ;
            pLines = NULL ;
        }

        Picture(int cn, int rn, int ln, int pC[][3], int pR[][4], int pL[][4])
        {
            cNum = cn;
            rNum = rn;
            lNum = ln;
            pCircles = new Circle[cn];
            pRects = new Rect[rn];
			pLines = new Line[ln];
			int i;
			for (i=0;i<cn;i++){
				pCircles[i].setCenter(pC[i][0],pC[i][1]);
				pCircles[i].setRadius(pC[i][2]);
			}
			for (i=0;i<rn;i++){
				pRects[i].setUpperLeft(pR[i][0],pR[i][1]);
				pRects[i].setLowerRight(pR[i][2],pR[i][3]);
			}
			for (i=0;i<ln;i++){
				pLines[i].setStart(pL[i][0],pL[i][1]);
				pLines[i].setEnd(pL[i][2],pL[i][3]);
			}

		}

		void print();
};


void Picture::print()
{
    int i;
    for(i=0; i<cNum ; i++)
    {
        pCircles[i].print();
    }
    for(i=0 ; i<rNum ; i++)
    {
        pRects[i].print();
    }
    for(i=0 ; i<lNum; i++)
    {
        pLines[i].print();
    }
};

int main(){

	clrscr();

    int cArr[3][3]={{50,50,50}, {200,100,100}, {420,50,30}};
    int rArr[2][4]={{30,40,170,100}, {420,50,500,300}};
    int lArr[2][4]={{420,50,300,300}, {40,500,500,400}};

    Picture myPic(3,2,2,cArr,rArr,lArr);

	myPic.print() ;

	getch();
	return 0;
}