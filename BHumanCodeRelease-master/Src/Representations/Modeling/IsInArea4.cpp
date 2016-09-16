#include "BallModelToField.h"
#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsInArea4.h"
#include "IsBallInPenaltyArea.h"
Pose2f BallModel2Field(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsBallInPenaltyArea(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsInArea4(const BallModel& theballModel,const RobotPose& theRobotPose)
{
     Pose2f BallModel = BallModel2Field(theballModel,theRobotPose);
     bool BallInPenaltyArea = IsBallInPenaltyArea(theballModel,theRobotPose);  
     if (((BallModel.translation.x() + 4500) * (BallModel.translation.x() + 4500) + BallModel.translation.y() * BallModel.translation.y() < 750 * 750) && BallInPenaltyArea)
         return true;
     else
         return false;
}