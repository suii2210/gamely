#pragma once

#include <string>

class PasswordHasher {
 public:
  std::string Hash(const std::string& password) const;
  bool Verify(const std::string& password, const std::string& hash) const;
};
