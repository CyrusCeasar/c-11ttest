// c++11test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <shared_mutex>

#include <iostream>	
#include <string>
#include <functional>
#include "lambda.h"
#include "Scale.h"
using namespace std;



template <typename T1,typename T2>
auto compose(T1 t1, T2 t2){
	return t1 + t2;
}

void foo(int* p){
	cout << *p << endl;
}

void test_for_unique_ptr() {
	std::unique_ptr<int> p1(new int(42));
	std::unique_ptr<int> p2 = std::move(p1);// transfer ownership
	if (p1)
		foo(p1.get());
	(*p2)++;
	if (p2)
		foo(p2.get());

}

void bar(std::shared_ptr<int> p){
	++(*p);
}
void test_share_ptr() {
	shared_ptr<int> p1(new int(42));
	shared_ptr<int> p2 = p1;
	bar(p1);
	foo(p2.get());
}


void testfoo_bar() {
	int* p1 = NULL;
	int* p2 = nullptr;
	if (p1 == p2) {

	}
	foo(nullptr);
	bar(nullptr);
	bool f = nullptr;
	//int i = nullptr;// error: A native nullptr can only be converted to bool or, using reinterpret_cast, to an integral type
}

void test_loop() {
	std::map<std::string, std::vector<int>> map;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	map["one"] = v;
	for (const auto& kvp : map) {
		cout << kvp.first << endl;
		
		for (auto v : kvp.second)
			cout << v << endl;
	}
}
//	int arr[] = { 1,2,3,4,5 };
//	for (int& e : arr) {
//		e = e*e;
//	}
//
//}
void test_auto() {
	auto a = 42;
	auto str = "abcde";
	auto p = new std::string("asdf");
	std::map<std::string, std::vector<int>> map;
	for (auto it = begin(map); it != end(map); ++it) {

	}
	//auto v = compose(2, 3.14);
}
void test_weak_ptr() {
	auto p = make_shared<int>(42);
	weak_ptr<int> wp = p;
	{
		auto sp = wp.lock();
		cout << *sp << std::endl;
	}
	p.reset();
	if (wp.expired())
		cout << "expired" << std::endl;
}




int main()
{
	
	//test_for_unique_ptr();
	//test_loop();
	//test_share_ptr();
//	test_weak_ptr();
//	lambda::_test5();

//	lambda::_test7();
	lambda::_test9();
	system("pause");
    return 0;
}

