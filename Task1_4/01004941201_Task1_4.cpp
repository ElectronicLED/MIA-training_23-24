/*
 * File: filename.c
 * Author: Nour ElDeen Shalaby
 * Description: Brief description of the purpose of this code file.
 * Date: 14/8/2023
 */

/*Initial Velocity: 30m/s
  Initial Angle: 46 deg */

/* Header Files */
#include <bits/stdc++.h>

using namespace std;


float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26}; //79%
float bno55[10] =   {0.0,  9.49, 16.36, 21.2 , 23.16, 22.8 , 19.5 , 14.85,  6.79, -2.69}; //92%


/* Main Function */
int main()
{
    float fusedData[10];

    /*good method*/
    //mpu6050 weight = 0.79/(0.79+0.92) = 0.462
    //bno55 weight  = 0.92/(0.79+0.92) = 0.538

    cout<<"Good Method data"<<endl;
    for(int i=0; i<10;i++){

        fusedData[i] = mpu6050[i] * 0.462 + bno55[i] * 0.538 ;

        cout<<fusedData[i]<<endl;
    }


    /*Hero Method*/
    cout<<"\n\nHero Method data"<<endl;
    //assume all initial values are 0
    //mpu6050 is the estimate
    //bno55 is the measurement
    float previous_est = 0;
    float measurement = 0;

    #define error_EST 0.21
    #define error_measurement 0.08

    //KG = error_EST / (error_EST+ error_measurement)
    float KG = error_EST / (error_EST+ error_measurement); //error is constant so kalman gain is constant

    //EST = previous_est + KG*(measurement - previous_est)
    float EST = previous_est + KG*(measurement - previous_est);
    //error_EST = (1-KG)* previous_error_EST


    /*
    since the error of both measurement and estimate are both constant
    the results will should be exactly the same as the previous mehtod
    */


    for(int i = 1; i<10 ; i++){

            fusedData[i] = fusedData[i-1] + KG*(bno55[i] - fusedData[i-1]);
            cout<<fusedData[i]<<endl;
    }



    return 0;


}
