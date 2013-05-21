#ifndef EPSWRITER_HPP
#define EPSWRITER_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <memory>

struct WriterDeleter {
	void operator()(std::ofstream* of) {
		*of << "showpage" << std::endl;
		delete of;
	}
};

class epswriter {

	private:
		int currRed;
		int currGreen;
		int currBlue;
		double lineWidth;
		std::shared_ptr<std::ofstream> eps;
		std::string name;

		bool equalCurrColor(int r, int g, int b);
		void changeColor(int r, int g, int b);
		void drawBasicTriangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue);

		void drawBasicSquare(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue);
		void drawBasicCircle(double xcentre, double ycentre, double radius, int red, int green, int blue);
	public:

		epswriter(std::string fileName, double minX, double minY, double maxX, double maxY);
		~epswriter();
		void line(double xfrom, double yfrom, double xto, double yto, double width, int red, int green, int blue);
		void multiline (const std::vector<double>& x, const std::vector<double>& y, double width, int red, int green, int blue);

		void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue);
		void filledTriangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue);
		
		void square(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue);
		void filledSquare(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue);
		
		void circle(double xcentre, double ycentre, double radius, int red, int green, int blue);
		void filledCircle(double xcentre, double ycentre, double radius, int red, int green, int blue);


};
#endif
