# Gamely

Gamely is a multi-game online platform with shared accounts, coins, and multiplayer rooms.
Monopoly is the first game, built as a plug-in that runs inside the Gamely core.

## Phase 1: Monopoly
- Multiplayer Monopoly runs inside Gamely's shared systems.
- The server is authoritative: dice, movement, ownership, rent, jail, bankruptcy.
- Clients only send actions; results are validated on the server.

## Shared core systems
- Accounts: email + password (hashed).
- Profiles: coins and game stats persist across games.
- Multiplayer rooms: create/join rooms by game type; start when all players join.
- Economy: global coins earned by wins and match completion.
- Persistence: user data and game progress saved to disk and reloaded on restart.

## Architecture
- Backend: C++ authoritative server.
- Frontend: React UI for display and input.
- HTTP for auth and lobby, WebSockets for real-time gameplay.

## Extensibility
New games plug into a common Game interface and reuse auth, rooms, economy, and persistence.

## Repository layout
- backend/ : C++ server
- frontend/ : React app
- docs/ : architecture and API docs

## Docs
- docs/architecture.md
- docs/api.md
