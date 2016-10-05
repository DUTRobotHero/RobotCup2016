/** A TestPlayer option without common decision */
option(TestPlayer)
{
  initial_state(start)
  {
    transition
    {
    }
    action
    {
      theHeadControlMode = HeadControl::lookForward;
      Stand();
    }
  }

}