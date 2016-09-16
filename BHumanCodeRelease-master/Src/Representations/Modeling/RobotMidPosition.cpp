#include "RobotMidPosition.h"
#include "BallModel.h"
#include "Tools/Math/Eigen.h"
#include "Tools/Math/Pose2f.h"
#include "RobotPose.h"

Vector2f RobotMidPosition(const BallModel& theBallModel,const RobotPose& theRobotPose,float Radius)
{
    float  ballrot = std::atan(theBallModel.estimate.position.y() /theBallModel.estimate.position.x() );   //球相对机器人的旋转角
    float ballrot2ground = theRobotPose.rotation + ballrot;    //球相对球场的旋转角

    float c =  theBallModel.estimate.position.norm();              //球相对机器人坐标系的长度(x^2+y^2)
    //把机器人坐标系旋转后，球相对机器人坐标系的坐标
    float Ball_X = std::cos(ballrot2ground) * c;
    float Ball_Y = std::sin(ballrot2ground) * c;
    //球相对于球场的坐标
    Ball_X = Ball_X + theRobotPose.translation.x();
    Ball_Y = Ball_Y + theRobotPose.translation.y();
    Vector2f goalpos(-4500,0);
    float  rot = std::atan(Ball_Y/(Ball_X - goalpos.x()));
    
    Vector2f ballpos(Ball_X,Ball_Y);
    
    Vector2f norm = ballpos - goalpos;      //连接球与门的向量

    norm.normalize();                                  //化成单位向量

    //Vector2f AD = (ballpos - goalpos).dot(theRobotPose.translation - goalpos) /(ballpos - goalpos).norm()*norm;
    
    Vector2f AD = Radius*norm;                     //球门前半径为450mm的圆弧半径

    Vector2f mid = goalpos + AD;               //计算出圆弧上的点（机器人要到达的位置）

    return mid;
}