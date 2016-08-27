/**
 * The option observes the state of a certain button and reports a success if it was pressed and released.
 * If a timeout is specified, the option can also be aborted if state changes take too long.
 * @param key The button to observe.
 * @param timeOut An optional timeout in ms. The timeout is measured between state changes.
 */
 
  //pengwanli
  //按钮按下和抬起，
  //第一个参数代表按下的按钮，
  //第二个参数指按钮按下的时间，当超过这个时间，则按按下一次按钮并抬起算
  //第三个参数指两次按下按钮的时间间隔，少于这个时间间隔，按按下一次算
option(ButtonPressedAndReleased, ((KeyStates) Key) key, (int) releaseTimeOut, (int) successiveTimeOut)
{
  /** The option waits for the button to be pressed. */
  initial_state(waitingForPressInit)
  {
    transition
    {
      if(theKeyStates.pressed[key])
        goto waitingForRelease;
    }
  }

  state(waitingForPressSuccessive)
  {
    transition
    {
      if(state_time > successiveTimeOut)
        goto timedOut;
      if(theKeyStates.pressed[key])
        goto waitingForRelease;
    }
  }

  /** The button was pressed, now the option waits for its release. */
  state(waitingForRelease)
  {
    transition
    {
      if(state_time > releaseTimeOut) // too slow -> abort
        goto timedOut;
      else if(!theKeyStates.pressed[key])
        goto success;
    }
  }

  /** Button was pressed and released. The option only stays a single cycle in this state. */
  target_state(success)
  {
    transition
    {
      goto waitingForPressSuccessive;
    }
  }

  /** The timeout was reached. The option only stays a single cycle in this state. */
  aborted_state(timedOut)
  {
    transition
    {
      goto waitingForPressInit;
    }
  }
}
