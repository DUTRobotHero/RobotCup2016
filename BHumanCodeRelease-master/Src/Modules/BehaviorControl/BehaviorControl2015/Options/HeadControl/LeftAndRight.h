/** Pun intended. Looks straight ahead in a way that the Nao V4's cameras cover the area in front of its feet as well as everything else in front of the robot.*/
option(LeftAndRight)
{
    /** Simply sets the necessary angles */
    initial_state(LeftAndRight) {
        transition {
            if(action_done)
                goto lookRight;
        }
        action {
            SetHeadPanTilt(-0.8f, 0.f, 50_deg);
        }
    }
    state(lookRight) {
        transition {
            if(action_done)
                goto lookLeft;
        }
        action {
            SetHeadPanTilt(0.8f, 0.f, 50_deg);
        }
    }
    state(lookLeft) {
        transition {
            if(action_done)
                goto lookRight1;
        }
        action {
            SetHeadPanTilt(-0.8f, 0.f, 50_deg);
        }
    }

    state(lookRight1) {
        transition {
            if(action_done)
                goto lookLeft1;
        }
        action {
            SetHeadPanTilt(0.8f, 0.f, 50_deg);
        }
    }


    state(lookLeft1) {
        transition {
            if (action_done)
                goto lookForward;
        }
        action {
            SetHeadPanTilt(-0.8f, 0.f, 50_deg);
        }
    }

    state(lookForward) {
        transition {
            if(action_done)
                goto turnOffHeadControl;
        }
        action {
            SetHeadPanTilt(0.f, 0.f, 50_deg);
        }
    }

    state(turnOffHeadControl) {
        action {
            theHeadControlMode = HeadControl::off;
        }
    }
}
