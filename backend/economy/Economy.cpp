#include "economy/Economy.h"

void Economy::AddCoins(User& user, int amount) {
  user.coins += amount;
}

bool Economy::DeductCoins(User& user, int amount) {
  if (user.coins < amount) {
    return false;
  }
  user.coins -= amount;
  return true;
}
