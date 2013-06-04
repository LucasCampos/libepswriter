/*
 *     This file is part of libepswriter.
 *
 *     libepswriter is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * */

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
		double fontSize;
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
		
		void writeText(double x, double y, std::string text, double font, int red, int green, int blue);


};
#endif
