#include <iostream>
#include <memory>
#include "Foo.h"

class FooBase::Impl {
public:
	void print_public() {
		data1 = 1;
		data2 = "public";
		std::cout << data2.c_str() << data1 << std::endl;
	};

	void print_protect() {
		data1 = 2;
		data2 = "protect";
		std::cout << data2.c_str() << data1 << std::endl;
	};

	void print_private() {
		data1 = 3;
		data2 = "private";
		std::cout << data2.c_str() << data1 << std::endl;
	};
private:
	int data1;
	std::string data2;
};

FooBase::FooBase() {
	pImpl = std::unique_ptr<Impl>(new Impl());
}

FooBase::~FooBase() {
	pImpl.reset();
}

void FooBase::public_print() {
	pImpl->print_public();
}

void FooBase::protect_print() {
	pImpl->print_protect();
}

void FooBase::private_print() {
	pImpl->print_private();
}

/*-------------------------------------------------------------------*/

Foo::Foo() {}

Foo::~Foo() {}

void Foo::print(int mode) {
	switch(mode) {
	case 0:
		public_print();
		break;
	case 1:
		protect_print();
		break;
	default:
		private_print();
		break;
	}
}