#pragma once
#include <iostream>
#include<string>
using namespace std;

class List
{
public:
	string Row_ID, Order_ID, Order_Date, Customer_ID, Customer_Name, Segment, Country, City;

};


class DS_arrayList {
private:
	List * list; 			//pointer for dynamic array
	int length; 		//current size of list
	int max_size; 		//capacity of list

public:
	DS_arrayList(int size) {				//create a dynamic array of specified size
		max_size = size;
		list = new List[max_size];
		length = 0;
	}
	~DS_arrayList() {						//destructor of dynamic array
		delete[] list;
	}
	bool isEmpty() {
		return (length == 0);
	}
	bool isFull() {
		return (length == max_size);
	}
	int listSize() {
		return length;
	}
	int maxListSize() {
		return max_size;
	}


	void Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City)
	{
		if (length >= max_size) {
			cout << " Cannot insert in a full list" << endl;
			return;
		}
		else {
			list[length].Row_ID = Row_ID;
			list[length].Order_ID = Order_ID;
			list[length].Order_Date = Order_Date;
			list[length].Customer_ID = Customer_ID;
			list[length].Customer_Name = Customer_Name;
			list[length].Segment = Segment;
			list[length].Country = Country;
			list[length].City = City;

			length++;
		}
	}
	void Delete(int location) {
		if (location < 0 || location >= length) {
			cout << "The location of item to be removed is out of range";
			return;
		}
		else {
			for (int i = location; i < length - 1; i++)
			{
				list[i].Row_ID = list[i + 1].Row_ID;
				list[i].Order_ID = list[i + 1].Order_ID;
				list[i].Order_Date = list[i + 1].Order_Date;
				list[i].Customer_ID = list[i + 1].Customer_ID;
				list[i].Customer_Name = list[i + 1].Customer_Name;
				list[i].Segment = list[i + 1].Segment;
				list[i].Country = list[i + 1].Country;
				list[i].City = list[i + 1].City;
			}
			length--;
		}
	}
	void Search(string Row_ID) 
	{
		bool found = false;
		for (int i = 0; i < length; i++)
		{
			if (list[i].Row_ID == Row_ID)
			{
				cout << " Value:" << Row_ID << " found at index:" << i << endl;
				found = true;
			}
		}
		if (!found)
			cout << " Value:" << Row_ID << " not found in the list" << endl;
	}

};


