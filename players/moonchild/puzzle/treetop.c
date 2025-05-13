inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The top of a pine tree";
  long_desc="You are sitting gently perched near the top of a tall pine tree. The smell of\n"
	+ "the pine needles fills the air. You feel sleepy and contented sitting up here.\n";
  dest_dir=({ "players/moonchild/trollslayer/hillock", "down" });
  smell="The gentle perfume of pine needles wafts through your nostrils.";
  items=({ "tree", "A great tall pine tree" });
}

init() { ::init(); add_action("sleep", "sleep"); }

sleep() {
  object wand;
  wand=present("enter_puzzle_wand",this_player());
  if(!wand) {
    say(this_player()->query_name() + " goes to sleep in the tree.\n");
    write("You go to sleep.\n"
	+ "As you sleep, you feel a spiritual presence stealing over you.\n"
	+ "It starts to talk to you.\n"
	+ "It says: I am the ghost of the father of King Dmitri. He has been imprisoned\n"
	+ "         in time and space by a rebellious magician. I am able to help you\n"
	+ "         if you have the right wand to break the enchantment that stops\n"
	+ "         mortals from entering his prison, but only you can actually free him.\n\n"
	+ "You awake again, feeling rather disturbed.\n");
    return 1;
  }
  if(wand->query_finder()!=this_player()->query_real_name()) {
    say(this_player()->query_name() + " goes to sleep in the tree.\n");
    write("You go to sleep.\n"
	+ "A voice tells you: Your wand is corrupted, it is impure.\n"
	+ "                   Find a true one to find your way.\n"
	+ "You awake again, feeling rather disturbed.\n");
    return 1;
  }
  say(this_player()->query_name() + " goes to sleep in the tree.\n");
  write("You go to sleep in the tree. A voice speaks to you in your dreams and you\n"
	+ "feel yourself moving. When you eventually wake up you are somewhere completely\n"
	+ "different.\n");
  transfer(this_player(),clone_object("players/moonchild/puzzle/void"));
  log_file("moonchild.quest", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
        + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "entered the void.\n");
  say(this_player()->query_name() + " is no longer here.\n");
  return 1;
}
