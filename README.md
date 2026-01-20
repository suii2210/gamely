# Monopoly Arcade

Monopoly Arcade is a client-server game where a React UI communicates with an authoritative C++ game server over HTTP and WebSockets.

## Architecture
- React client: UI only, never decides game results.
- C++ server: authoritative logic, anti-cheat, deterministic rules.
- REST for auth and lobby actions.
- WebSockets for real-time gameplay updates.

## Repository layout
- backend/ : C++ server
- frontend/ : React app
- docs/ : architecture and design docs

## Notes
- The server rolls dice, validates moves, and computes economy.
- The client renders the board and sends player intent only.
"# gamely" 
