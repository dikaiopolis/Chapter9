//
//  main.c
//  PBR
//
//  Created by Daniel Baldwin on 8/12/13.
//  Copyright (c) 2013 Daniel Baldwin. All rights reserved.
//

#include <stdio.h>
#include <math.h>

    void cartesianToPolar(double x, double y, double *rPtr, double *thetaPtr)
{
    
    //Is rPtr non-Null?
    if (rPtr) {
    //Store the radius in the supplied address
    *rPtr = sqrt(x * x + y * y);
    }
    
    //Is thetaPtr NULL?
    if (!thetaPtr) {
        //Skip the rest of the function
        return;
    }
    
    //Calculate theta
    double theta;
    if (x == 0.0) {
        if (y == 0.0) {
        theta = 0.0; //techhnically considered undefined
        } else if (y > 0 ) {
        theta = M_PI_2;
        }
    } else {
        theta = atan(y/x);
    }
    //Store theta in the supplied address
    *thetaPtr = theta;
    }


    int main(int argc, const char * argv[])
{
    double pi = 3.14;
    double integerPart;
    double fractionPart;
    
    //Pass the address of integerPart as an argument
    fractionPart = modf(pi, &integerPart);
    
    //Find the value stored in integerPart
    printf("integerPart = %.0f, fractionPart = %.2f\n", integerPart, fractionPart);
    
    double x = 3.0;
    double y = 4.0;
    double radius;
    double angle;
    
    cartesianToPolar(x, y, &radius, &angle);
    printf("(%.2f, %.2f) becomes (%.2f, %.2f radians)\n", x, y, radius, angle);
    
    return 0;
}

