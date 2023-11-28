#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct Complex{
	private:
		float real;
		float imag;

	public:
		Complex();
		Complex(float r);
		Complex(float r, float i);
		~Complex();
		void print();
	Complex (Complex &c){
		real = c.real;
		imag = c.imag;
		cout <<"    This is Copy constructor !!!!!!!"<<endl;
	}

	//Unary Operators ++,--
	//prefix
	Complex operator ++(){
		++real;
		++imag;
		return Complex(real,imag);
	}
	//postfix
	Complex operator ++(int dummy){
		this->real++;
		this->imag++;
		return *this; //return by value so the copy constructor will work
	}
	Complex operator --(){
		--real;
		--imag;
		return Complex(real,imag);
	}
	//postfix
	Complex operator --(int dummy){
		this->real--;
		this->imag--;
		return *this; //return by value so the copy constructor will work
	}


	//Binary operators
	//+ operator
	Complex operator +(Complex c){
		Complex temp(real+c.real,imag+c.imag);
		return temp;
	}
	Complex operator +(float f){
		Complex temp(real,imag);
		temp.real += f;
		return temp;
	}
	friend Complex operator +(float f,Complex &c);//passed by reference not to run a copy constructor and declare new copy object which we don't need

	//- operator
	Complex operator -(Complex c){
		Complex temp(real-c.real,imag-c.imag);
		return temp;
	}
	Complex operator -(float f){
		Complex temp(real,imag);
		temp.real -= f;
		return temp;
	}
	friend Complex operator -(float f,Complex &c);

	//* operator
	Complex operator *(Complex c){
		Complex temp;
		temp.real = (this->real * c.real)-(this->imag * c.imag);
		temp.imag = (this->real * c.imag)+(this->imag * c.real);
		return temp;
	}
	Complex operator *(float f){
		Complex temp(real,imag);
		temp.real *= f;
		temp.imag *= f;
		return temp;
	}
	friend Complex operator *(float f,Complex &c);
    
    //(/) operator
	Complex operator /(Complex c){
		Complex temp;
		temp.real = ((this->real * c.real)-(this->imag * -(c.imag)))/((c.real*c.real)+(c.imag*c.imag));
		temp.imag = ((this->real * -(c.imag))+(this->imag * c.real))/((c.real*c.real)+(c.imag*c.imag));
		return temp;
	}
	Complex operator /(float f){
		Complex temp(real,imag);
		temp.real /= f;
		temp.imag /= f;
		return temp;
	}
	friend Complex operator /(float f,Complex &c);

    //Assignment operator =
    Complex operator =(Complex c){
		this->real = c.real;
		this->imag = c.imag;
		return *this;
	}
	/*Complex operator =(float f){
		this->real = f;
        this->imag = 0;
		return *this;
	}*/

    //Assignment operator +=
	Complex operator +=(Complex c){
		this->real+=c.real;
		this->imag+=c.imag;
		return *this;
	}
	Complex operator +=(float f){
		this->real+=f;
		return *this;
	}

	//Assignment operator -=
	Complex operator -=(Complex c){
		this->real-=c.real;
		this->imag-=c.imag;
		return *this;
	}
	Complex operator -=(float f){
		this->real-=f;
		return *this;
	}

	//Assignment operator *=
	Complex operator *=(Complex c){
		this->real = (this->real * c.real)-(this->imag * c.imag);
		this->imag = (this->real * c.imag)+(this->imag * c.real);
		return *this;
	}
	Complex operator *=(float f){
		this->real*=f;
		this->imag*=f;
		return *this;
	}

	//Assignment operator /=
	Complex operator /=(Complex c){
		this->real = ((this->real * c.real)-(this->imag * -(c.imag)))/((c.real*c.real)+(c.imag*c.imag));
		this->imag = ((this->real * -(c.imag))+(this->imag * c.real))/((c.real*c.real)+(c.imag*c.imag));
		return *this;
	}
	Complex operator /=(float f){
		this->real/=f;
		this->imag/=f;
		return *this;
	}

	//Comparison operator ==
	int operator ==(Complex c){
		if((real==c.real)&&(imag==c.imag))
			return 1;
		else
			return 0;
	}
	int operator ==(float f){
		if((real==f)&&(imag==0))
			return 1;
		else
			return 0;
	}

	//Comparison operator !=
	int operator !=(Complex c){
		if((real!=c.real)||(imag!=c.imag))
			return 1;
		else
			return 0;
	}
	int operator !=(float f){
		if((real!=f)||(imag!=0))
			return 1;
		else
			return 0;
	}

	//Comparison operator >
	int operator > (Complex c){
		float temp1 = sqrt((real*real)+(imag*imag));
		float temp2 = sqrt((c.real*c.real)+(c.imag*c.imag));
		if(temp1>temp2)
			return 1;
		else
			return 0;
	}
	int operator > (float f){
		float temp = sqrt((real*real)+(imag*imag));
		if(temp>f)
			return 1;
		else
			return 0;
	}
	//Comparison operator <
	int operator < (Complex c){
		float temp1 = sqrt((real*real)+(imag*imag));
		float temp2 = sqrt((c.real*c.real)+(c.imag*c.imag));
		if(temp1<temp2)
			return 1;
		else
			return 0;
	}
	int operator < (float f){
		float temp = sqrt((real*real)+(imag*imag));
		if(temp<f)
			return 1;
		else
			return 0;
	}
	//Comparison operator >=
	int operator >= (Complex c){
		float temp1 = sqrt((real*real)+(imag*imag));
		float temp2 = sqrt((c.real*c.real)+(c.imag*c.imag));
		if(temp1>=temp2)
			return 1;
		else
			return 0;
	}
	int operator >= (float f){
		float temp = sqrt((real*real)+(imag*imag));
		if(temp>=f)
			return 1;
		else
			return 0;
	}
	//Comparison operator <=
	int operator <= (Complex c){
		float temp1 = sqrt((real*real)+(imag*imag));
		float temp2 = sqrt((c.real*c.real)+(c.imag*c.imag));
		if(temp1<=temp2)
			return 1;
		else
			return 0;
	}
	int operator <= (float f){
		float temp = sqrt((real*real)+(imag*imag));
		if(temp<=f)
			return 1;
		else
			return 0;
	}

	//Casting operators
	//() operator
	operator float(){ //no explicit return type here as c++ determines it based on type passed inside ()
		return sqrt((real*real)+(imag*imag));
	}

    //Shift operators of cin & cout
	friend istream& operator>>(istream& in,Complex& c);
	friend ostream& operator<<(ostream& out,Complex& c);
};


