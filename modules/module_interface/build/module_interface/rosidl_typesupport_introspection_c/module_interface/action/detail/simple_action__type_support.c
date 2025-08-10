// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from module_interface:action/SimpleAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
#include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "module_interface/action/detail/simple_action__functions.h"
#include "module_interface/action/detail/simple_action__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_Goal__init(message_memory);
}

void module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_member_array[1] = {
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_Goal, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_Goal",  // message name
  1,  // number of fields
  sizeof(module_interface__action__SimpleAction_Goal),
  module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_member_array,  // message members
  module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Goal)() {
  if (!module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_Goal__rosidl_typesupport_introspection_c__SimpleAction_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_Result__init(message_memory);
}

void module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_Result__fini(message_memory);
}

size_t module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__size_function__SimpleAction_Result__result(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Result__result(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_function__SimpleAction_Result__result(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__fetch_function__SimpleAction_Result__result(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Result__result(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__assign_function__SimpleAction_Result__result(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_function__SimpleAction_Result__result(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__resize_function__SimpleAction_Result__result(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_Result, result),  // bytes offset in struct
    NULL,  // default value
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__size_function__SimpleAction_Result__result,  // size() function pointer
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Result__result,  // get_const(index) function pointer
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__get_function__SimpleAction_Result__result,  // get(index) function pointer
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__fetch_function__SimpleAction_Result__result,  // fetch(index, &value) function pointer
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__assign_function__SimpleAction_Result__result,  // assign(index, value) function pointer
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__resize_function__SimpleAction_Result__result  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_Result",  // message name
  1,  // number of fields
  sizeof(module_interface__action__SimpleAction_Result),
  module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_member_array,  // message members
  module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Result)() {
  if (!module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_Result__rosidl_typesupport_introspection_c__SimpleAction_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `feedback`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_Feedback__init(message_memory);
}

void module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_Feedback__fini(message_memory);
}

size_t module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__size_function__SimpleAction_Feedback__feedback(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Feedback__feedback(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_function__SimpleAction_Feedback__feedback(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__SimpleAction_Feedback__feedback(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Feedback__feedback(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__assign_function__SimpleAction_Feedback__feedback(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_function__SimpleAction_Feedback__feedback(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__resize_function__SimpleAction_Feedback__feedback(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_member_array[1] = {
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_Feedback, feedback),  // bytes offset in struct
    NULL,  // default value
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__size_function__SimpleAction_Feedback__feedback,  // size() function pointer
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__SimpleAction_Feedback__feedback,  // get_const(index) function pointer
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__get_function__SimpleAction_Feedback__feedback,  // get(index) function pointer
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__SimpleAction_Feedback__feedback,  // fetch(index, &value) function pointer
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__assign_function__SimpleAction_Feedback__feedback,  // assign(index, value) function pointer
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__resize_function__SimpleAction_Feedback__feedback  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_Feedback",  // message name
  1,  // number of fields
  sizeof(module_interface__action__SimpleAction_Feedback),
  module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_member_array,  // message members
  module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Feedback)() {
  if (!module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_Feedback__rosidl_typesupport_introspection_c__SimpleAction_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "module_interface/action/simple_action.h"
// Member `goal`
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_SendGoal_Request__init(message_memory);
}

void module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(module_interface__action__SimpleAction_SendGoal_Request),
  module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_member_array,  // message members
  module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Request)() {
  module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Goal)();
  if (!module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_SendGoal_Request__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_SendGoal_Response__init(message_memory);
}

void module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(module_interface__action__SimpleAction_SendGoal_Response),
  module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_member_array,  // message members
  module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Response)() {
  module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_SendGoal_Response__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_members = {
  "module_interface__action",  // service namespace
  "SimpleAction_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_type_support_handle = {
  0,
  &module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal)() {
  if (!module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_type_support_handle.typesupport_identifier) {
    module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_SendGoal_Response)()->data;
  }

  return &module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_GetResult_Request__init(message_memory);
}

void module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(module_interface__action__SimpleAction_GetResult_Request),
  module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_member_array,  // message members
  module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Request)() {
  module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_GetResult_Request__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "module_interface/action/simple_action.h"
// Member `result`
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_GetResult_Response__init(message_memory);
}

void module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(module_interface__action__SimpleAction_GetResult_Response),
  module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_member_array,  // message members
  module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Response)() {
  module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Result)();
  if (!module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_GetResult_Response__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_members = {
  "module_interface__action",  // service namespace
  "SimpleAction_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_type_support_handle = {
  0,
  &module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult)() {
  if (!module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_type_support_handle.typesupport_identifier) {
    module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_GetResult_Response)()->data;
  }

  return &module_interface__action__detail__simple_action__rosidl_typesupport_introspection_c__SimpleAction_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "module_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "module_interface/action/detail/simple_action__functions.h"
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "module_interface/action/simple_action.h"
// Member `feedback`
// already included above
// #include "module_interface/action/detail/simple_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  module_interface__action__SimpleAction_FeedbackMessage__init(message_memory);
}

void module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_fini_function(void * message_memory)
{
  module_interface__action__SimpleAction_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(module_interface__action__SimpleAction_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_members = {
  "module_interface__action",  // message namespace
  "SimpleAction_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(module_interface__action__SimpleAction_FeedbackMessage),
  module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_member_array,  // message members
  module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_type_support_handle = {
  0,
  &module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_module_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_FeedbackMessage)() {
  module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, module_interface, action, SimpleAction_Feedback)();
  if (!module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &module_interface__action__SimpleAction_FeedbackMessage__rosidl_typesupport_introspection_c__SimpleAction_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
