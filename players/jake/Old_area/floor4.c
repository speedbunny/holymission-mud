inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "floor4";
  long_desc = 
	"You see lots of candy and junk food all over this room.\n"
	"It is almost impossible to walk in here.\n"
        "The room smells like chocolate.\n";
  items = ({ "candy", "The candy is all over the floor",
	"junk food", "the junk food is all over" });
  smell = "Mmmm... you smell chocolate!";
  dest_dir = ({ "players/jake/jhall","east" });
  clone_list = ({ 1, 1, "beth", "players/jake/monster/beth", 0 });

::reset();
replace_program("room/room");
}

