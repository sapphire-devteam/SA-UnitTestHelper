// Copyright (c) 2021 Sapphire's Suite. All Rights Reserved.. All Rights Reserved.

#include <UnitTestHelper.hpp>
using namespace Sa;

#define LOG(_str) std::cout << _str << std::endl;

void GroupBeginCB(const std::string& _name)
{
	// Get UserData.
	int& myUserData = UTH::GetUserData<int>();
	(void)myUserData;

	LOG("Group of test [" << _name << "] started\n");
}

void GroupEndCB(const UTH::Group& _group)
{
	LOG("Group of test [" << _group.name << "] exit with code: " << _group.localExit);
}

void TitleCB(const UTH::Title& _infos)
{
	LOG("Test: " << _infos.pred << "\t" << _infos.funcDecl << " in file: " << _infos.fileName << " at line:" << _infos.lineNum << '\n');
}

void ParamsCB(const std::vector<UTH::Param>& _params)
{
	for (auto it = _params.begin(); it != _params.end(); ++it)
		LOG(it->name << ": [" << it->value << "]\n");
}

void ResultCB(bool _predicate)
{
	if (_predicate)
		LOG("Result: Success\n")
	else
		LOG("Result: Failure\n")
}

/// Methods with all the tests (can be in a separated file).
void MainTests()
{
	int i = 5;
	int j = 9;

	SA_UTH_EQ(i, i);
	SA_UTH_EQ(i, j); // Error.
}

int main()
{
	SA_UTH_INIT();


	// Disable default console log.
	UTH::bCslLog = false;

	// Set UserData.
	int myUserData = 9;
	UTH::UserData = &myUserData;

	// Set Callbacks.
	UTH::GroupBeginCB = GroupBeginCB;
	UTH::GroupEndCB = GroupEndCB;
	UTH::TitleCB = TitleCB;
	UTH::ParamsCB = ParamsCB;
	UTH::ResultCB = ResultCB;

	SA_UTH_GP(MainTests());


	SA_UTH_EXIT();
}
