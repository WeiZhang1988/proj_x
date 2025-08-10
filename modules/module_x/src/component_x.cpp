#include "component_x.hpp"

using namespace std::chrono_literals;

AlgorithmXWrapper::AlgorithmXWrapper(const std::string & node_name) : \
rclcpp_lifecycle::LifecycleNode(node_name), current_op_state_(OperationalState::UNCONFIGURED) {
  // Declare parameters
  declareParameters();

  // Create services for state control
  activate_srv_ = create_service<std_srvs::srv::Trigger>("activate", 
  std::bind(&AlgorithmXWrapper::handleActivateRequest, this, std::placeholders::_1, std::placeholders::_2));
  standby_srv_ = create_service<std_srvs::srv::Trigger>("standby", 
  std::bind(&AlgorithmXWrapper::handleStandbyRequest, this, std::placeholders::_1, std::placeholders::_2));
  emergency_stop_srv_ = create_service<std_srvs::srv::Trigger>("emergency_stop", 
  std::bind(&AlgorithmXWrapper::handleEmergencyStop, this, std::placeholders::_1, std::placeholders::_2));
  
  // Create state publisher
  state_pub_ = create_publisher<std_msgs::msg::String>("operational_state", 10);

  // Create subscription
  sub_ = create_subscription<std_msgs::msg::String>("lifecycle_topic", 10, std::bind(&AlgorithmXWrapper::messageCallback, this, std::placeholders::_1));
  message_count_ = 0;

  // Create action service
  action_server_ = rclcpp_action::create_server<module_interface::action::SimpleAction>(
    this,
    "simple_action_server",
    std::bind(&AlgorithmXWrapper::handleGoal, this, std::placeholders::_1, std::placeholders::_2),
    std::bind(&AlgorithmXWrapper::handleCancel, this, std::placeholders::_1),
    std::bind(&AlgorithmXWrapper::handleAccepted, this, std::placeholders::_1));

  // Initialize state transition map
  initializeStateTransitions();

  // create algorithm
  Catalan::Configuration conf;
  cat_ = std::make_shared<Catalan>(conf);
  RCLCPP_INFO(get_logger(), "Node constructed");
}

  // Callback for timer (only active when node is activated)
