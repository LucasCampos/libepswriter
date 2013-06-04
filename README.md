libepswriter
========

Simple eps generator. The interface was based on libpngwriter.

#Compiling

This library requires only a modern compiler, with C++11 features enabled.

#Usage

First, one needs to create a epswriter object. The interface to the constructor is

```c++
 epswriter(std::string fileName, double minX, double minY, double maxX, double maxY);
 ```

after which a file named fileName will be created, with boundaries defined by the rectangle with left-down vertex on
(minX, minY) and right-up vertex on (minX, maxX). Then, just use the drawing functions, explained in the next section.

#Drawing Functions

##General Notes

The colors are always integers, varying from 0 to 65535. For now, it is left to the user the duty to obey these limits. 

##Lines

```c++
void line(double xfrom, double yfrom, double xto, double yto, double width, int red, int green, int blue);
void multiline (const std::vector<double>& x, const std::vector<double>& y, double width, int red, int green, int blue);
```

The first function, line, just draws a simple line, starting at (xfrom, yfrom), and ending at (xto, yto). 
Multiline draws a set of connected lines, with coordinates defined by the vectors x and y. 
This function does not need them to be of the same size, and will halt after the smallest vector ends.

##Triangles

```c++
void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue);
void filledTriangle(double x1, double y1, double x2, double y2, double x3, double y3, int red, int green, int blue);
```

Draws a triangle, with vertex given by (x1,y1), (x2,y2), (x3,y3).

##Squares

```c++
void square(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue);
void filledSquare(double xfrom, double yfrom, double xto, double yto, int red, int green, int blue);
```
This function is actually a misnomer. It draws a rectangle, with left-down corner on (xfrom, yfrom), and right-up corner on (xto, yto)

##Circles

```c++
void circle(double xcentre, double ycentre, double radius, int red, int green, int blue);
void filledCircle(double xcentre, double ycentre, double radius, int red, int green, int blue);
```

Draws a circle, centred on (xcentre, ycentre), with given radius

##Text
```c++
void writeText(double x, double y, std::string text, double font, int red, int green, int blue);
```

Write a given string, with font as fontSize, in box coordinates.

#Known bugs

When drawing circles, a horizontal line appears in the center of the circle.
