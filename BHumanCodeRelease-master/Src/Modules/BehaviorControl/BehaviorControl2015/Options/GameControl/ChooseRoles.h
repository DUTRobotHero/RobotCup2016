option(ChooseRoles)
{
	char KEEPER_NUM=1;
	char DEFANDER_NUM=4;
	char STRIKER_NUM=2;
	char SUPPORTER_NUM=3;
  common_transition
  {
/*		if ( theRobotInfo.number == KEEPER_NUM )
			goto Keeper;
		else if  ( theRobotInfo.number == DEFANDER_NUM )
			goto Defender;//应该为Defender,不过还没有写完
		else if (theRobotInfo.number == STRIKER_NUM ||theRobotInfo.number == SUPPORTER_NUM )
		{
			if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友，没有的情况默认为Striker
				
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到对应号的teammate,排除keeper ,defender和自己
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != DEFANDER_NUM && 
							tempTeammate.number != theRobotInfo.number )
							{otherTeammate=tempTeammate;}
				}
				//确保队友的信息是准确的
				if (otherTeammate.number !=-1 && //不为空
					otherTeammate.status == Teammate::Status::FULLY_ACTIVE && //正在活动
					theFrameInfo.getTimeSince(otherTeammate.ball.timeWhenLastSeen) < 300 )//没有丢失球
				{
					//如果离球比较近，则为Striker ,否则为Supporter
					if (otherTeammate.ball.estimate.position.norm() > theBallModel.estimate.position.norm()+500.f )	
					{goto Striker;}
					else
					{goto defaultRole;}
				}
				else{//队友信息不准确的情况
                    if (libCodeRelease.timeSinceBallWasSeen()<300 || 
                        otherTeammate.status != Teammate::Status::FULLY_ACTIVE){//如果自己检测到球 或者 队友没有完全在踢球
                        goto Striker;}
                    else{
                        goto defaultRole;}
                }
				
			}
			else{
				//没有队友的情况默认为Striker
				goto Striker;
			}
		}*/
        for (Teammate tempTeammate:theTeammateData.teammates)
        {		//找到对应号的teammate,排除keeper ,defender和自己
                if (tempTeammate.number != KEEPER_NUM &&
                    tempTeammate.number != DEFANDER_NUM && 
                    tempTeammate.number != theRobotInfo.number )
                    {otherTeammate=tempTeammate;}
        }
        if ( theRobotInfo.number == KEEPER_NUM )
			goto Keeper;
		else if  ( theRobotInfo.number == DEFANDER_NUM )
			goto Defender;//应该为Defender,不过还没有写完
		else if (theRobotInfo.number == STRIKER_NUM )
            goto Striker;
        else if (theRobotInfo.number == SUPPORTER_NUM )
            goto Supporter;
  }

  /** Stand still and wait. */
  initial_state(initial)
  {
    action
    {
     theHeadControlMode = HeadControl::none;
      SetHeadPanTilt(0.f, 0.f, 150_deg);
    }
  }
  state(Keeper)
  {
	  action
	  {
		  Keeper();
          theBehaviorStatus.role = Role::keeper;
		}
	}
	state(Defender)
  {
	  
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
            for(Obstacle o:theObstacleModel.obstacles)
                ShowObstacles(o.center);
			Defender();
            theBehaviorStatus.role = Role::defender;
		}
	}
state(Striker)
  {
	  action
	  {
		  //ShowTeammateData(otherTeammate.number,otherTeammate.ball);
		  StrikerDong1();
          theBehaviorStatus.role = Role::striker;
          //KeyFrameRightArm(ArmKeyFrameRequest::back, false);
          //KeyFrameLeftArm(ArmKeyFrameRequest::back, false);
		}
	}
	state(Supporter)
  {
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
            theBehaviorStatus.role = Role::supporter;
		    Supporter();
            //KeyFrameRightArm(ArmKeyFrameRequest::useDefault, false);
            //KeyFrameLeftArm(ArmKeyFrameRequest::useDefault, false);
		}
	}
	state(defaultRole)
  {
	  
	  action
	  {
            if (theRobotInfo.number == SUPPORTER_NUM){
                theBehaviorStatus.role = Role::supporter;
                Supporter();
                KeyFrameRightArm(ArmKeyFrameRequest::useDefault, false);
                KeyFrameLeftArm(ArmKeyFrameRequest::useDefault, false);
                }
            else if (theRobotInfo.number == STRIKER_NUM){
                theBehaviorStatus.role = Role::striker;
                StrikerDong1();
                //KeyFrameLeftArm(ArmKeyFrameRequest::back, false);
                //KeyFrameRightArm(ArmKeyFrameRequest::back, false);
                }
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
			 
		}
	}
}
	Teammate otherTeammate;
 
