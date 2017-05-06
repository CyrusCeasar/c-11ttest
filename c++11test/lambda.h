#pragma once
#include <functional>
#include <iostream>
#include <list>
#include <algorithm>
#include "Scale.h"
using namespace std;
class lambda {
public:
	static void _test1() {
		auto f1 = [](int x, int y) {return x + y; };
		cout << f1(2, 3) << endl;
		function<int(int, int)> f2 = [](int x, int y) {return x + y; };
		cout << f2(3, 4) << endl;
	}

	static	void _test2() {
		int i = 3, j = 5;
		// The following lambda expression captures i by value and  
		// j by reference.  
		function<int(void)> f = [i, &j] {return i + j; };
		i = 22;
		j = 44;
		cout << f() << endl;
	}

	static	void _test3() {
		int n = [](int x, int y) {return x + y; }(5, 4);
		cout << n << endl;
	}
	static	void _test4() {
		list<int> numbers;
		numbers.push_back(13);
		numbers.push_back(17);
		numbers.push_back(42);
		numbers.push_back(46);
		numbers.push_back(99);

		const list<int>::const_iterator result = find_if(numbers.begin(), numbers.end(), [](int n) {return (n % 2) == 0; });
		if (result != numbers.end()) {
			cout << "The first even number in the list is" << *result << "." << endl;
		}
		else {
			cout << "The list contains no even numbers." << endl;
		}
	}
	static void _test5() {
		int timestwoplusthree = [](int x) {return[](int y) {return y * 2; }(x)+3; }(5);
		cout << timestwoplusthree << endl;
	}

	// ????????? what fuck for this test
	static void _test6() {
		// The following code declares a lambda expression that returns   
		// another lambda expression that adds two numbers.   
		// The returned lambda expression captures parameter x by value.  
		auto addtwointegers = [](int x) ->function<int(int)> {
			return[=](int y) {return x + y;  };
		};
		// The following code declares a lambda expression that takes another  
		// lambda expression as its argument.  
		// The lambda expression applies the argument z to the function f  
		// and multiplies by 2.  
		auto highterorder = [](const function<int(int)>& f, int z) {
			return f(z) * 2;
		};
		// Call the lambda expression that is bound to higherorder. 
		auto answer = highterorder(addtwointegers(7), 8);
		cout << answer << endl;
	}

	template <typename T>
	 static void negate_all(vector<T>& v) {
		for_each(v.begin(), v.end(), [](T& n) {n = -n; });
	}
	template <typename T>
	 static void print_all(const vector<T>& v) {
		for_each(v.begin(), v.end(), [](const T& n) {cout << n << endl; });
	}

	 static void _test7() {
		 vector<int> v;
		 v.push_back(34);
		 v.push_back(-43);
		 v.push_back(56);
		 print_all(v);
		 negate_all(v);
		 cout << "After negate_all():" << endl;
		 print_all(v);
	}

	 static void _test8() {
		 vector<int> values;
		 values.push_back(1);
		 values.push_back(2);
		 values.push_back(3);
		 values.push_back(4);

		 Scale s(3);
		 s.ApplyScale(values);
	 }

	
	 static void _test9() {
		 vector<int> elements(3);
		 vector<int> indices(3);
		 indices[0] = 0;
		 indices[1] = -1;
		 indices[2] = 2;

		 try {
			 for_each(indices.begin(), indices.end(), [&](int index) {
				 elements.at(index) = index;
			 });
		 }
		 catch (const out_of_range& e) {
			 cerr << "Caught '" << e.what() << ",." << endl;
		 };
	}
	

};