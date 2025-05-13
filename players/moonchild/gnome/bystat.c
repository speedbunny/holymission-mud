/* Uglymouth, 931209, fixed query_name()/query_real_name() mismatch */
inherit "room/room";

string last_name;

reset(arg) {
  if(arg) return;
  short_desc="On a dark path";
  long_desc="You are on a dark path, leading east and west.\n"
	+ "To the east, a huge statue looms above you.\n";
  dest_dir=({ "players/moonchild/gnome/dtemple", "east",
	"players/moonchild/gnome/dpath", "west" });
  items=({ "statue", "This is a statue of a fire demon. It seems to glow a dim red colour" });
  property=({ "no_teleport", "no_sneak" });
  enable_commands();
}

init() {
  ::init();
  add_action("east", "east");
}

east() {
  if(lower_case(this_player()->query_name())!=last_name) {
    tell_room(this_object(),
	"The statue says: Give me the password and you may pass.\n");
    return 1;
  }
  tell_room(this_object(), "The statue says: You may pass.\n");
  return 0;
}

catch_tell(str) {
  string who,what;
  if(sscanf(str,"%s says: %s\n",who,what)!=2) return;
  if(lower_case(what)==lower_case("players/moonchild/cave/c22"->query_password())) {
    last_name=lower_case(who);
    tell_room(this_object(), "The statue says: You may pass, " + who + ".\n" +
                             who + " is sucked away.\n");
    move_object(this_player(),"/players/moonchild/gnome/dtemple");
    tell_object(this_player(),"You are sucked away and land elsewhere.\n");
  }
  else tell_room(this_object(), "The statue laughs hollowly.\n");
}

query_last_name() {
  return last_name;
  }
