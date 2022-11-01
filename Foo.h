#include <iostream>
#include <memory>


class FooBase {
private:
	class Impl;
	std::unique_ptr<Impl> pImpl;

protected:
	void private_print();
	void protect_print();
	void public_print();
	
public:
	FooBase();
	~FooBase();
};

class Foo : private FooBase {
public:
	Foo();
	~Foo();
	void print(int mode);
};