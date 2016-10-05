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
      default: goto none;
    }
  }

  initial_state(none) {}
  state(off) {action SetHeadPanTilt(JointAngles::off, JointAngles::off, 0.f);}
  state(lookForward) {action LookForward();}
  state(leftAndRight)  {action LeftAndRight();}
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
    leftAndRight,
	focusBall,
  });
};

HeadControl::Mode theHeadControlMode = HeadControl::Mode::none; /**< The head control mode executed by the option HeadControl. */
