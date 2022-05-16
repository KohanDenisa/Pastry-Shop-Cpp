#include "pastryshop_tests.h"
#include < cassert >

//teste pastry shop
//diagrama
//warnings

void pastryshop_tests::test_append()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	assert(repo.get_i(1) == Product(11, "Canolli", 30, 15, "Deep-fried"));
}

void pastryshop_tests::test_update()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	repo.update(12, "Choux", 25, 18, "Oven-baked");
	assert(repo.get_i(0) == Product(12, "Choux", 25, 18, "Oven-baked"));
}

void pastryshop_tests::test_remove()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	repo.remove(11);
	assert(repo.get_i(1) == Product(121, "Lava cake", 100, 20, "Chocolate"));
}

void pastryshop_tests::test_get_by_id()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	assert(repo.get_by_id(121) == Product(121, "Lava cake", 100, 20, "Chocolate"));
}

void pastryshop_tests::test_filter_by_type()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	string t = "Chocolate";
	PastryShop repo2;
	PastryShop repo3;
	repo3.append(p3);
	repo2 = repo.filterByType(t);
	assert(repo2 == repo3);
}

void pastryshop_tests::test_filter_by_price()
{
	Product p1(12, "Pavlova", 250, 33, "Meringue-based");
	Product p2(11, "Canolli", 30, 15, "Deep-fried");
	Product p3(121, "Lava cake", 100, 20, "Chocolate");
	PastryShop repo;
	repo.append(p1);
	repo.append(p2);
	repo.append(p3);
	float p = 33;
	PastryShop repo2;
	PastryShop repo3;
	repo3.append(p1);
	repo2 = repo.filterByPrice(p);
	assert(repo2 == repo3);
}

void pastryshop_tests::test_all()
{
	test_append();
	test_update();
	test_remove();
	test_get_by_id();
	//test_filter_by_type();
	//test_filter_by_price();
}
