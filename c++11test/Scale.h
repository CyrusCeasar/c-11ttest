#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Scale {
public:
	explicit Scale(int scale) :_scale(scale) {}


	void ApplyScale(const vector<int>& v)const {
		for_each(v.begin(), v.end(), [=](int n) {cout << n*_scale << endl; });
	}
private:
	int _scale;
};