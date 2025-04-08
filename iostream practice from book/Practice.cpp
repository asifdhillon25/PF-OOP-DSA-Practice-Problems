#include "Practice.h"

 void Practice::showing_flags()
{
	double pi = 3.14;
	int x = 1234;

	std::ios_base::fmtflags newf;

	newf = cout.flags();

	cout.setf(std::ios::hex | std::ios::uppercase | std::ios::showbase | std::ios::scientific);

	cout << "\nx=" << x << "pi = " << pi;

	// Set the formatting flags for cout
	cout.flags(newf);
	cout << "\nx=" << x << "pi = " << pi;
	// Now, you can print values with the desired formatting

	cout << "\n" << dec << x;

	cout << endl;

	cout.width(10);
	// cout.flags(std::ios::fmtflags(0));
	cout << setfill(' ') << x << "\n";

	cout << setw(15) << right << 12 << setw(15) << right << 12;
}
