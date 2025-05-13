inherit "room/room";
int door_is_open, door_is_locked, test;
object money;

reset(arg) {
  door_is_open = 0; door_is_locked = 1; test = 1;
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Treasure Room";
    long_desc =
"This is the treasure room of the Frost Giants. Here they store\n"+
"their wealth. It is a small room with smoke stains on walls \n";
    dest_dir = ({
"players/ted/frost/study","south"
    });
  }
  if (!money) {
    money = clone_object("obj/money");
    call_other(money, "set_money", random(2000)+1000);
    move_object(money, this_object());
  }
}

long(str) {
  ::long(str);
if ((str=="door") && call_other("players/ted/frost/study","query_ink_move")) {
  if (door_is_open)
    write("The door is open.\n");
  else 
    write("The door is closed.\n");
  }
if(!str && call_other("players/ted/frost/study","query_ink_move"))
  write("There is the outline of a door on the north wall.\n");
}

init() {
  ::init();
    add_action("open"); add_verb("open");
    add_action("unlock"); add_verb("unlock");
    add_action("north"); add_verb("north");
}


id(str) {
    return str == "door";
}

open(str) {
	if(call_other("players/ted/frost/study","query_ink_move")) {
    if (str && str != "door")
	return 0;
    if (door_is_open)
	return 0;
    if (door_is_locked) {
	write("The door is locked.\n");
	return 1;
    }
    door_is_open = 1;
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " opened the door.\n");
    return 1;
  }
}

unlock(str) {
	if(call_other("players/ted/frost/study","query_ink_move")) {
    if(present("king")) {
 	  write("The Frost Giant King gets in your way!\n");
      return 1;
    }
    if (str && str != "door")
	return 0;
    if (door_is_open || !door_is_locked)
	return 0;
    if (!present("frost_key", this_player())) {
	if (present("key", this_player()))
	    write("You don't have the right key.\n");
	else
	    write("You need a key.\n");
	return 1;
    }
    door_is_locked = 0;
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " unlocked the door.\n");
    return 1;
  }
}

north() {
  if(call_other("players/ted/frost/study","query_ink_move")) {
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(),"move_player","north#players/ted/frost/treasure");
    return 1;
  }
}

query_door() {
    return !door_is_open;
}

open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}
