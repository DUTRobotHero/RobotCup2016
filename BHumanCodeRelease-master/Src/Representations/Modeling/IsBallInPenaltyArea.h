#pragma once
#include "BallModelToField.h"
#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"

bool IsBallInPenaltyArea(const BallModel& theballModel,const RobotPose& theRobotPose);