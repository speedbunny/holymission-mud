inherit "/boards/board";

void reset(int tick) {
  ::reset(tick); 
  if(tick)
    return;
  set_name("Archwiz To-Do board");
  my_env="room/arch/todo";    
}
 
void long() {
  if(this_player()->query_archwiz() && interactive(this_player()))
    ::long();
  else
    write("Illegal access! (logged)\n");
}
