
#include "Rock.h"
using namespace std;

/*
class IParent {
public:
    virtual void Release() =0;
};

class IChild : public IParent {
public:
    virtual void Do() =0;
};

class Parent : public IParent {
public:
    virtual void Release() {
        cout << "RELEASED !!" << endl;
    }
};

class Child : public Parent, public IChild {
public:
	using Parent::Release();
    virtual void Do() {
        cout << "bla bla says the human" << endl;
    }
};
*/

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR pCmdLine, int nCmdShow) {
    Console::Show();
	Console::SetColor(Console::Color::YELLOW, true, Console::Color::MAGENTA, false);

	cout << "Hello World!" << endl << "Welcome to C++ Programming" << endl;

    //Child* oChild = new Child();
    //oChild->Do();
    //oChild->Release();

	system("pause");
    return 0;
}
