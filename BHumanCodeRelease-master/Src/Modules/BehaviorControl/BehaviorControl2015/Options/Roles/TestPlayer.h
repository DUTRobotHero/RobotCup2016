/** A TestPlayer option without common decision */
option(TestPlayer)
{
  initial_state(start)
  {
    transition
    {
		goto shoot;
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }
      state(shoot) {
        transition {
			if (action_done)
				goto start;
        }
        action {
		 Shoot(KickRequest::kickForward);
        }
    }

}