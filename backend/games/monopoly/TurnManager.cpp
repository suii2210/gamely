namespace monopoly {
int NextTurn(int current_turn, int player_count) {
  if (player_count <= 0) {
    return 0;
  }
  return (current_turn + 1) % player_count;
}
}  // namespace monopoly
