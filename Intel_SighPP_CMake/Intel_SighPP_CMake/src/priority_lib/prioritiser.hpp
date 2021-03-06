// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Sight++. All Rights Reserved.

#pragma once
#include <vector>
#include <iostream>
#include "../classification_result.hpp"
#include "priority_module.hpp"

#include<map>
class Prioritiser
{
private:
	std::map<std::string, priority_module&> modules;
	std::string module_choice;
	priority_module* selected_module;
public:
	Prioritiser() {
		std::map<std::string, priority_module&> modules = {};
		std::string module_choice = "";
	}
	virtual void add_module(priority_module& p);
	virtual void set_module(std::string name_module);
	virtual int load_module();
	std::vector<ClassificationItem> prioritise(std::vector<ClassificationResult> results);
};