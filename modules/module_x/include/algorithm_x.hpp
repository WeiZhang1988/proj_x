#ifndef ALGORITHM_X_HPP
#define ALGORITHM_X_HPP

#include <vector>

class Catalan {
public:
  typedef struct {
    int method;
  } Configuration;

  Catalan(const Configuration& config);
    
  // Core processing function
  std::vector<int> process(const int& input);
  
  // Configuration updates
  void updateConfiguration(const Configuration& new_config);

private:
  Configuration config_;
    
};

class PID {
public:
  PID(double kp, double ki, double kd);
  double calculate(double setpoint, double current_value, double dt);
  void reset();
private:
  double kp_, ki_, kd_, pre_err_, integral_;
};

#endif // FIBONACCI_HPP