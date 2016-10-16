/**
* @file LibCodeRelease.h
*/

class LibCodeRelease : public LibraryBase
{
public:
  /** Constructor for initializing all members*/
  LibCodeRelease();

  void preProcess() override;

  void postProcess() override;
  
  
  bool between(float value, float min, float max);
  float getAngle(const Vector2f& vector1, const Vector2f& vector2);
    
  int timeSinceBallWasSeen();

  float angleToGoal;
  float angleToGoalForStriker;
  bool returnFormPenalty;
  bool firstKick;
};