#pragma once

#include "gameObject.h"

class Puzzle;

class lockedObject : public gameObject
{
protected:
  bool isLocked;
  Puzzle *objPuzzle;

public:
  lockedObject(string, string, string, Puzzle *);
  void interact() override;
  bool getLocked() { return isLocked; }
  void setLocked(bool val) { isLocked = val; }
};