Complex operator +(float f,Complex &c){
	Complex temp(f+c.real,c.imag);
	return temp;
}
Complex operator -(float f,Complex &c){
	Complex temp(f-c.real,c.imag);
	return temp;
}
Complex operator *(float f,Complex &c){
	Complex temp(f*c.real,f*c.imag);
	return temp;
}
Complex operator /(float f,Complex &c){
	Complex temp;
	temp.real = (c.real * f)/((c.real*c.real)+(c.imag*c.imag));
	temp.imag = (f * (-(c.imag)))/((c.real*c.real)+(c.imag*c.imag));
	return temp;
}

//shift operators
istream& operator >>(istream& in, Complex & c)
{
	cout<<"    Enter real part: ";
	in>>c.real;
	cout<<"    Enter imag part: ";
	in>>c.imag;
	return in;
}

ostream& operator <<(ostream& out, Complex & c)
{
    if(c.imag<0)
		out<<c.real<<" - "<<fabs(c.imag)<<"i"<<endl;
	else
		out<<c.real<<" + "<<c.imag<<"i"<<endl;
    return out;
}


Complex::Complex(){
	real=imag=0;
	cout<<"    Default Constructor is calling"<<endl;
}

Complex::Complex(float real, float imag){
	this->real = real;
	this->imag = imag;
	cout<<"    Constructor with two parameters is calling"<<endl;
}

Complex::Complex(float r){
	real = imag =r;
	cout<<"    Constructor with one parameters is calling"<<endl;

}

Complex::~Complex(){
	cout<<"    Destructor is calling"<<endl;
}

void Complex::print(){
	if(imag<0){
		cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
	}else{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
}

int main(){

	clrscr();
	cout<<"Declaring c1(5+9i):";
	Complex c1(5,9);
	cout<<"Declaring c2(3+4i):";
	Complex c2(3,4);

    //Code section for testing unary operators
	cout<<"\nTest prefix operators : "<<endl;
	++c1;
	cout<<"    After prefix ++ operator c1 = ";
	c1.print();
	cout<<"\nTest postfix operators: "<<endl;
	c1--;
	cout<<"    After postfix -- operator c1 = ";
	c1.print();



	/*
	//code section for test (+,-,*,/)
	cout<<"Test / operator(complex / complex):"<<endl;
	Complex c3 = c1/c2; //3 Constructors(2 is copy) and only 2 destructor Because we assign the third instance to c3 so it won't be destruct
	cout<<"    Result of c1/c2 is ";
	c3.print();
	cout<<"Test / operator(complex / float):"<<endl;
	c3 = c1/3.5; //2 constructors and 2 destructors because c3 already declared before so the compiler will destruct the return object nd only give its values to c3
	cout<<"    Result of c1 / 3.5 is ";
	c3.print();
	cout<<"Test / operator(float / complex):"<<endl;
	c3 = 3.5/c1; //2 constructors and 2 destructors because c3 already declared before so the compiler will destruct the return object nd only give its values to c3
	cout<<"    Result of 3.5 / c1 is ";
	c3.print();
	*/

   /*
	//code section for Assignment operators (=(commented),+=,-=.*=,/=)
	cout<<"Test += operand(complex += complex):"<<endl;
	c1+=c2;
	c1.print();
	cout<<"Test += operand(complex += float):"<<endl;
	c1+=3.5;
	cout<<"    Result of c1 += 3.5 is ";
	c1.print();
	*/


   /*
	//code Section for compersion operators
	cout<<"Test == operator(complex == complex):"<<endl;
	int result = c1==c2;
	cout<<"    c1 == c2 is "<<result<<endl;
	cout<<"Test == operator(complex == float):"<<endl;
	result = c1==3;
	cout<<"    c1 == 3 is "<<result<<endl;
	*/


   /*
   //code Section for compersion operators
	cout<<"Test () operator:"<<endl;
	float f = (float) c1;
	cout<<"    The casting of c1 is "<<f<<endl;
	*/

    /*
   //code section for shift opertors
	cout<<"Test shift operators: "<<endl;
	cout<<"    C1 is "<<c1;
	cout<<"Enter C2 :"<<endl;
	cin>>c2;
	cout<<"    C1 is "<<c2;
    */

	getch();
	return 0;
}