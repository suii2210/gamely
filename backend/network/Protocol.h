#pragma once

#include <string>
#include <vector>

namespace protocol {

struct Error {
  std::string code;
  std::string message;
};

struct UserProfile {
  std::string user_id;
  std::string email;
  int coins = 0;
  int games_played = 0;
  int games_won = 0;
};

struct PlayerInfo {
  std::string user_id;
  std::string display_name;
  int position = 0;
  int coins = 0;
  bool ready = false;
};

struct RoomInfo {
  std::string room_id;
  std::string room_code;
  std::string game_type = "monopoly";
  int max_players = 4;
  std::vector<PlayerInfo> players;
  std::string status;
};

struct RegisterRequest {
  std::string email;
  std::string password;
};

struct RegisterResponse {
  bool ok = false;
  UserProfile user;
  Error error;
};

struct LoginRequest {
  std::string email;
  std::string password;
};

struct LoginResponse {
  bool ok = false;
  std::string token;
  UserProfile user;
  Error error;
};

struct MeResponse {
  bool ok = false;
  UserProfile user;
  Error error;
};

struct CreateRoomRequest {
  std::string game_type = "monopoly";
  int max_players = 4;
};

struct CreateRoomResponse {
  bool ok = false;
  std::string room_id;
  std::string room_code;
  RoomInfo room;
  Error error;
};

struct JoinRoomRequest {
  std::string room_code;
};

struct JoinRoomResponse {
  bool ok = false;
  std::string room_id;
  RoomInfo room;
  Error error;
};

struct ReadyRoomRequest {
  std::string room_id;
  bool ready = false;
};

struct ReadyRoomResponse {
  bool ok = false;
  RoomInfo room;
  Error error;
};

struct LeaveRoomRequest {
  std::string room_id;
};

struct LeaveRoomResponse {
  bool ok = false;
  Error error;
};

enum class WsMessageType {
  kAuth,
  kAuthOk,
  kPing,
  kPong,
  kLobbyReady,
  kLobbyState,
  kGameAction,
  kGameState,
  kTurnUpdate,
  kDiceRolled,
  kEconomyUpdate,
  kGameOver,
  kError
};

struct WsEnvelope {
  WsMessageType type = WsMessageType::kError;
  std::string request_id;
  std::string room_id;
  std::string data_json;
};

struct WsAuth {
  std::string token;
};

struct WsLobbyReady {
  std::string room_id;
  bool ready = false;
};

struct WsGameAction {
  std::string room_id;
  std::string action;
  std::string action_json;
};

struct WsLobbyState {
  RoomInfo room;
};

struct WsGameState {
  std::string room_id;
  std::string state_json;
};

struct WsTurnUpdate {
  std::string room_id;
  std::string player_id;
  int position = 0;
};

struct WsDiceRolled {
  std::string room_id;
  std::string player_id;
  int die1 = 0;
  int die2 = 0;
  int total = 0;
};

struct WsEconomyUpdate {
  std::string user_id;
  int coins = 0;
  int delta = 0;
  std::string reason;
};

struct WsGameOver {
  std::string room_id;
  std::string winner_id;
};

struct WsError {
  std::string code;
  std::string message;
};

}  // namespace protocol
