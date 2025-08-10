// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from module_interface:action/SimpleAction.idl
// generated code does not contain a copyright notice

#ifndef MODULE_INTERFACE__ACTION__DETAIL__SIMPLE_ACTION__STRUCT_H_
#define MODULE_INTERFACE__ACTION__DETAIL__SIMPLE_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_Goal
{
  int32_t goal;
} module_interface__action__SimpleAction_Goal;

// Struct for a sequence of module_interface__action__SimpleAction_Goal.
typedef struct module_interface__action__SimpleAction_Goal__Sequence
{
  module_interface__action__SimpleAction_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_Result
{
  rosidl_runtime_c__int32__Sequence result;
} module_interface__action__SimpleAction_Result;

// Struct for a sequence of module_interface__action__SimpleAction_Result.
typedef struct module_interface__action__SimpleAction_Result__Sequence
{
  module_interface__action__SimpleAction_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_Feedback
{
  rosidl_runtime_c__int32__Sequence feedback;
} module_interface__action__SimpleAction_Feedback;

// Struct for a sequence of module_interface__action__SimpleAction_Feedback.
typedef struct module_interface__action__SimpleAction_Feedback__Sequence
{
  module_interface__action__SimpleAction_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "module_interface/action/detail/simple_action__struct.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  module_interface__action__SimpleAction_Goal goal;
} module_interface__action__SimpleAction_SendGoal_Request;

// Struct for a sequence of module_interface__action__SimpleAction_SendGoal_Request.
typedef struct module_interface__action__SimpleAction_SendGoal_Request__Sequence
{
  module_interface__action__SimpleAction_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} module_interface__action__SimpleAction_SendGoal_Response;

// Struct for a sequence of module_interface__action__SimpleAction_SendGoal_Response.
typedef struct module_interface__action__SimpleAction_SendGoal_Response__Sequence
{
  module_interface__action__SimpleAction_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} module_interface__action__SimpleAction_GetResult_Request;

// Struct for a sequence of module_interface__action__SimpleAction_GetResult_Request.
typedef struct module_interface__action__SimpleAction_GetResult_Request__Sequence
{
  module_interface__action__SimpleAction_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_GetResult_Response
{
  int8_t status;
  module_interface__action__SimpleAction_Result result;
} module_interface__action__SimpleAction_GetResult_Response;

// Struct for a sequence of module_interface__action__SimpleAction_GetResult_Response.
typedef struct module_interface__action__SimpleAction_GetResult_Response__Sequence
{
  module_interface__action__SimpleAction_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "module_interface/action/detail/simple_action__struct.h"

/// Struct defined in action/SimpleAction in the package module_interface.
typedef struct module_interface__action__SimpleAction_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  module_interface__action__SimpleAction_Feedback feedback;
} module_interface__action__SimpleAction_FeedbackMessage;

// Struct for a sequence of module_interface__action__SimpleAction_FeedbackMessage.
typedef struct module_interface__action__SimpleAction_FeedbackMessage__Sequence
{
  module_interface__action__SimpleAction_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} module_interface__action__SimpleAction_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MODULE_INTERFACE__ACTION__DETAIL__SIMPLE_ACTION__STRUCT_H_
