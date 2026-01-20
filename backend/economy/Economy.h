#pragma once

#include "users/User.h"

class Economy {
 public:
  void AddCoins(User& user, int amount);
  bool DeductCoins(User& user, int amount);
};
