#include <iostream>
using namespace std;

class base{
	public:
		static int staticvar;
		base() {}
		virtual ~base(){};
};
int base::staticvar = 0;
class baseplus: public base{
	public:
		baseplus(){};
		~baseplus(){};
};

int main(){
	base a,b;
	baseplus c;
	a.staticvar++;
	cout<< a.staticvar<<" "<<b.staticvar<<endl;
	b.staticvar++;
	cout<< a.staticvar<<" "<<b.staticvar<<endl;
	cout<<c.staticvar<<endl;
	c.staticvar++;
	cout<< a.staticvar<<" "<<b.staticvar<<endl;

	return 0;
}
