# Architecture

## Backend modules
- auth: login, password hashing, session tokens
- users: profile, coins, game history
- lobby: rooms, join flow, start gating
- games/monopoly: turn logic, dice, board, rules
- economy: coin balances and rewards
- persistence: save and load state
- network: REST and WebSocket transport
- utils: logging helpers

## Frontend responsibilities
- Render the board and pieces
- Display server updates
- Send user actions

## Network messages
REST endpoints are used for login, registration, and lobby actions. WebSockets are used for live game state.

Example WebSocket message:
{
  "type": "TURN_UPDATE",
  "player": "user@email.com",
  "position": 12
}
