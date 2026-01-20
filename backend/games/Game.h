#pragma once

class Game {
 public:
  virtual ~Game() = default;
  virtual void Tick() = 0;
};
