#include <string>
#include "Polynomial.h"
#include <vector>

using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	cout << "one's address : " << one << endl;
	cout << "quad's address : " << quad << endl;
	cout << "cubic's address : " << cubic << endl;
	Polynomial One(one, 1);
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	
	cout << "Copy Constucter : Polynomial p = q" << endl;
	Polynomial p = q;  // test copy constructor
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << p[i] << endl;

	Polynomial r;

	cout << "Test r = p + q process : \n";
	r = p + q;
	cout << "Show : Polynomial r " << endl;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	
	cout << "Test r = q\n";
	r = q;             //test operator=s
	cout << "Test Operator= : Polynomial r " << endl;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	
	cout << "\nLast Line of Code\n";
	//r = c;

	
	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;
	
	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	
	cout << "TEST 1\n";
	r = r + r;
	cout << "r + r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = 5 + r;
	cout << "5+r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = r + 5000;
	cout << "r+5000\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "Test2\n";
	r = r - r;
	cout << "r-r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = 1000 - r;
	cout << "1000-r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = r - 1.447;
	cout << "r-1.447\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;


	cout << "Test3\n";
	r = r * r;
	cout << "r*r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = 500 - r;
	cout << "500-r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = 7 * r;
	cout << "7 * r\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = r * 2;
	cout << "r*2\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	r = r + q + c;
	cout << "r + q + c\n";
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	Polynomial b;
	b = b + 78;
	double z[] = {0};
	Polynomial zq(z,1);
	zq = zq + 1;
	cout << b.mySize() << " " << zq.mySize() << endl;
	Polynomial qq;
	qq = b * zq;
	cout << qq.mySize() << endl;
	for (int i = 0; i < qq.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << qq[i] << endl;
	b[1] = 78;
	b[2] = 99;
	for (int i = 0; i < b.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << b[i] << endl;
}
