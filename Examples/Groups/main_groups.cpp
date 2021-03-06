// Copyright (c) 2021 Sapphire's Suite. All Rights Reserved.. All Rights Reserved.

#include <UnitTestHelper.hpp>
using namespace Sa;

/// Methods with grouped test (can be in a separated file).
void GroupTests_Success()
{
	int i = 5;
	SA_UTH_EQ(i, i);
}

void GroupTests_Failure()
{
	int i = 5;
	int j = 9;
	SA_UTH_EQ(i, j); // Error.


	// Create subgroup manually with name "TestSubGroup".
	SA_UTH_GPB(TestSubGroup);

	SA_UTH_EQ(i, i);

	SA_UTH_GPE();
}

int main()
{
	SA_UTH_INIT();


	SA_UTH_GP(GroupTests_Success());
	SA_UTH_GP(GroupTests_Failure());


	SA_UTH_EXIT();
}
