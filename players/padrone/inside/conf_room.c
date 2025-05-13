/* conf_room.c -- the Conference Room */
/* Modified 170293 By Ethereal Cashimor to resemble a more fantasy like world.
   Hope Padrone doesn't mind. */
inherit "room/room";

status is_closed;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    smell="The air is pleasant here, but not very fresh.";
    set_light(1);
    short_desc="Padrone's Conference Room";
    long_desc="This is Padrone's Conference Room, a spacious and luxuriously\n"
            + "furnished room with a big table and a magical ball. When the\n"
            + "door is closed, nobody, not even a wizard (except for Padrone)\n"
            + "can enter this room. This includes teleporting. There is a\n"
            + "door leading west. @@print_door@@.\n";
    items=({"door","@@print_door@@",
            "room","You could reside her for ages",
            "table","Solid oak",
            "ball","Using the proper spell it can display images"});
    dest_dir=({"","west"});
  }
}

open(str) {
    if (!str || str != "door")
	return 0;
    if (!is_closed) {
	write("The door is already open.\n");
	return 1;
    }
    write("You open the door. Anybody can enter or leave now.\n");
    say(this_player()->query_name() +
	" opened the door. Anybody can enter or leave now.\n");
    is_closed = 0;
    return 1;
} /* open */

close(str) {
    if (!str || str != "door")
	return 0;
    if (is_closed) {
	write("The door is already closed.\n");
	return 1;
    }
    write("You close the door. Nobody can enter or leave now.\n");
    say(this_player()->query_name() +
	" closed the door. Nobody can enter or leave now.\n");
    is_closed = 1;
    write("As the door closes, the room automatically checks if any invisible\n" +
	  "players, monsters or items are present in the room.\n");
    say("As the door closes, the room automatically checks if any invisible\n" +
	"players, monsters or items are present in the room.\n");
    check_for_invisible();
    return 1;
} /* close */

check(str) {
    if (str)
	return 0;
    write("Checking if any invisible\n" +
	  "players, monsters or items are present in the room.\n");
    say("Checking if any invisible\n" +
	"players, monsters or items are present in the room.\n");
    check_for_invisible();
    return 1;
} /* check */


init() { 
  if (is_closed && call_other(this_player(), "query_name") != "Padrone") {
    write("Sorry, the conference room is occupied.\n");
    write("You'll have to wait outside.\n");
    tell_room(this_object(),this_player()->query_name()+" tried to magically\n"
            + "enter the conference room, but failed (haha!).\n");
    this_player()->move_player("back out again#players/padrone/inside/e_uhall");
  } 
  else {
	write("Welcome to Padrone's Conference Room!\n");
	add_action("open"); add_verb("open");
	add_action("close"); add_verb("close");
	add_action("check"); add_verb("check");
	add_action("west"); add_verb( "west");
    }
} /* init */

west() {
    if (is_closed) {
	write("The door is closed. You must open it before leaving.\n");
	return 1;
    }
    write("Goodbye. Thank you for visiting Padrone's Conference Room.\n");
    this_player()->move_player("west#players/padrone/inside/e_uhall");
    return 1;
} /* west */

print_door() {
  if (is_closed) return "The door is closed";
  return "The door is open";
} /* print_door */

query_closed() {
	return is_closed;
}

check_for_invisible() {
	object an_obj;
	string namestring, shortstring;
	int nr;

	an_obj = first_inventory(this_object());
	nr = 0;
	while (an_obj) {
		shortstring = an_obj->short();
		if (!shortstring) {

			nr += 1;
			write("\n");
			write("WARNING! Invisible object found:\n");
			namestring = an_obj->query_name();
			if (!namestring)
				namestring = "NO NAME";
			write("Name: " + namestring + "\n");
			write("Long description:\n");
			an_obj->long();
			write("\n");
		}
		an_obj = next_inventory(an_obj);
	}
	write("There are " + nr + " invisible objects in this room.\n");
	say("There are " + nr + " invisible objects in this room.\n");
} /* check_for_invisible */
