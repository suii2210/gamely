namespace monopoly {
bool IsMoveAllowed(int from, int to, int board_size) {
  return from >= 0 && to >= 0 && to < board_size;
}
}  // namespace monopoly
