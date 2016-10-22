option(HeadControl)
{
  common_transition
  {
    if(!theGroundContactState.contact && theGameInfo.state != STATE_INITIAL)
      goto lookForward;

    switch(theHeadControlMode)
    {
      case HeadControl::off: goto off;
      case HeadControl::lookForward: goto lookForward;
      case HeadControl::leftAndRight: goto leftAndRight;
      case HeadControl::focusBall: goto focusBall;
      case HeadControl::searchForBall: goto searchForBall;
	  case HeadControl::lookHigh: goto lookHigh;
      default: goto none;
    }
  }

  initial_state(none) {}
  state(off) {action SetHeadPanTilt(JointAngles::off, JointAngles::off, 0.f);}
  state(lookForward) {action LookForward();}
  state(leftAndRight)  {action LeftAndRight();}
  state(searchForBall)  {action SearchForBall();}
  state(lookHigh)  {action SetHeadPanTilt(0.0f, 0.0f, 150_deg);}
  state(focusBall){action SetHeadTarget(Vector3f(theBallModel.estimate.position.x(),
																				theBallModel.estimate.position.y(),
																				theBallModel.estimate.radius/2.0));}
}

struct HeadControl
{
  ENUM(Mode,
  {,
    none,
    off,
    lookForward,
	lookHigh,
    leftAndRight,
    focusBall,
    searchForBall,
  });
};

HeadControl::Mode theHeadControlMode = HeadControl::Mode::none; /**< The head control mode executed by the option HeadControl. */
