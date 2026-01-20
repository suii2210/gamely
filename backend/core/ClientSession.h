#pragma once

#include <string>

class ClientSession {
 public:
  void Send(const std::string& message);
  void Close();
};
