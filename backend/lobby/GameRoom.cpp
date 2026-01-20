#include "lobby/GameRoom.h"

void GameRoom::AddPlayer(const std::string& email) {
  (void)email;
  ++player_count_;
}

bool GameRoom::IsReady() const {
  return player_count_ > 1;
}
