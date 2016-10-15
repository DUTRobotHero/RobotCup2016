/**
 * This option lets the robot kick the ball use right leg
 * This option use Shoot.h ，which is the Shoot pose.
 * By JiangDong
 */
option(ShootKick)
{
  initial_state(alignBehindBallInShootKick)
  {
    transition
    {
		if(libCodeRelease.between(theBallModel.estimate.position.y(), -50.f, -20.f)
          && libCodeRelease.between(theBallModel.estimate.position.x(), 120.f, 150.f)
          && std::abs(libCodeRelease.angleToGoalForStriker) < 2_deg)
        goto shootKick;
    }
    action
    {
		theHeadControlMode = HeadControl::focusBall;
        WalkToTarget(Pose2f(80.f, 80.f, 80.f), Pose2f(libCodeRelease.angleToGoalForStriker, theBallModel.estimate.position.x() - 140.f, theBallModel.estimate.position.y() + 30.f));
    }
  }

 state(shootKick)
  {
    transition
    {
		if (action_done)
			goto finished;
    }
    action
    {
		  Annotation("Kick use right'");
		 theHeadControlMode = HeadControl::focusBall;
		 Shoot(KickRequest::kickForward);
    }
  }
target_state(finished){
	action{
		theHeadControlMode = HeadControl::lookForward;
		;}
	}
}
