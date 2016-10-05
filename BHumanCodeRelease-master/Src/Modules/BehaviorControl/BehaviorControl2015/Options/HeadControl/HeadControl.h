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
      default: goto none;
    }
  }

  initial_state(none) {}
  state(off) {action SetHeadPanTilt(JointAngles::off, JointAngles::off, 0.f);}
  state(lookForward) {action LookForward();}
  state(leftAndRight)  {action LeftAndRight();}
}

struct HeadControl
{
  ENUM(Mode,
  {,
    none,
    off,
    lookForward,
    leftAndRight,
  });
};

HeadControl::Mode theHeadControlMode = HeadControl::Mode::none; /**< The head control mode executed by the option HeadControl. */
