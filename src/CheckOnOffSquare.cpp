/*
 * CheckOnOffSquare.cpp
 *
 *  Created on: 2017/04/11
 *      Author: labuser
 */

#include "CheckOnOffSquare.h"

CheckOnOffSquare::CheckOnOffSquare() {
	// TODO Auto-generated constructor stub

}

CheckOnOffSquare::~CheckOnOffSquare() {
	// TODO Auto-generated destructor stub
}

#include <iostream>
#include <math.h>
using namespace std;

double computeLength(double xPointA, double yPointA, double xPointB, double yPointB) {

	double distance;

	// Apply Pythagorean on distance between two points
	distance = sqrt(pow((xPointA-xPointB), 2) + pow((yPointA-yPointB), 2));
	return distance ;
}

void checkQuadrilateral(int xRange, int yRange, double widthQuadrilateral, double heightQuadrilateral,
		double xCircle, double yCircle, double diameter, double peripheryConstraint,
		double radius, double ratioRadius) {

	double constraintValue, distanceCenter;
	double xQuadrilateral, yQuadrilateral;
	int count = 0;

	cout << "Area within circle: " << endl;
	cout << "Area " << "  X index " << "  Y Index" << endl;
	// cout << "Shape Result: 1 represent square within circle" << endl;

	for (int i=yRange; i>=1; i= i-1) {   // yPosition of quadrilateral
		for (int j=1; j<=xRange; j=j+1) {   // xPosition of quadrilateral

			xQuadrilateral = ((2*double(j))-1)/2;
			yQuadrilateral = ((2*double(i))-1)/2;

			distanceCenter = computeLength(xCircle, yCircle, xQuadrilateral, yQuadrilateral);
			constraintValue = ratioRadius - peripheryConstraint;

			if(distanceCenter < constraintValue) {
				cout << 1;
				/*
				cout << count << "        " << j-1 << "        " << i-1 << endl;
				count ++; */
			} else {
				cout << 0;

			}
		} cout << endl;
	}
	cout << endl << "Number of quadrilateral inside circle: "<< count << endl;
}

int main() {

	int xNum, yNum;
	int checkInputMin, checkInputMax;
	double diameter, peripheryConstraint, radius, ratioRadius;
	double xCircle, yCircle, xEdgeQuadrilateral, yEdgeQuadrilateral, widthQuadrilateral, heightQuadrilateral;

	// Use to calculate the scale radius
	yEdgeQuadrilateral = 0;

	cout << "Please input diameter, xNum, yNum." << endl;
	cin >>  diameter >> xNum >> yNum;
	cout << endl;

	// xNum and yNum is the number of quadrilateral on X and Y.
	xEdgeQuadrilateral = double(xNum)/2;
	radius = diameter/2;

	widthQuadrilateral = diameter / double(xNum);
	heightQuadrilateral = diameter / double(yNum);

	xCircle = double(xNum)/2;
	yCircle = double(yNum)/2;

	checkInputMin = 0.13*diameter;
	checkInputMax = 0.35*diameter;

	cout << "xNum: " << xNum << endl << "yNum: " << yNum << endl << endl;

	cout << "Minimum and maximum input for x and y number: " << checkInputMin
			<< " ~ " << checkInputMax <<  " with diameter " << diameter << endl << endl;

	// ratioRadius = computeLength(xCircle, yCircle, xEdgeQuadrilateral, yEdgeQuadrilateral);
	ratioRadius = computeLength(xCircle, yCircle, xEdgeQuadrilateral, yEdgeQuadrilateral);

	if((xNum<checkInputMin)||(xNum>checkInputMax) || (yNum<checkInputMin) ||(yNum>checkInputMax)) {
		cout << "xNum and yNum is not fitted to define quadrilateral within square." << endl;
	} else {
		if (widthQuadrilateral == heightQuadrilateral) {
				// Calculate peripheral value to define the constraint within circle
				peripheryConstraint = computeLength(widthQuadrilateral, heightQuadrilateral, 0, 0) / 8;

				// Status of square in association with circle
				cout << "Statistical Information" << endl;
				cout << "Number of square is " << xNum*yNum <<endl;
				cout << "Number of quadrilateral on X-axis: " << xNum << endl;
				cout << "Number of quadrilateral on Y-axis: " << yNum << endl;
				cout << "Center of circle with X, and Y: " << xCircle << " " << yCircle <<endl ;
				cout << "Radius of circle: " << radius << endl;
				cout << "Ratio Radius: " << ratioRadius << endl;
				cout << "Width of quadrilateral: " << widthQuadrilateral << endl;
				cout << "Height of quadrilateral: " << heightQuadrilateral << endl;
				cout << "Periphery constraint for boundary check: " << peripheryConstraint << endl << endl;

				// Check the InOut status of quadrilateral within circle
				checkQuadrilateral(xNum, yNum, widthQuadrilateral, heightQuadrilateral, xCircle, yCircle,
						diameter, peripheryConstraint, radius, ratioRadius);
		} else {
				// Calculate peripheral value to define the constraint within circle
				peripheryConstraint = computeLength(widthQuadrilateral, heightQuadrilateral, 0, 0) / 8;

				// Status of rectangular in association with circle
				cout << "Statistical Information" << endl;
				cout << "Number of rectangular is " << xNum*yNum << endl;
				cout << "Number of quadrilateral on X-axis: " << xNum << endl;
				cout << "Number of quadrilateral on Y-axis: " << yNum << endl;
				cout << "Center of circle with X, and Y: " << xCircle << " " << yCircle <<endl ;
				cout << "Radius of circle: " << radius << endl;
				cout << "Ratio Radius: " << ratioRadius << endl;
				cout << "Width of quadrilateral: " << widthQuadrilateral << endl;
				cout << "Height of quadrilateral: " << heightQuadrilateral << endl;
				cout << "Periphery constraint for boundary check: " << peripheryConstraint << endl << endl;

				// Check the InOut status of quadrilateral within circle
				checkQuadrilateral(xNum, yNum, widthQuadrilateral, heightQuadrilateral, xCircle, yCircle,
						diameter, peripheryConstraint, radius, ratioRadius);
		}
	}
	cout << endl << "Done";

	return 0;
}
