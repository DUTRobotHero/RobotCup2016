#include "RobotPose.h"
#include "Tools/Math/Pose2f.h"
#include "Tools/Math/Eigen.h"
#include "IsInArea1.h"
#include "IsInArea2_3.h"
#include "IsInArea4.h"
#include "GetAreaNumber.h"
bool IsInArea1(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsInArea2_3(const BallModel& theballModel,const RobotPose& theRobotPose);
bool IsInArea4(const BallModel& theballModel,const RobotPose& theRobotPose);

int GetAreaNumber(const BallModel& theballModel,const RobotPose& theRobotPose)
{
    if(IsInArea1(theballModel,theRobotPose))
        return 1;
    else if(IsInArea2_3(theballModel,theRobotPose))
        return 2;                     //2或3都可
    else if(IsInArea4(theballModel,theRobotPose))
        return 4;
    else
        return 0;
}