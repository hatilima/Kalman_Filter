// kalman.c

#include "afro_kalman.h"
#include <math.h>
#include<stdint.h>

void kalmanPredict(KalmanFilter* filter, float gyroRate, float dt) {
    // Predict the state
    filter->angle += dt * (gyroRate - filter->bias);

    // Update the error covariance matrix
    filter->P[0][0] += dt * (dt * filter->P[1][1] - filter->P[0][1] - filter->P[1][0] + filter->Q_angle);
    filter->P[0][1] -= dt * filter->P[1][1];
    filter->P[1][0] -= dt * filter->P[1][1];
    filter->P[1][1] += filter->Q_bias * dt;
}

void kalmanUpdate(KalmanFilter* filter, float measurement) {
    // Calculate Kalman gain
    float S = filter->P[0][0] + filter->R_measure;
    float K[2]; // Kalman gain vector
    K[0] = filter->P[0][0] / S;
    K[1] = filter->P[1][0] / S;

    // Update the state and error covariance matrix
    float y = measurement - filter->angle;
    filter->angle += K[0] * y;
    filter->bias += K[1] * y;

    filter->P[0][0] -= K[0] * filter->P[0][0];
    filter->P[0][1] -= K[0] * filter->P[0][1];
    filter->P[1][0] -= K[1] * filter->P[0][0];
    filter->P[1][1] -= K[1] * filter->P[0][1];
}
