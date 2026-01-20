# Architecture

## Platform overview
Gamely hosts multiple games under one platform with shared accounts, coins, and multiplayer rooms.
Monopoly is the first game and runs as a plug-in that implements the common Game interface.

## Backend modules
- auth: registration, login, password hashing, session tokens
- users: profile, coins, game stats
- lobby: rooms by game type, join flow, ready/start gating
- games: common interface and per-game modules
- games/monopoly: turn logic, dice, board, rules
- economy: coin balances and rewards
- persistence: save/load profiles and game state
- network: REST and WebSocket transport
- utils: logging helpers

## Frontend responsibilities
- Render lobby and board UI
- Display server updates
- Send player actions only (no game results)

## Real-time sync
- REST for login, registration, and lobby actions
- WebSockets for gameplay state and turn updates

Example WebSocket message:
{
  "type": "TURN_UPDATE",
  "player": "user@email.com",
  "position": 12
}

## Persistence
User profiles and game progress are stored on disk and reloaded on server restart.
The server periodically saves state to reduce data loss on crashes.

## Extensibility
New games reuse authentication, rooms, economy, and persistence.
Only the game logic changes when adding new titles.
