/**
 * This option lets the robot kick the ball use right leg,the kick type decide the way to kick ,kick straight or sidewards .
 * @param kickType The WalkRequest::KickType to be executed. Only right and sidewardsRight
 * By JiangDong
 */
option(RightKick,((WalkRequest) KickType) kickType)
{
  initial_state(alignBehindBallInRightKick)
  {
    transition
    {
		if(libCodeRelease.between(theBallModel.estimate.position.y(), -50.f, -20.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 140.f, 170.f)
          && std::abs(libCodeRelease.angleToGoalForStriker) < 2_deg)
        goto rightkick;
    }
    action
    {
		theHeadControlMode = HeadControl::focusBall;
        WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 150.f, theBallModel.estimate.position.y() + 30.f));
    }
  }

state(rightkick)
  {
    transition
    {
		if(state_time > 3000 || (state_time > 10 && action_done))
        goto finished;
    }
    action
    {
		  Annotation("Kick use right'");
		  theHeadControlMode = HeadControl::focusBall;
		  InWalkKick(kickType, Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 160.f, theBallModel.estimate.position.y() + 55.f));
    }
  }
target_state(finished){
	  action{
		  theHeadControlMode = HeadControl::lookForward;
		  }
	  }
}