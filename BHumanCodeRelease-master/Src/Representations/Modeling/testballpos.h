#pragma once

#include "BallModel.h"
#include "Tools/Math/Eigen.h"
#include "Tools/Math/Pose2f.h"
#include "RobotPose.h"

Vector2f TestBallPos(const BallModel& theBallModel,const RobotPose& theRobotPose);