void AlgorithmXWrapper::timerCallback() {
  static size_t count = 0;
  auto msg = std_msgs::msg::String();
  msg.data = "#" + std::to_string(++count) + "\n";
  // Get parameter value
  int param_num = get_parameter("param_num").as_int();
  auto res = cat_->process(param_num);
  msg.data += "<=== Catalan of " + std::to_string(param_num) + " is ";
  for (auto item : res) {
    msg.data += std::to_string(item) + ", ";
  }
  msg.data += " ===>";
  if (!pub_->is_activated()) {
    RCLCPP_INFO(get_logger(), "Lifecycle node is currently inactive. Messages are not published.");
  } else {
    RCLCPP_INFO(get_logger(), "Lifecycle node is active. Publishing: [%s]", msg.data.c_str());
  }
  pub_->publish(msg);
}

  // Transition callback for state configuring
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn AlgorithmXWrapper::on_configure(const rclcpp_lifecycle::State &) {
  RCLCPP_INFO(get_logger(), "Configuring...");
  
  // Get parameter value
  int param_method = get_parameter("param_method").as_int();
  int param_num = get_parameter("param_num").as_int();
  double target_speed = get_parameter("target_speed").as_double();
  RCLCPP_INFO(get_logger(), "param_methd: %d, param_num: %d, target_speed: %lf", param_method, param_num, target_speed);
  
  // Initialize resources
  try {
    // Simulate resource initialization
    RCLCPP_INFO(get_logger(), "Initializing resources...");

    // Create a timer (will be managed by lifecycle)
    timer_ = create_wall_timer(1s, std::bind(&AlgorithmXWrapper::timerCallback, this));

    // Create a publisher (will be managed by lifecycle)
    pub_ = create_publisher<std_msgs::msg::String>("lifecycle_topic", 10);

    // create algorithm
    Catalan::Configuration conf;
    conf.method = param_method;
    cat_->updateConfiguration(conf);
    
    // Return success
    RCLCPP_INFO(get_logger(), "Configuration completed successfully");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  } catch (...) {
    RCLCPP_ERROR(get_logger(), "Failed to initialize resources");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::FAILURE;
  }
}

  // Transition callback for state activating
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn AlgorithmXWrapper::on_activate(const rclcpp_lifecycle::State &state) {
  RCLCPP_INFO(get_logger(), "Activating...");
  
  // Activate resources
  pub_->on_activate();
  timer_->reset();

  LifecycleNode::on_activate(state);
  
  // Return success
  RCLCPP_INFO(get_logger(), "Activation completed successfully");
  return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

  // Transition callback for state deactivating
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn AlgorithmXWrapper::on_deactivate(const rclcpp_lifecycle::State &state) {
  RCLCPP_INFO(get_logger(), "Deactivating...");
  
  // Deactivate resources
  pub_->on_deactivate();
  timer_->cancel();
  LifecycleNode::on_deactivate(state);
  
  // Return success
  RCLCPP_INFO(get_logger(), "Deactivation completed successfully");
  return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

  // Transition callback for state cleaning up
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn AlgorithmXWrapper::on_cleanup(const rclcpp_lifecycle::State &) {
  RCLCPP_INFO(get_logger(), "Cleaning up...");
  
  // Clean up resources
  timer_.reset();
  pub_.reset();
  
  // Return success
  RCLCPP_INFO(get_logger(), "Cleanup completed successfully");
  return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

  // Transition callback for state shutting down
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn AlgorithmXWrapper::on_shutdown(const rclcpp_lifecycle::State & state) {
  RCLCPP_INFO(get_logger(), "Shutting down from state %s", state.label().c_str());
  
  // Shut down resources
  if (state.id() == lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE) {
    on_deactivate(state);
  }
  
  timer_.reset();
  pub_.reset();
  
  // Return success
  RCLCPP_INFO(get_logger(), "Shutdown completed");
  return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

void AlgorithmXWrapper::messageCallback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "Received message #%zu: '%s'", message_count_++, msg->data.c_str());
}

bool AlgorithmXWrapper::transitionToState(OperationalState new_state) {
  // Check if transition is valid
  auto current_state = current_op_state_;
  auto transition_key = std::make_pair(current_state, new_state);
  
  if (valid_transitions_.find(transition_key) == valid_transitions_.end()) {
    RCLCPP_WARN(get_logger(), "Invalid state transition from %s to %s", stateToString(current_state).c_str(), stateToString(new_state).c_str());
    return false;
  }
  
  // Execute exit actions for current state
  executeExitActions(current_state);
  
  // Update state
  current_op_state_ = new_state;
  RCLCPP_INFO(get_logger(), "State changed from %s to %s", stateToString(current_state).c_str(), stateToString(new_state).c_str());
  
  // Execute entry actions for new state
  executeEntryActions(new_state);
  
  // Publish state change
  publishState();
  
  return true;
}

// Service callbacks
void AlgorithmXWrapper::handleActivateRequest(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
  (void)request; // unused
  
  if (transitionToState(OperationalState::ACTIVE)) {
    response->success = true;
    response->message = "Successfully activated";
  } else {
    response->success = false;
    response->message = "Failed to activate - invalid state transition";
  }
}

void AlgorithmXWrapper::handleStandbyRequest(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
  (void)request; // unused
  
  if (transitionToState(OperationalState::STANDBY)) {
    response->success = true;
    response->message = "Successfully moved to standby";
  } else {
    response->success = false;
    response->message = "Failed to standby - invalid state transition";
  }
}

void AlgorithmXWrapper::handleEmergencyStop(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
  (void)request; // unused
  
  if (transitionToState(OperationalState::EMERGENCY_STOP)) {
    response->success = true;
    response->message = "Emergency stop activated";
  } else {
    response->success = false;
    response->message = "Failed to emergency stop - invalid state transition";
  }
}

void AlgorithmXWrapper::declareParameters() {
  declare_parameter("param_method", 0);
  declare_parameter("param_num", 0);
  rcl_interfaces::msg::ParameterDescriptor param_desc;
  param_desc.description = "Movement speed (0.1-5.0 m/s)";
  param_desc.floating_point_range.resize(1);
  param_desc.floating_point_range[0].from_value = 0.1;
  param_desc.floating_point_range[0].to_value = 5.0;
  param_desc.floating_point_range[0].step = 0.1;
  declare_parameter("target_speed", 1.0, param_desc);
  target_speed_ = get_parameter("target_speed").as_double();
  param_callback_handle_ = add_on_set_parameters_callback(
  std::bind(&AlgorithmXWrapper::parametersCallback, this, std::placeholders::_1));
}

rclcpp_action::GoalResponse AlgorithmXWrapper::handleGoal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const SimpleAction::Goal> goal) {
  RCLCPP_INFO(get_logger(), "Received goal request with order %d", goal->goal);
  (void)goal;
  (void)uuid;
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}
rclcpp_action::CancelResponse AlgorithmXWrapper::handleCancel(const std::shared_ptr<GoalHandle> goal_handle) {
  RCLCPP_INFO(get_logger(), "Received request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}
void AlgorithmXWrapper::handleAccepted(const std::shared_ptr<GoalHandle> goal_handle) {
  std::thread{std::bind(&AlgorithmXWrapper::execute, this, std::placeholders::_1), goal_handle}.detach();
}
void AlgorithmXWrapper::execute(const std::shared_ptr<GoalHandle> goal_handle) {
  RCLCPP_INFO(get_logger(), "Executing goal");
  rclcpp::Rate loop_rate(1);
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<SimpleAction::Feedback>();
  auto & sequence = feedback->feedback;
  auto result = std::make_shared<SimpleAction::Result>();
  for (int i = 0; (i < goal->goal) && rclcpp::ok(); ++i) {
    // Check if there is a cancel request
    if (goal_handle->is_canceling()) {
      result->result = sequence;
      goal_handle->canceled(result);
      RCLCPP_INFO(get_logger(), "Goal canceled");
      return;
    }
    // Update sequence
    auto vec = cat_->process(i);
    sequence.push_back(vec[vec.size() - 1]);
    // Publish feedback
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(get_logger(), "Publish feedback");
    loop_rate.sleep();
  }
  // Check if goal is done
  if (rclcpp::ok()) {
    result->result = sequence;
    goal_handle->succeed(result);
    RCLCPP_INFO(get_logger(), "Goal succeeded");
  }
}


rcl_interfaces::msg::SetParametersResult AlgorithmXWrapper::parametersCallback(const std::vector<rclcpp::Parameter> &parameters) {
  auto result = rcl_interfaces::msg::SetParametersResult();
  result.successful = true;
  
  for (const auto &param : parameters) {
    if (param.get_name() == "target_speed") {
      if (param.as_double() < 0.1 || param.as_double() > 5.0) {
        result.successful = false;
        result.reason = "Target speed must be between 0.1 and 5.0";
        continue;
      }
      target_speed_ = param.as_double();
      RCLCPP_INFO(get_logger(), "Target speed parameter changed to: %.1f", target_speed_);
    }
  }
  return result;
}

void AlgorithmXWrapper::initializeStateTransitions() {
  // Define all valid state transitions
  valid_transitions_ = {
    // From UNCONFIGURED
    {{OperationalState::UNCONFIGURED, OperationalState::STANDBY}, "Initial configuration"},
    
    // From STANDBY
    {{OperationalState::STANDBY, OperationalState::ACTIVE}, "Normal operation"},
    {{OperationalState::STANDBY, OperationalState::ERROR}, "Error detected"},
    {{OperationalState::STANDBY, OperationalState::EMERGENCY_STOP}, "Emergency stop"},
    
    // From ACTIVE
    {{OperationalState::ACTIVE, OperationalState::STANDBY}, "Return to standby"},
    {{OperationalState::ACTIVE, OperationalState::ERROR}, "Error detected"},
    {{OperationalState::ACTIVE, OperationalState::EMERGENCY_STOP}, "Emergency stop"},
    
    // From ERROR
    {{OperationalState::ERROR, OperationalState::STANDBY}, "Error recovered"},
    {{OperationalState::ERROR, OperationalState::EMERGENCY_STOP}, "Emergency stop after error"},
    
    // From EMERGENCY_STOP
    {{OperationalState::EMERGENCY_STOP, OperationalState::STANDBY}, "Reset from emergency"}
  };
}

void AlgorithmXWrapper::executeEntryActions(OperationalState state) {
  switch (state) {
    case OperationalState::STANDBY:
      RCLCPP_INFO(get_logger(), "Entering STANDBY - reducing resource usage");
      // Implement standby-specific initialization
      break;
      
    case OperationalState::ACTIVE:
      RCLCPP_INFO(get_logger(), "Entering ACTIVE - full operation");
      // Implement active mode initialization
      break;
      
    case OperationalState::ERROR:
      RCLCPP_ERROR(get_logger(), "Entering ERROR state - safety measures activated");
      // Implement error handling procedures
      break;
      
    case OperationalState::EMERGENCY_STOP:
      RCLCPP_FATAL(get_logger(), "EMERGENCY STOP ACTIVATED!");
      // Implement emergency procedures
      break;
      
    default:
      break;
  }
}

void AlgorithmXWrapper::executeExitActions(OperationalState state) {
  switch (state) {
    case OperationalState::ACTIVE:
      RCLCPP_INFO(get_logger(), "Exiting ACTIVE - stopping operational tasks");
      // Clean up active operations
      break;
      
    case OperationalState::ERROR:
      RCLCPP_INFO(get_logger(), "Exiting ERROR state - recovery complete");
      // Clean up error state
      break;
      
    default:
      break;
  }
}

void AlgorithmXWrapper::publishState() {
  auto msg = std_msgs::msg::String();
  msg.data = stateToString(current_op_state_);
  state_pub_->publish(msg);
}

std::string AlgorithmXWrapper::stateToString(OperationalState state) {
  switch (state) {
    case OperationalState::UNCONFIGURED: return "UNCONFIGURED";
    case OperationalState::STANDBY: return "STANDBY";
    case OperationalState::ACTIVE: return "ACTIVE";
    case OperationalState::ERROR: return "ERROR";
    case OperationalState::EMERGENCY_STOP: return "EMERGENCY_STOP";
    default: return "UNKNOWN";
  }
}


int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<AlgorithmXWrapper>("algorithm_x_wrapper");
  
  // This spins both the node and executor in a multithreaded executor
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node->get_node_base_interface());
  executor.spin();
  
  rclcpp::shutdown();
  return 0;
}
