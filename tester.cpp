#include "epswriter.hpp"
#include <cstdlib>

int MyRand(){return rand()%65535;}

int main() {

	srand(time(NULL));

	const double xMin = -1, yMin = -1;
	const double xMax = 1, yMax = 1;

	{
		epswriter c("circle.eps", xMin, yMin, xMax, yMax);
		epswriter cF("circleF.eps", xMin, yMin, xMax, yMax);
		const double radius = 0.5;
		const double centerX = 0;
		const double centerY = 0;

		c.circle(centerX, centerY,radius,MyRand(), MyRand(), MyRand());
		cF.filledCircle(centerX, centerY,radius,MyRand(), MyRand(), MyRand());
	}

	{
		epswriter t("triangle.eps", xMin, yMin, xMax, yMax);
		epswriter tF("triangleFilled.eps", xMin, yMin, xMax, yMax);

		const double x1= 0  , y1=.5;
		const double x2=-.25, y2=-.25;
		const double x3= .25, y3=-.25;

		t.triangle(x1,y1,x2,y2,x3,y3,MyRand(),MyRand(),MyRand());
		tF.filledTriangle(x1,y1,x2,y2,x3,y3,MyRand(),MyRand(),MyRand());
	}

	{
		epswriter s("square.eps", xMin, yMin, xMax, yMax);
		epswriter sF("squareFilled.eps", xMin, yMin, xMax, yMax);
			
		const double leftDownX = -.5, leftDownY=-.5;
		const double rightUpX = .5, rightUpY = .5;
		s.square(leftDownX, leftDownY, rightUpX, rightUpY,MyRand(),MyRand(),MyRand());
		sF.filledSquare(leftDownX, leftDownY, rightUpX, rightUpY,MyRand(),MyRand(),MyRand());
	}

	{
		epswriter l("line.eps", xMin, yMin, xMax, yMax);
		epswriter ml("multiline.eps",xMin, yMin, xMax, yMax);

		const double lineWidth = .05;
		const double x0 = -1, y0=-1;
		const double xf = .5, yf=1.0;
		std::vector<double> x,y;
		x.push_back(.5);x.push_back(.7); x.push_back(.9);
		y.push_back(-.3);y.push_back(.4); y.push_back(0);

		l.line(x0,y0,xf,yf, lineWidth, MyRand(),MyRand(),MyRand());
		ml.multiline(x,y, lineWidth, MyRand(),MyRand(),MyRand());
	}

}
