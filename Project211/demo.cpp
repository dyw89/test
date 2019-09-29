#include <iostream>
#include <vector>>
#include <algorithm>


struct Point
{  
	Point(double x1, double y1) :x(x1), y(y1) {};
	double x, y;

};
bool Incircle(const Point& pa, const Point& pb, const Point& pc, const Point& pd)
{
	const double adx = pa.x - pd.x;
	const double ady = pa.y - pd.y;
	const double bdx = pb.x - pd.x;
	const double bdy = pb.y - pd.y;

	const double adxbdy = adx * bdy;
	const double bdxady = bdx * ady;
	const double oabd = adxbdy - bdxady;

	if (oabd <= 0)
		return false;

	const double cdx = pc.x - pd.x;
	const double cdy = pc.y - pd.y;

	const double cdxady = cdx * ady;
	const double adxcdy = adx * cdy;
	const double ocad = cdxady - adxcdy;

	if (ocad <= 0)
		return false;

	const double bdxcdy = bdx * cdy;
	const double cdxbdy = cdx * bdy;

	const double alift = adx * adx + ady * ady;
	const double blift = bdx * bdx + bdy * bdy;
	const double clift = cdx * cdx + cdy * cdy;

	const double det = alift * (bdxcdy - cdxbdy) + blift * ocad + clift * oabd;
	//return det > 0;
	return det > 1e-7;//¼õÉÙ¾«¶ÈÎó²î
}

int main()
{
	Point a(0, 0), b(3, 0), c(4, 0), d(1, 3);
	bool f = Incircle(a, b, c, d);

	return 0;
}