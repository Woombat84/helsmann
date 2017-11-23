//============================================================================
// Name        : hmm.cpp
// Author      : Mark
// Version     :
// Copyright   : Your copyright notice
// Description : Calculates the angel of a robot
//============================================================================

#include<cmath>
#include<iostream>

#define PI 3.14159265

using namespace std;

float lineAngle(float a, float b , float c, float d);
float constantLine(float a, float b, float c);
float distRobotline(float a, float b, float c,float d);
float angleRobot(float a, float b);
float callfuntionsangles(float a, float b, float c,float d, float e, float f,float g);

float ye = -0.0,xe =1.0, yw = 0.0, xw = 4.0, lh =2.0, yr = -2, xr = 5 ;

int main(){

      cout << callfuntionsangles(ye, yw, xe, xw, lh, yr, xr) << endl;
      cin;

return 0;
}


// Precondition: calculate angel between end-point and
// way-point need 4 inputs
// first y end-point, way-point,x end-point and way-point
// Postcondition: Output angel the line

float lineAngle(float a, float b , float c, float d){

      float angle = (a-b)/(c-d);
      cout << "Angel of line: 	 	" << angle<<  endl;
return angle;

}


// Precondition: calculate the constant in the line equation
// needs the end-point or way-point coordinates and the angel
// between end-point and way-point
// first input angel of line, x end or way-point,y end or
// way-point
// Postcondition: outputs the constant

float constantLine(float a, float b, float c ){

      float constantB = c-a*b;
      cout << "The constant b is:  	" << constantB << endl;
return constantB;
}

// Precondition: calculate the distance between the the
// robot and the angel between end-point and way-point.
// Using the distance formula it need's the angel of the line
// the constant and the robots x,y coordinate.
// first input angel of line,constant of line, x robot,
// y robot.
// Postcondition: output the distances.


float distRobotline(float a, float b, float c,float d){

      float dist = abs(a*c+b-d)/sqrt(pow(a,2)+1.0);
      cout << "Distance to line:	 " << dist << endl;
return dist;
}

// Precondition: calculate the angel of attack for the robot
// using the tanh(a/b) this needs the constant lookahead
// value and distance of the robot to line also conversion from radian to degrees.
// first input lookahead constant, distance between
// robot and line

float angleRobot(float a, float b){
      float robotAngle ;
      robotAngle = atan(a/b)*180 / PI;
      cout << "angle of triangle: 		" << robotAngle << endl;
return robotAngle;
}


// Precondition: calls the functions needed for calculating
// the angel of the triangle made by the lookahead robot location and the equation of the line.
// first y end-point, way-point,x end-point, way-point,
// lookahead constant and the robots x,y coordinate.
// Postcondition: Output the angel the robot needs to turn

float callfuntionsangles(float a, float b, float c,float d, float e, float f,float g){
      float lineA;
      float constL;
      float distR;
      float angleT;


            lineA   =   lineAngle     (a, b, c, d);
            constL  =   constantLine  (lineA, d, b);
            distR   =   distRobotline (lineA, constL, g, f);
            angleT  =   angleRobot    (e, distR);


return angleT;
}
// Precondition: calculate the desired angel
// input 1. angle of line 2. constant B 3.robot x 4.robot y
// 5.end-point x 6. way-point x 7.angleT
float desiredAngle(float a,float b,float c,float d,float e,float f,float g )
{
bool front = true;
bool positiveAngle = true;
bool overUnder = true;  // true if below line
bool frontBehind = true; // true if in front
float overUndersum = 0;
float angleR;

if (a < 0 ){				//  estimate positive or negative angle
	positiveAngle = false;
	}

overUndersum = a*c+b-d;    	// robot below or above line above if sum is negative
if (overUndersum > 0){

	overUnder = false;
}

if(positiveAngle == true){			//end point in front or behind robot
	if(e < f){
		front = false					// behind
			}
	}
if(positiveAngle == false){
	if(e < c){
		front = false;					//behind
	}
}



return angleR;
}
