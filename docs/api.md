# API and WebSocket Contracts

This document defines the initial HTTP and WebSocket message contracts.
All messages are JSON. The server is authoritative for game rules.

## REST (HTTP)

Base URL: `http://<host>:8080`

Headers:
- `Content-Type: application/json`
- `Authorization: Bearer <token>` for protected endpoints

### POST /auth/register
Request:
```json
{
  "email": "user@example.com",
  "password": "plain-text-password"
}
```
Response (success):
```json
{
  "ok": true,
  "user": {
    "user_id": "u_123",
    "email": "user@example.com",
    "coins": 100,
    "games_played": 3,
    "games_won": 1
  }
}
```
Response (error):
```json
{
  "ok": false,
  "error": {
    "code": "AUTH_EMAIL_TAKEN",
    "message": "Email is already registered."
  }
}
```

### POST /auth/login
Request:
```json
{
  "email": "user@example.com",
  "password": "plain-text-password"
}
```
Response (success):
```json
{
  "ok": true,
  "token": "jwt-or-session-token",
  "user": {
    "user_id": "u_123",
    "email": "user@example.com",
    "coins": 100,
    "games_played": 3,
    "games_won": 1
  }
}
```
Response (error):
```json
{
  "ok": false,
  "error": {
    "code": "AUTH_INVALID",
    "message": "Invalid credentials."
  }
}
```

### GET /users/me
Response (success):
```json
{
  "ok": true,
  "user": {
    "user_id": "u_123",
    "email": "user@example.com",
    "coins": 100,
    "games_played": 3,
    "games_won": 1
  }
}
```

### POST /lobby/create
Request:
```json
{
  "game_type": "monopoly",
  "max_players": 4
}
```
Response (success):
```json
{
  "ok": true,
  "room_id": "r_123",
  "room_code": "ABCD",
  "room": {
    "room_id": "r_123",
    "room_code": "ABCD",
    "game_type": "monopoly",
    "max_players": 4,
    "players": [],
    "status": "waiting"
  }
}
```

### POST /lobby/join
Request:
```json
{
  "room_code": "ABCD"
}
```
Response (success):
```json
{
  "ok": true,
  "room_id": "r_123",
  "room": {
    "room_id": "r_123",
    "room_code": "ABCD",
    "game_type": "monopoly",
    "max_players": 4,
    "players": [
      {
        "user_id": "u_123",
        "display_name": "Player 1",
        "position": 0,
        "coins": 100,
        "ready": true
      }
    ],
    "status": "waiting"
  }
}
```

### POST /lobby/ready
Request:
```json
{
  "room_id": "r_123",
  "ready": true
}
```
Response (success):
```json
{
  "ok": true,
  "room": {
    "room_id": "r_123",
    "room_code": "ABCD",
    "game_type": "monopoly",
    "max_players": 4,
    "players": [],
    "status": "waiting"
  }
}
```

### POST /lobby/leave
Request:
```json
{
  "room_id": "r_123"
}
```
Response (success):
```json
{
  "ok": true
}
```

## WebSocket

WebSocket URL: `ws://<host>:8081/ws`

Client connects and sends an auth message with a token. The server responds
with `AUTH_OK` or `ERROR`.

### Envelope
Every WebSocket message uses the same JSON envelope:
```json
{
  "type": "MESSAGE_TYPE",
  "request_id": "optional-correlation-id",
  "room_id": "optional-room-id",
  "data": {}
}
```

### Client -> Server

#### AUTH
```json
{
  "type": "AUTH",
  "request_id": "1",
  "data": {
    "token": "jwt-or-session-token"
  }
}
```

#### PING
```json
{
  "type": "PING",
  "request_id": "2",
  "data": {}
}
```

#### LOBBY_READY
```json
{
  "type": "LOBBY_READY",
  "request_id": "3",
  "room_id": "r_123",
  "data": {
    "ready": true
  }
}
```

#### GAME_ACTION
```json
{
  "type": "GAME_ACTION",
  "request_id": "4",
  "room_id": "r_123",
  "data": {
    "action": "ROLL_DICE",
    "payload": {}
  }
}
```

Example actions:
- `ROLL_DICE`
- `BUY_PROPERTY`
- `END_TURN`
- `PAY_RENT`
- `JAIL_DECISION`

### Server -> Client

#### AUTH_OK
```json
{
  "type": "AUTH_OK",
  "request_id": "1",
  "data": {}
}
```

#### LOBBY_STATE
```json
{
  "type": "LOBBY_STATE",
  "room_id": "r_123",
  "data": {
    "room_id": "r_123",
    "room_code": "ABCD",
    "max_players": 4,
    "players": [],
    "status": "waiting"
  }
}
```

#### TURN_UPDATE
```json
{
  "type": "TURN_UPDATE",
  "room_id": "r_123",
  "data": {
    "player_id": "u_123",
    "position": 12
  }
}
```

#### DICE_ROLLED
```json
{
  "type": "DICE_ROLLED",
  "room_id": "r_123",
  "data": {
    "player_id": "u_123",
    "die1": 4,
    "die2": 3,
    "total": 7
  }
}
```

#### GAME_STATE
```json
{
  "type": "GAME_STATE",
  "room_id": "r_123",
  "data": {
    "state": {}
  }
}
```

#### ECONOMY_UPDATE
```json
{
  "type": "ECONOMY_UPDATE",
  "data": {
    "user_id": "u_123",
    "coins": 120,
    "delta": 20,
    "reason": "WIN_MATCH"
  }
}
```

#### GAME_OVER
```json
{
  "type": "GAME_OVER",
  "room_id": "r_123",
  "data": {
    "winner_id": "u_123"
  }
}
```

#### ERROR
```json
{
  "type": "ERROR",
  "request_id": "4",
  "data": {
    "code": "INVALID_ACTION",
    "message": "Action is not valid for the current state."
  }
}
```
