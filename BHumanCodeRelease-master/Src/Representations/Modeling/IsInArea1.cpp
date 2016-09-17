#include "BallModelToField.h"
#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsInArea1.h"

Pose2f BallModel2Field(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsInArea1(const BallModel& theballModel,const RobotPose& theRobotPose)
{
     Pose2f BallModel = BallModel2Field(theballModel,theRobotPose);
     if ((0.75 * BallModel.translation.x() + BallModel.translation.y() + 3375.0 > 0) && (0.75 * BallModel.translation.x() - BallModel.translation.y() + 3375.0 > 0) 
     && (BallModel.translation.x() > -3900) && std::abs(BallModel.translation.y()) < 1100)
         return true;
     else
         return false;
}