inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc="A shimmering void";
  long_desc="You are in a shimmering void; blackness surrounds you and you can see the\n"
	+ "stars in the distance. You can see two portals, a white portal and a grey\n"
	+ "portal - you feel as if you could reach them as you seem to be able to move\n"
	+ "without effort in these strange, weightless surroundings.\n";
  items=({ "void", "It's inky black, with stars shining out from it",
	"stars", "It's like the night sky, only they're all around you",
	"portal", "Which portal, white portal or grey portal",
	"portals", "Which portal, white portal or grey portal",
	"white portal", "It shimmers in front of you. Through it, you can see some kind of building",
	"grey portal", "This portal is opaque; snakelike figures dance on it" });
}

init() { ::init(); add_action("enter", "enter"); }

enter(str) {
  object skin;
  if(str=="portal") {
    write("Which portal, white portal or grey portal?\n");
    return 1;
  }
  if(str=="white portal") {
    write("You enter the white portal.\n");
    this_player()->move_player("through the white portal#room/church");
    destruct(this_object());
    return 1;
  }
  if(str=="grey portal") {
    skin=present("puzzle_quest_skin",this_player());
    if(!skin) {
      write("You try to enter the portal, but it drags at you and won't let you through!\n");
      return 1;
    }
    if(this_player()->query_real_name()!=skin->query_finder()) {
      write("You enter the portal, but as you are on the threshold of a strange and bizarre\n"
	+ "new world, a voice declaims: Ha! You thought you would do THAT? No way ......\n"
	+ "You are transported somewhere, and you feel dizzy and weak.\n");
      transfer(this_player(),"room/church");
      this_player()->reduce_hp(this_player()->query_hp());
      this_player()->reduce_sp(this_player()->query_sp());
      destruct(this_object());
      return 1;
    }
    write("You enter the grey portal.\n");
    this_player()->move_player("through the white portal", clone_object("players/moonchild/puzzle/puzzle"));
    destruct(this_object());
    return 1;
  }
}

long(str) {
  if(!str) return write(long_desc);
  return ::long(str);
}
