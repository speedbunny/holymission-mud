sp(string s)
  {
  say(capitalize(this_player()->query_name()) +" says "+ s
     +"\n");
  write("You said: "+ s +"\n");
  return 1;
  }
init()
  {
  add_action("sp","say");
  }
