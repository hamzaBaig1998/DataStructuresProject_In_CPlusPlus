#include"arrayList.h"
#include"linkList.h"
#include"dsw.h"
#include"bst.h"

#include<iostream>
#include<string>
#include<chrono>
#include<fstream>
using namespace std;
int main()
{
	int count = 0;
	ifstream in("data.csv");
	if (!in.is_open())
	{
		cout << "ERROR:Opening file!" << endl;
	}
	else {
		cout << "FILE:Found!" << endl;
	}
	int i = 0;
	string Row_ID_array[9996], Order_ID_array[9996], Order_Date_array[9996], Customer_ID_array[9996], Customer_Name_array[9996], Segment_array[9996], Country_array[9996], City_array[9996];
	string Row_ID, Order_ID, Order_Date, Customer_ID, Customer_Name, Segment, Country, City;
	auto start = std::chrono::high_resolution_clock::now();
	while (in.good())
	{
		getline(in, Row_ID, ',');
		Row_ID_array[i] = Row_ID;
		getline(in, Order_ID, ',');
		Order_ID_array[i] = Order_ID;
		getline(in, Order_Date, ',');
		Order_Date_array[i] = Order_Date;
		getline(in, Customer_ID, ',');
		Customer_ID_array[i] = Customer_ID;
		getline(in, Customer_Name, ',');
		Customer_Name_array[i] = Customer_Name;
		getline(in, Segment, ',');
		Segment_array[i] = Segment;
		getline(in, Country, ',');
		Country_array[i] = Country;
		getline(in, City, ',');
		City_array[i] = City;

		i++;
		count++;

	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	in.close();




	DS_arrayList obj(count);
	DS_linkList obj1;
	BinarySearchTree obj2;
	DSW obj3;


	auto start2 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < count; i++)
	{
		obj.Insert(Row_ID_array[i], Order_ID_array[i], Order_Date_array[i], Customer_ID_array[i], Customer_Name_array[i], Segment_array[i], Country_array[i], City_array[i]);
		//obj1.Insert(Row_ID_array[i], Order_ID_array[i], Order_Date_array[i], Customer_ID_array[i], Customer_Name_array[i], Segment_array[i], Country_array[i], City_array[i]);
		//obj2.Insert(Row_ID_array[i], Order_ID_array[i], Order_Date_array[i], Customer_ID_array[i], Customer_Name_array[i], Segment_array[i], Country_array[i], City_array[i]);
		//obj3.Insert(Row_ID_array[i], Order_ID_array[i], Order_Date_array[i], Customer_ID_array[i], Customer_Name_array[i], Segment_array[i], Country_array[i], City_array[i]);
	}
	auto finish2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed2 = finish2 - start2;
	std::cout << "Elapsed time: " << elapsed2.count() << " s\n";


	auto start3 = std::chrono::high_resolution_clock::now();

	obj.Search(Row_ID_array[2]);
	//obj1.Search(Row_ID_array[2]);
	//obj2.Search(Row_ID_array[2]);
	//obj3.Search(Row_ID_array[2]);
	auto finish3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed3 = finish3 - start3;
	std::cout << "Elapsed time: " << elapsed3.count() << " s\n";


	auto start4 = std::chrono::high_resolution_clock::now();

	obj.Delete(114);
	//obj1.Delete(Row_ID_array[7]);
	//obj2.Delete(Row_ID_array[7]);
	//obj3.Delete(Row_ID_array[7]);
	auto finish4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed4 = finish4 - start4;
	std::cout << "Elapsed time: " << elapsed4.count() << " s\n";
	//time end
	system("pause");
	return 0;
}