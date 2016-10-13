/** Triggers the options for the different game states.
 *  This option also invokes the get up behavior after a fall, as this is needed in most game states.
 */
option(HandleGameState)
{
    /** As game state changes are discrete external events and all states are independent of each other,
        a common transition can be used here. */
    common_transition {
        if(theGameInfo.state == STATE_INITIAL)
            goto initial;
        else if(theGameInfo.state == STATE_FINISHED)
            goto finished;
        else if(theFallDownState.state != FallDownState::upright && theFallDownState.state != FallDownState::undefined)
            goto getUp;
        else if(theGameInfo.state == STATE_READY)
            goto ready;
        else if(theGameInfo.state == STATE_SET)
            goto set;
        else if(theGameInfo.state == STATE_PLAYING || theWhistle.lastTimeWhistleDetected != 0)
            goto playing;
    }

    /** Stand still and wait. */
    initial_state(initial) {
        action {
            theHeadControlMode = HeadControl::none;
            SetHeadPanTilt(0.f, 0.f, 150_deg);
            if(theGameInfo.secondaryState == STATE2_PENALTYSHOOT)
                PlaySound(theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber
                ? "penaltyStriker.wav" : "penaltyKeeper.wav");

            if(theGameInfo.secondaryState == STATE2_PENALTYSHOOT) {
                if (theGameInfo.kickOffTeam == theOwnTeamInfo.teamNumber)
                    StrikerDong1();
                else
                    Keeper();
            } else
                SpecialAction(SpecialActionRequest::standHigh);
        }
    }

    /** Stand still and wait. If somebody wants to implement cheering moves => This is the place. ;-) */
    state(finished) {
        action {
            theHeadControlMode = HeadControl::lookForward;
            Stand();
        }
    }

    /** Get up from the carpet. */
    state(getUp) {
        action {
            Annotation("Getting up.");
            GetUp();
        }
    }

    /** Walk to kickoff position. */
    state(ready) {
        action {
            ShowRobotToField(theRobotPose);
            ShowSomething((float)theRobotInfo.number);
            ArmContact();
            ReadyState();
        }
    }

    /** Stand and look around. */
    state(set) {
        action {
            //theHeadControlMode = HeadControl::lookForward;
            Stand();
            SetState();
            ShowWhistle(theWhistle.confidenceOfLastWhistleDetection);
            ShowCorrelation(theWhistle.lastTimeWhistleDetected);
            ShowCorrelation(theWhistle.lastTimeOfIncomingSound);


        }
    }

    /** Play soccer! */
    state(playing) {
        action {
            /*  WhistleRecognizer whistleRecognizer;
              bool detectWhistle = whistleRecognizer.detectWhistle();*/
            ShowCorrelation(theWhistle.lastTimeWhistleDetected);
            ShowCorrelation(theWhistle.lastTimeOfIncomingSound);
            if(theGameInfo.kickOffTeam != theOwnTeamInfo.teamNumber)
            {
            if(theBallModel.estimate.velocity.x() > 0.0 || theBallModel.estimate.velocity.y() > 0.0 || state_time  > 10000) {
                ArmContact();
                PlayingState();
            }
            }
            else {
                ArmContact();
                PlayingState();
            }
        }
    }
}
