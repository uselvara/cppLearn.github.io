#include <iostream>

class AClass
{
public:
    AClass()
    {
        std::cout << "AClass constructor" << std::endl;
    }
	~AClass()
	{
		std::cout << "AClass destructor" << std::endl;
	}
	int getA() volatile // this* is volatile
	{
		std::cout << "AClass getA" << std::endl;
        return a;
	}

    int getA() const // this* is const
    {
        std::cout << "AClass getA" << std::endl;
        return a;
    }

    int getA() const volatile // this* is const-volatile
    {
        std::cout << "AClass getA" << std::endl;
        return a;
    }

private:
	int a; //will not be const/volatile qualified if holding object is const/volatile. however accessess through the c/v object will be treated accordingly.
};

void func()
{
    volatile AClass aobjv{}; // entire object is volatile
    std::cout << aobjv.getA() << std::endl;

    const AClass aobjc{}; // entire object is const
    std::cout << aobjc.getA() << std::endl;

	  const volatile AClass aobjcv{}; // entire object is const-volatile
	  std::cout << aobjcv.getA() << std::endl;
}

int main()
{
    func();
    return 0;
}
