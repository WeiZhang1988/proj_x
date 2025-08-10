#include "algorithm_x.hpp"

Catalan::Catalan(const Configuration& config) : config_(config) {}

std::vector<int> Catalan::process(const int& input) {
  std::vector<int> res = {1};
  switch (config_.method) {
    case 0:
      for (int i=0; i<input; i++) {
        res.push_back(res[i]*(4*i+2)/(i+2));
      }
      break;
    case 1:
      for (int i=0; i<input; i++) {
        res.push_back(res[i]*(4*i+2)/(i+2) + 1);  //  add one to make it wrong
      }
      break;
    default:
      for (int i=0; i<input; i++) {
        res.push_back(res[i]*(4*i+2)/(i+2));
      }
      break;
  }
  return res;
}
    
// Configuration updates
void Catalan::updateConfiguration(const Configuration& new_config) {
    config_ = new_config;
}

PID::PID(double kp, double ki, double kd) : kp_(kp), ki_(ki), kd_(kd), pre_err_(0.0), integral_(0.0) {}

double PID::calculate(double setpoint, double current_value, double dt) {
  double error = setpoint - current_value;
  double P = kp_ * error;
  integral_ += error * dt;
  double I = ki_ * integral_;
  double D = kd_ * (error - pre_err_) / dt;
  pre_err_ = error;
  return P + I + D;
}

void PID::reset() {
  integral_ = 0.0;
  pre_err_ = 0.0;
}