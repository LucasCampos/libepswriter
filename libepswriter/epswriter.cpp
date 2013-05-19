#include "epswriter.hpp"

epswriter::epswriter(std::string fileName, double minX, double minY, double maxX, double maxY): name(fileName), currRed(0), currGreen(0), currBlue(0){

	eps.open(fileName.data());

	//Writes eps header
	eps << " %!PS-Adobe-3.0 EPSF-3.0 " << std::endl;
	eps << "%%Pages: 1" << std::endl;
	eps << "%%BoundingBox: " << minX << " " << minY << " " << maxX << " " << maxY << std::endl;
	eps << "%%LanguageLevel: 1" << std::endl;
	eps << "%%EndComments" << std::endl << std::endl;

	eps << "0 0 0 setrgbcolor" << std::endl << std::endl;
	eps << std::min(maxX-minX, maxY-minY)/20 << " setlinewidth " << std::endl;

}

epswriter::~epswriter() {
	eps << "showpage" << std::endl;
}

bool epswriter::equalCurrColor(int r, int g, int b) {
	bool t = true;
	t&= (r==currRed);
	t&= (g==currGreen);
	t&= (b==currBlue);

	return t;
}

void epswriter::changeColor(int r, int g, int b) {
	if (!equalCurrColor(r,g,b))
		eps << r << " " << g << " " << b << " setrgbcolor" << std::endl;
}


void epswriter::line(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue){
	changeColor(red,green,blue);
	eps << xfrom << " " << yfrom << " moveto " << std::endl;
	eps << xto << " " << yto << " lineto " << std::endl;
	eps << "stroke " << std::endl;

}

void epswriter::multiline (const std::vector<double>& x, const std::vector<double>& y, int red, int green, int blue) {
	changeColor(red,green,blue);
	if ((x.size() > 0) && (y.size() > 0))
		eps << x[0] << " " << y[0] << " moveto" << std::endl;
	for (int i=1; i<std::min(x.size(),y.size()); i++)
		eps << x[i] << " " << y[i] << " lineto" << std::endl;
	eps << "stroke" << std::endl;
}

void epswriter::drawBasicTriangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue) {

	changeColor(red,green,blue);

	eps << x1 << " " << y1 << " moveto" << std::endl;
	eps << x2 << " " << y2 << " lineto" << std::endl;
	eps << x3 << " " << y3 << " lineto" << std::endl;
	eps << "closepath " << std::endl;
}

void epswriter::triangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue) {
	drawBasicTriangle(x1,y1,x2,y2,x3,y3, red, green, blue);
	eps << "stroke" << std::endl;
}

void epswriter::filledTriangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue) {
	drawBasicTriangle(x1,y1,x2,y2,x3,y3, red, green, blue);
	eps << "fill" << std::endl;
}

void epswriter::drawBasicSquare(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue) {
	
	changeColor(red,green,blue);
	eps << xfrom << " " << yfrom << " moveto" << std::endl;
	eps << xto << " " << yfrom << " lineto" << std::endl;
	eps << xto << " " << yto << " lineto" << std::endl;
	eps << xfrom << " " << yto << " lineto" << std::endl;
	eps << "closepath" << std::endl;
}

void epswriter::square(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue) {
	drawBasicSquare(xfrom, yfrom, xto, yto, red,green, blue);
	eps << "stroke" << std::endl;
}

void epswriter::filledSquare(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue) {
	drawBasicSquare(xfrom, yfrom, xto, yto, red,green, blue);
	eps << "fill" << std::endl;
}


void epswriter::drawBasicCircle(double xcentre, double ycentre, double radius, int red, int green, int blue) {

	changeColor(red,green,blue);
	eps << xcentre << " " << ycentre << " moveto" << std::endl;
	eps << xcentre << " " << ycentre << " " << radius << " 0 360 arc" << std::endl;
	eps << "closepath" << std::endl;
}

void epswriter::circle(double xcentre, double ycentre, double radius, int red, int green, int blue) {
	drawBasicCircle(xcentre, ycentre, radius, red, green, blue);
	eps << "stroke" << std::endl;
}

void epswriter::filledCircle(double xcentre, double ycentre, double radius, int red, int green, int blue) {
	drawBasicCircle(xcentre, ycentre, radius, red, green, blue);
	eps << "fill" << std::endl;
}