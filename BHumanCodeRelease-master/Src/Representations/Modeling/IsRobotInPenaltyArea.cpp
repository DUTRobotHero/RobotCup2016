#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsRobotInPenaltyArea.h"

bool IsRobotInPenaltyArea(const RobotPose& theRobotPose)
{
    float PENALTYWIDTH = 600.0;
    float PENALTYHEIGHT = 2200;
    float FIELDWIDTH = 9000;
    if ( (theRobotPose.translation.x() < (-FIELDWIDTH/2+PENALTYWIDTH)) && (theRobotPose.translation.y() > -PENALTYHEIGHT/2) && (theRobotPose.translation.y() < PENALTYHEIGHT/2 ))
        return true;
    else
        return false;
}