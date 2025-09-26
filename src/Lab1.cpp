#include <iostream>
#include <limits>
using namespace std;

int main(int argc, char** argv) {
	int x = 1; float y = 2.3; double z = 4.56; char c = 'C'; bool b = true;
    std::cout << "type\t| lowest()\t| min()\t\t| max()\t\t| name\t| value\n"
        << "int\t| "
        << numeric_limits<int>::lowest() << "\t| "
        << numeric_limits<int>::min() << "\t| "
        << numeric_limits<int>::max() << "\t| "
        << "x\t| "
        << x << endl
        << "float\t| "
        << numeric_limits<float>::lowest() << "\t| "
        << numeric_limits<float>::min() << "\t| "
        << numeric_limits<float>::max() << "\t| "
        << "y\t| "
        << y << endl
        << "double\t| "
        << numeric_limits<double>::lowest() << "\t| "
        << numeric_limits<double>::min() << "\t| "
        << numeric_limits<double>::max() << "\t| "
        << "z\t| "
        << z << endl
        << "char\t| "
        << +numeric_limits<char>::lowest() << "\t\t| "
        << +numeric_limits<char>::min() << "\t\t| "
        << +numeric_limits<char>::max() << "\t\t| "
        << "c\t| "
        << c << endl
        << "bool\t| "
        << numeric_limits<bool>::lowest() << "\t\t| "
        << numeric_limits<bool>::min() << "\t\t| "
        << numeric_limits<bool>::max() << "\t\t| "
        << "b\t| "
        << b << endl;
	return 0;
}