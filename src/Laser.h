#ifndef LASER_H
#define LASER_H

#include <cmath>

#include "PicParams.h"

const double PI2 = 8.*atan(1.);

class Laser {
public:

    Laser(double, std::vector<double>, LaserStructure);

    LaserStructure laser_struct;

    double pi_ov_2;

    double a0_delta_y_;
    double a0_delta_z_;

    std::string         boxSide;
    double              angle;
    std::string         type_of_time_profile;
    std::string         type_of_y_profile;
    std::vector<int>    int_params;
    std::vector<double> double_params;

    std::string         type_of_transv_profile;
    std::vector<int>    int_params_transv;
    std::vector<double> double_params_transv;
    
    double time_profile(double);
    double transverse_profile2D(double, double);

};

#endif

