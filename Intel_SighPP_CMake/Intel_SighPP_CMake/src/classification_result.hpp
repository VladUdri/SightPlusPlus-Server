﻿#pragma once
#include <iostream>
#include <string>
#include <vector>

enum ItemPriority
{
	HIGH, MEDIUM, LOW, EMERGENCY, NONE
};

struct point {
	double x;
	double y;

	point(const int x, const int y) : x(x), y(y) {}
};

struct ClassificationItem
{
	std::string name;
	double distance;
	point bottom_left;
	point top_right;
	ItemPriority prio = NONE;
	ClassificationItem(const std::string name) : name(name), bottom_left(point(0, 0)), top_right(point(0, 0)) {}
	ClassificationItem(const std::string name, const double distance, const point bottom_left, const point top_right) : name(name), distance(distance), bottom_left(bottom_left), top_right(top_right) {}

	std::string to_string() {
		std::string s = "";
		try
		{
			s.append("Printing ClassificationItem: " + name + "\n");
			s.append("ClassificationItem distance: " + std::to_string(distance) + "\n");
			s.append("ClassificationItem prio: " + std::to_string(prio) + "\n");
		}
		catch (const std::exception&)
		{
			s.append("");
		}

		return s;
	}
};

struct ClassificationResult {
	// TODO What results to store?
public:
	std::string model_name;
	std::vector<ClassificationItem> objects;

	ClassificationResult(const std::string name) : model_name(name) {}
	
	std::string to_string() {
		std::string s = "";
		try
		{
			s.append("Printing ClassificationResult: " + model_name + "\n");


			for (size_t i = 0; i < objects.size(); i++)
			{
				s.append("Object " + std::to_string(i) + ": " + objects[i].to_string());
			}
		}
		catch (const std::exception&)
		{
			s.append("");
		}

		return s;
	}
	
};

struct PrioritisedClassificationResult
{
	// TODO What results to store in a prioritised results?

	std::string model_name;
	std::vector<ClassificationItem> objects;

	std::string to_string() {
		std::string s = "";
		try
		{
			s.append("Printing PrioritisedClassificationResult: " + model_name + "\n");


			for (size_t i = 0; i < objects.size(); i++)
			{
				s.append("Object " + std::to_string(i) + ": " + objects[i].to_string());
			}
		}
		catch (const std::exception&)
		{
			s.append("");
		}

		return s;
	}

};