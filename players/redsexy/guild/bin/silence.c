main(string arg) {
  int silent_move;
  object cloak;
  cloak = present("guildsoul", this_player());

  if(arg == "off") {
      write("The movements of your Creatures will now be evident.\n");
      cloak->set_silent_move(0);
      return 1;
    }
  if(arg == "on") {
    write("The movements of your Creatures will now be silent.\n");
    cloak->set_silent_move(1);
    return 1;
    }
  else{
    notify_fail("Syntax: silence on or off\n");
    return 0;
    }
}
