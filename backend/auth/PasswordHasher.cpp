#include "auth/PasswordHasher.h"

std::string PasswordHasher::Hash(const std::string& password) const {
  (void)password;
  return "";
}

bool PasswordHasher::Verify(const std::string& password, const std::string& hash) const {
  (void)password;
  (void)hash;
  return false;
}
