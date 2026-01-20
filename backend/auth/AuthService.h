#pragma once

#include <string>

class AuthService {
 public:
  bool RegisterUser(const std::string& email, const std::string& password);
  bool Login(const std::string& email, const std::string& password);
};
