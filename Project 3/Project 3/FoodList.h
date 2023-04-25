#pragma once
#include <string>
#include <iostream>

class FoodList
{
public:

	class Food
	{
	public:

		std::string category;
		std::string name;
		int id;
		double nutrients[35];

		Food();
	};

	// Variables
	Food* foodList = new Food[7078];

	// Functions

	FoodList();
	~FoodList();

	// Sorting

};

