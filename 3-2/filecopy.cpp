#include <fstream>
using namespace std;

void copyfile(char* srcfile, char* dstfile)
{
	ifstream src;
	src.open(srcfile);
	ofstream dst;
	dst.open(dstfile);
	char ch;
	while (src.get(ch))
		dst << ch;
	src.close(); dst.close();
}

int main()
{
	char srcfile[] = "democopy.src";
	char dstfile[] = "democopy.dst";
	copyfile(srcfile, dstfile);
	return 0;
}
