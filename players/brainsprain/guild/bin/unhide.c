int main() {
  if (this_player()->query_ghost()) {
    write("You try to show yourself to mortal men.\n");
    return 1;
  }
  if (!this_player()->query_invis()) {
    write("You are not hiding.\n");
    return 1;
  }
  present("thiefsoul",this_player())->do_unhide();
  return 1;
}








