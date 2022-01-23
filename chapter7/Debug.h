#ifndef __DEBUG__
#define __DEBUG__

class Debug
{
public:
	// ----- constructor -----

	constexpr Debug(bool i, bool h, bool o) : io(i), hw(h), other(o) {}
	constexpr Debug(bool b = true) : Debug(b, b, b) {}

	// ----- function -----

	constexpr bool any() { return io || hw || other; }

private:
	// ----- member ------

	bool io;
	bool hw;
	bool other;
};

#endif
