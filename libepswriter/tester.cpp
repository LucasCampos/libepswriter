#include "epswriter.hpp"

int main() {

	epswriter c("circle.eps", -1, -1, 1, 1);
	epswriter cF("circleF.eps", -1, -1, 1, 1);

	c.circle(0,0,.5,150,0,0);
	cF.filledCircle(.5,.5,.5,150,0,0);

	epswriter t("triangle.eps", -1,-1, 1,1);
	epswriter tF("triangleFilled.eps", -1, -1, 1,1);

	t.triangle(0, .5, 
		-.25, -.25, 
		.25, -.25, 
		150, 0, 0);
	tF.filledTriangle(0, .5, -.25, -.25, .25, -.25, 150, 0, 0);

	epswriter s("square.eps", -1, -1, 1, 1);
	epswriter sF("squareFilled.eps", -1, -1, 1, 1);

	s.square(-.5, -.5, .5, .5, 0, 150, 0);
	sF.filledSquare(-.5, -.5, .5, .5, 0, 150, 0);

	epswriter l("line.eps", -1, -1, 1, 1);
	epswriter ml("multiline.eps",-1,-1,1,1);

	std::vector<double> x,y;
	x.push_back(.5);x.push_back(.7); x.push_back(.9);
	y.push_back(-.3);y.push_back(.4); y.push_back(0);
	
	l.line(-1,-1, .5, 1.0, 0.05, 0, 140, 230);
	ml.multiline(x,y, 0.05, 240, 120, 10);

}
