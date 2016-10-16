#pragma once
#include "BallModelToField.h"
#include "BallModel.h"
#include "Tools/Math/Eigen.h"
#include "Tools/Math/Pose2f.h"
#include "RobotPose.h"

Vector2f RobotMidPosition(const BallModel& theBallModel,const RobotPose& theRobotPose,float Radius = 650.0);