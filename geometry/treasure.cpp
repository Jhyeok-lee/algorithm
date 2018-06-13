#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 2.0*acos(0.0);
const double EPSILON = 1e-9;
class Vector {
public:
	double x,y;

	explicit Vector(double _x=0, double _y=0)
	{
		x = _x;
		y = _y;
	}

	bool operator == (const Vector& r) const
	{
		return x == r.x && y == r.y;
	}

	bool operator < (const Vector& r) const
	{
		return x != r.x ? x < r.x : y < r.y;
	}

	Vector operator + (const Vector& r) const
	{
		return Vector(x + r.x, y + r.y);
	}

	Vector operator - (const Vector& r) const
	{
		return Vector(x - r.x, y - r.y);
	}

	Vector operator * (double r) const
	{
		return Vector(x * r, y * r);
	}

	double size() const
	{
		return hypot(x,y);
	}

	Vector toUnit() const
	{
		return Vector(x/size(), y/size());
	}

	double polar() const
	{
		return fmod(atan2(y,x) + 2*PI, 2*PI);
	}

	double dot(const Vector& r) const
	{
		return x*r.x + y*r.y;
	}

	double cross(const Vector& r) const
	{
		return x*r.y - y*r.x;
	}

	Vector project(const Vector& r)
	{
		Vector a = r.toUnit();
		return a * a.dot(*this);
	}
};

double ccw(Vector a, Vector b)
{
	return a.cross(b);
}

double ccw(Vector p, Vector a, Vector b)
{
	return ccw(a-p, b-p);
}

bool lineIntersection(Vector a, Vector b, Vector c,
					Vector d, Vector& x)
{
	double det = (b-a).cross(d-c);
	if( fabs(det) < EPSILON )
		return false;
	x = a + (b-a) * ((c-a).cross(d-c)/det);
	return true;
}

typedef vector<Vector> polygon;
polygon cutPoly(const polygon& p, const Vector& a,
					const Vector& b)
{
	int n = p.size();
	vector<bool> inside(n);
	for(int i=0; i<n; i++)
		inside[i] = ccw(a,b,p[i]) >= 0;
	polygon ret;
	for(int i=0; i<n; i++) {
		int j = (i+1)%n;
		if( inside[i] )
			ret.push_back(p[i]);
		if( inside[i] != inside[j] ) {
			Vector cross;
			lineIntersection(p[i], p[j], a, b, cross);
			ret.push_back(cross);
		}
	}
	return ret;
}

polygon intersection(const polygon& p, double x1, double y1,
					double x2, double y2)
{
	Vector a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;
}

double area(const polygon& p)
{
	double ret = 0;
	for(int i=0; i<p.size(); i++) {
		int j = (i+1)%p.size();
		ret += p[i].x * p[j].y - p[i].y * p[j].x;
	}
	return fabs(ret)/2.0;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		double x1, y1, x2, y2;
		int N;
		scanf("%lf %lf %lf %lf %d", &x1, &y1, &x2, &y2, &N);
		double x,y;
		polygon p;
		for(int i=0; i<N; i++) {
			scanf("%lf %lf", &x, &y);
			p.push_back(Vector(x,y));
		}
		polygon ret = intersection(p, x1, y1, x2, y2);
		double r = area(ret);
		printf("%.10lf\n", r);
	}
	return 0;
}