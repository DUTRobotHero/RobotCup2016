#include "BallModelToField.h"
#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsBallInPenaltyArea.h"

Pose2f BallModel2Field(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsBallInPenaltyArea(const BallModel& theballModel,const RobotPose& theRobotPose)
{
    Pose2f BallPos = BallModel2Field(theballModel,theRobotPose);
    float PENALTYWIDTH = 600.0;
    float PENALTYHEIGHT = 2200;
    float FIELDWIDTH = 9000;
    if ( BallPos.translation.x() < (-FIELDWIDTH/2+PENALTYWIDTH) && (BallPos.translation.y() > -PENALTYHEIGHT/2) && (BallPos.translation.y() < PENALTYHEIGHT/2 ))
        return true;
    else
        return false;
}