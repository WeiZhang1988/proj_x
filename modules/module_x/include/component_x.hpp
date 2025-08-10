#ifndef COMPONENT_X_H
#define COMPONENT_X_H

#include <memory>
#include <string>
#include <map>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "lifecycle_msgs/msg/state.hpp"
#include "lifecycle_msgs/msg/transition.hpp"
#include "module_interface/action/simple_action.hpp"

#include "algorithm_x.hpp"

using namespace std::chrono_literals;
using SimpleAction = module_interface::action::SimpleAction;
using GoalHandle = rclcpp_action::ServerGoalHandle<SimpleAction>;

enum class OperationalState {
  UNCONFIGURED,
  STANDBY,
  ACTIVE,
  ERROR,
  EMERGENCY_STOP
};

class AlgorithmXWrapper : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit AlgorithmXWrapper(const std::string & node_name);

  // Callback for timer (only active when node is activated)
  void timerCallback();

  // Transition callback for state configuring
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &) override;
  // Transition callback for state activating
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State &) override;
  // Transition callback for state deactivating
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &) override;
  // Transition callback for state cleaning up
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State &) override;
  // Transition callback for state shutting down
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State & state) override;

  bool transitionToState(OperationalState new_state);
  void handleActivateRequest(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response);
  void handleStandbyRequest(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response);
  void handleEmergencyStop(const std::shared_ptr<std_srvs::srv::Trigger::Request> request, const std::shared_ptr<std_srvs::srv::Trigger::Response> response);
  

private:
  std::shared_ptr<rclcpp::TimerBase> timer_;
  OperationalState current_op_state_;
  std::map<std::pair<OperationalState, OperationalState>, std::string> valid_transitions_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr activate_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr standby_srv_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr emergency_stop_srv_;
  rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub_;
  rclcpp_action::Server<SimpleAction>::SharedPtr action_server_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_; 
  size_t message_count_;
  std::shared_ptr<Catalan> cat_;
  std::shared_ptr<PID> pid_;
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;
  double target_speed_;

  void declareParameters();
  rcl_interfaces::msg::SetParametersResult parametersCallback(const std::vector<rclcpp::Parameter> &parameters);
  void initializeStateTransitions();
  void executeEntryActions(OperationalState state);
  void executeExitActions(OperationalState state);
  void publishState();
  std::string stateToString(OperationalState state);
  rclcpp_action::GoalResponse handleGoal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const SimpleAction::Goal> goal);
  rclcpp_action::CancelResponse handleCancel(const std::shared_ptr<GoalHandle> goal_handle);
  void handleAccepted(const std::shared_ptr<GoalHandle> goal_handle);
  void execute(const std::shared_ptr<GoalHandle> goal_handle);
  void messageCallback(const std_msgs::msg::String::SharedPtr msg);
};

#endif