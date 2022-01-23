#ifndef __NO_DEFAULT__
#define __NO_DEFAULT__

class No_default
{
public:
	// ----- constructor -----

	No_default(int i) : member_i(i) {}

	// ----- member -----

	int getI();

private:
	int member_i;
};

class C
{
	// ----- constructor -----

public:
	C(No_default d = No_default(1)) : noDefault(d) {}

	// ----- member -----

	No_default &getD();

private:
	No_default noDefault;
};

#endif
