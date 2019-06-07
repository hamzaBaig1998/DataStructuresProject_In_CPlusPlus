#pragma once
#include<iostream>
#include<string>

using namespace std;

class List
{
public:
	string Row_ID, Order_ID, Order_Date, Customer_ID, Customer_Name, Segment, Country, City;

};

class Node
{
public:
	List * Data = new List;
	Node *Next;

};

class DS_linkList
{
private:
	Node * Head;
	int Count;

public:
	DS_linkList()
	{
		Head = NULL;
		Count = 0;
	}

	void Insert(string Row_ID, string Order_ID, string Order_Date, string Customer_ID, string Customer_Name, string Segment, string Country, string City)
	{
		Node *ptr = new Node();
		ptr->Data->Row_ID =Row_ID;
		ptr->Data->Order_ID = Order_ID;
		ptr->Data->Order_Date = Order_Date;
		ptr->Data->Customer_ID = Customer_ID;
		ptr->Data->Customer_Name = Customer_Name;
		ptr->Data->Segment = Segment;
		ptr->Data->Country = Country;
		ptr->Data->City = City;
		ptr->Next = NULL;

		if (Head == NULL)
		{
			Head = ptr;
			Count++;
		}
		else
		{
			Node *Temp = Head;
			while (Temp->Next != NULL)
			{
				Temp = Temp->Next;
			}
			Temp->Next = ptr;
			Count++;
		}
	}

	void Search(string Row_ID)
	{

		if (Head != NULL)
		{
			Node *search = Head;
			int count = 0;
			Node *t1 = Head;
			int c1 = 0;
			if (Head->Next != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					if (search->Data->Row_ID == Row_ID)
					{
						count = 1;
						break;
					}

					if (c1 >= 1)
					{
						t1 = t1->Next;
					}
					search = search->Next;
					c1++;
				}
			}
			else
			{
				if (search->Data->Row_ID == Row_ID)
				{
					count = 2;

				}
			}
			if (count != 0)
			{
				cout << "\nRow ID Found !\n";
			}
			else
			{
				cout << "\nRow ID Not Found !\n";
			}
		}
		else
		{
			cout << "\nList IS EMPTY!\n";
		}
	}

	void Delete(string Row_ID)
	{
		if (Head != NULL)
		{
			Node *TempS = Head;
			int count = 0;
			Node *t1 = Head;
			int c1 = 0;
			if (Head->Next != NULL)
			{
				for (int i = 0; i < Count; i++)
				{
					if (TempS->Data->Row_ID == Row_ID)
					{
						count = 1;
						break;
					}

					if (c1 >= 1)
					{
						t1 = t1->Next;
					}
					TempS = TempS->Next;
					c1++;
				}
			}
			else
			{
				if (TempS->Data->Row_ID ==Row_ID)
				{
					count = 2;

				}
			}
			if (count != 0)
			{
				
				if (count == 1)
				{
					if (c1 == Count)
					{
						t1->Next = NULL;
					}
					else
					{
						t1->Next = TempS->Next;
					}
					Count--;
				}

				if (count == 2)
				{
					Head = NULL;
					Count--;
				}

				cout << "\nThe value has been deleted !\n";

			}
			else
			{
				cout << "\nThe value not found !\n";
			}
		}
		else
		{
			cout << "\nNo Value in the list !\n";
		}
	}

};
