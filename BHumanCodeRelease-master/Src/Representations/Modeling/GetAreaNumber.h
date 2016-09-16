#pragma once
#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsInArea1.h"
#include "IsInArea2_3.h"
#include "IsInArea4.h"

int GetAreaNumber(const BallModel& theballModel,const RobotPose& theRobotPose);