// afro_kalman.h

#ifndef AFRO_KALMAN_H
#define AFRO_KALMAN_H

#include<stdint.h>

typedef struct {
    float Q_angle;  // Process noise covariance for the angle
    float Q_bias;   // Process noise covariance for the bias
    float R_measure; // Measurement noise covariance

    float angle;    // The angle calculated by the Kalman filter
    float bias;     // The gyro bias calculated by the Kalman filter
    float P[2][2];  // Error covariance matrix
} KalmanFilter;

void kalmanPredict(KalmanFilter* filter, float gyroRate, float dt);
void kalmanUpdate(KalmanFilter* filter, float measurement);

#endif // AFRO_KALMAN_H