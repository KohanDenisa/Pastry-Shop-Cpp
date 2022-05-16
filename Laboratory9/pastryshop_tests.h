#pragma once
#include "pastryshop.h"
#include <iostream>
using namespace std;

class pastryshop_tests
{
public:
	static void test_append();
	static void test_update();
	static void test_remove();
	static void test_get_by_id();
	static void test_filter_by_type();
	static void test_filter_by_price();
	static void test_all();

};

