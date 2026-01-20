#pragma once

#include <string>

class GameRoom {
 public:
  void AddPlayer(const std::string& email);
  bool IsReady() const;

 private:
  int player_count_ = 0;
};
