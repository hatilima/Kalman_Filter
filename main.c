#include "afro_kalman.h" // Make sure to include a Kalman filter library for C
#include <math.h>
#include<stdint.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

// MPU6050 raw sensor values struct
typedef struct {
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
    int16_t acce_x;
    int16_t acce_y;
    int16_t acce_z;
} MPU6050Data;

// Kalman filter variables
KalmanFilter kalmanRoll;

// Function to initialize the Kalman filter
void initKalmanFilter() {
    // Initialize the Kalman filter parameters
    kalmanRoll.Q_angle = 0.001;
    kalmanRoll.Q_bias = 0.003;
    kalmanRoll.R_measure = 0.03;
    kalmanRoll.angle = 0.0;
    kalmanRoll.bias = 0.0;
    kalmanRoll.P[0][0] = 0.0;
    kalmanRoll.P[0][1] = 0.0;
    kalmanRoll.P[1][0] = 0.0;
    kalmanRoll.P[1][1] = 0.0;
}

// Function to update the Kalman filter with new sensor data
void updateKalmanFilter(MPU6050Data sensorData) {
    // Convert raw gyro data to degrees per second
    float gyroRate = sensorData.gyro_x / 131.0;

    // Calculate time between readings (assumes a constant sample rate)
    float dt = 0.01;  // Update this value based on your actual sampling rate

    // Predict the roll angle using the gyro rate
    kalmanPredict(&kalmanRoll, gyroRate, dt);

    // Measure the roll angle using accelerometer data
    float roll = atan2(sensorData.acce_y, sensorData.acce_z) * (180.0 / M_PI);

    // Update the Kalman filter with the measured roll angle
    kalmanUpdate(&kalmanRoll, roll);

    // Get the filtered roll angle from the Kalman filter
    float filteredRoll = kalmanRoll.angle;

    // Now, you can use filteredRoll as the output
}

int main() {
    // Initialize the Kalman filter
    initKalmanFilter();

    // Read sensor data from MPU6050
    MPU6050Data sensorData;

    // ... Code to read sensor data ...

    // Update Kalman filter with sensor data
    updateKalmanFilter(sensorData);

    // The filtered angles are now available for use

    return 0;
}
