#include<iostream.h>
#include<conio.h>

class GeoShape{
	protected:
		float dim1;
		float dim2;

	public:
		GeoShape(){
			dim1 = dim2 = 0;
		}
		GeoShape(float x){
			dim1 = dim2 = x;
		}
		GeoShape(float x, float y){
			dim1 = x;
			dim2 = y;
		}


		void setDim1(float x){
			dim1 = x;
		}

		void setDim2(float y){
			dim2 = y;
		}

		float getDim1(){
			return dim1;
		}

		float getDim2(){
			return dim2;
		}

		float calcArea(){
			return 0.0f;
		}

};

class Rect: public GeoShape{

	public:
		Rect(): GeoShape(){
		}

		Rect(float x): GeoShape(x){
		}

		Rect(float x, float y): GeoShape(x,y){
		}

		float calcArea(){
			return dim1 * dim2;
		}

};



class Triangle:public GeoShape{

	public:
		Triangle():GeoShape(){
		}
		Triangle(float x): GeoShape(x){
		}
		Triangle(float b, float h): GeoShape(b,h){
		}

		float calcArea(){
			return 0.5 * dim1 * dim2;
		}

};

class Circle: protected GeoShape{

	public:
		Circle():GeoShape(){
		}
		Circle(float r):GeoShape(r){
		}

		float calcArea(){
			return 2.0 * (22.0/7.0) * dim1 * dim1;
		}
};

class Square: protected Rect{

	public:
		Square(): Rect(){
		}

		Square(float dim): Rect(dim){
		}

		~Square(){
		}

		float calcArea(){
        	return dim1*dim2;
		}


};




int main(){

	clrscr();

	float tD1=20,tD2=10;
	Triangle myT(tD1, tD2);
	cout <<"Triangle: "<<myT.calcArea() << endl;

	Circle myC(7);
	cout << "Circle before Violating: "<<myC.calcArea() << endl;

	Rect myR(2, 5);
	cout <<"Rectangle: "<<myR.calcArea() << endl;

	Square myS(5);
	cout <<"Square before Violating: "<<myS.calcArea() << endl;

	myS.setDim2(4) ; //Violating the Square Constraint
	myC.setDim2(3) ; //Violating the Circle Constraint
	cout << "Square after Violating: "<<myS.calcArea() << endl;
	cout <<"Circle after Violating: "<< myC.calcArea() << endl;

	getch() ;
	return 0;
}