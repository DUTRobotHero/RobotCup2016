option(ChooseRoles)
{
	char KEEPER_NUM=1;
	char DEFANDER_NUM=4;
	char STRIKER_NUM=2;
	char SUPPORTER_NUM=3;
  common_transition
  {
		if ( theRobotInfo.number == KEEPER_NUM )
			goto Keeper;
		else if  ( theRobotInfo.number == DEFANDER_NUM )
			goto TestPlayer;//应该为Defender,不过还没有写完
		else if (theRobotInfo.number == STRIKER_NUM ||theRobotInfo.number == SUPPORTER_NUM )
		{
			if ( theTeammateData.numberOfActiveTeammates !=0 ){//判断是否有发送消息的队友，没有的情况默认为defaultRole
				
				for (Teammate tempTeammate:theTeammateData.teammates)
				{		//找到对应号的teammate,排除keeper ,defender和自己
						if (tempTeammate.number != KEEPER_NUM &&
							tempTeammate.number != DEFANDER_NUM && 
							tempTeammate.number != theRobotInfo.number )
							{otherTeammate=tempTeammate;}
				}
				//确保队友的信息是准确的，不准确就会进入默认模式defaultdefaultRole
				if (otherTeammate.number !=-1 && //不为空
					otherTeammate.status == Teammate::Status::FULLY_ACTIVE && //正在活动
					theFrameInfo.getTimeSince(otherTeammate.ball.timeWhenLastSeen) < 300 )//没有丢失球
				{
					//如果离球比较近，则为Striker ,否则为Supporter
					if (otherTeammate.ball.estimate.position.norm() > theBallModel.estimate.position.norm() )	
					{goto Striker;}
					else
					{goto Supporter;}
				}
				else//不准确就会进入默认模式defaultdefaultRole
				{goto defaultRole;}
				
			}
			else{
				//没有队友的情况默认为defaultRole
				goto defaultRole;
			}
		}
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
		}
	}
	state(TestPlayer)
  {
	  
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
			TestPlayer();
		}
	}
state(Striker)
  {
	  action
	  {
		  //ShowTeammateData(otherTeammate.number,otherTeammate.ball);
		  StrikerDong1();
		}
	}
	state(Supporter)
  {
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
		    Supporter();
		}
	}
	state(defaultRole)
  {
	  
	  action
	  {
			//ShowTeammateData(otherTeammate.number,otherTeammate.ball);
			 StrikerDong1();
             KeyFrameLeftArm(ArmKeyFrameRequest::back, true);
             KeyFrameRightArm(ArmKeyFrameRequest::back, true);
		}
	}
}
	Teammate otherTeammate;
 
