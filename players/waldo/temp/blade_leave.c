int main() {
  object prev_room, thief;
  thief=this_player();

  if (file_name(environment(thief)) != "players/blade/guild/hideout") {
    write("You try to leave the hideout, and notice that you already left.\n");
    return 1;
  }
  prev_room=present("thiefsoul",thief)->prev_environment();
  if (objectp(prev_room))
    //        thief->move_player("X", hide);
  move_object(thief,prev_room);
  else   
    //        thief->move_player("X#" + GM->query_room(gd));
  move_object(thief,"guild/master"->query_room("guild/master"->
                                               query_number("thief")));
  write("You have returned.\n");
  return 1;
}








