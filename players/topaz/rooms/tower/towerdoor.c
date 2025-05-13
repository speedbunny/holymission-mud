inherit "room/room";

int door_is_open, door_is_locked;
object topazdemon,key;

reset(arg) {
    if (!arg) {
        set_light(1);
	short_desc="Outside the demon tower";
        long_desc=
            "Before you stands an impressive looking tower.\n" +
            "It looks like it could withstand almost any assault.\n" +
            "There is a big door on the front that looks like it gets\n" +
            "quite a bit of use.  The tower is all black and seems to\n" +
            "pulse with evil energy.  Just looking at it makes you wish\n" +
            "that you were not here, but safe at home!\n";
        dest_dir=({
            "/players/topaz/rooms/tower/floor1","north",
            "/players/topaz/rooms/demons/crevice","south",
                 });
        items=({
            "tower","The tower drains your will to live",
            "runes","Strange runes in another tongue",
            "door","There are strange runes all over this door.\n" +
                   "The door seems to be the only way into and out of the tower.\n" +
                   "@@door_desc",
              });
    }
    if (!topazdemon || !living(topazdemon)) {
	object key;
        topazdemon = clone_object("obj/monster");
	topazdemon->set_name("demon");
        topazdemon->set_alias("topazdemon");
        topazdemon->set_race("demon");
        topazdemon->set_size(3);
	topazdemon->set_level(13);
        topazdemon->set_wc(17);
        topazdemon->set_ac(6);
        topazdemon->set_aggressive(1);
	topazdemon->set_hp(400);
	topazdemon->set_al(-100);
        topazdemon->add_money(500+random(601));
	topazdemon->set_short("An ugly demon");
        topazdemon->set_long("An ugly demon with a tattoo of a white crown on it's chest.\n");
	move_object(topazdemon, this_object());
	key = clone_object("obj/treasure");
	key->set_id("key");
	key->set_alias("tower key");
	key->set_short("A runed key");
        key->set_long("It has unintelligible runes on it.\n");
	key->set_value(10);
	key->set_weight(1);
	transfer(key, topazdemon);
    }
    door_is_open = 0; door_is_locked = 1;
}

door_desc() {
    if (door_is_open) 
        return("The door is open");
    else
	return("The door is closed");
}

init() {
    ::init();
    add_action("open", "open");
    add_action("unlock", "unlock");
    add_action("north", "north");
    add_action("read", "read");
}

open(str) {
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
    say(this_player()->query_name() + " opened the door.\n");
    return 1;
}

unlock(str) {
    if (str && str != "door")
	return 0;
    if (door_is_open || !door_is_locked)
	return 0;
    if (!present("tower key", this_player())) {
	if (present("key", this_player()))
	    write("You don't have the right key.\n");
	else
	    write("You need a key.\n");
	return 1;
    }
    door_is_locked = 0;
    write("Ok.\n");
    say(this_player()->query_name() + " unlocked the door.\n");
    return 1;
}

north() {
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    if (topazdemon && present(topazdemon, this_object())) {
	write("The demon growls and won't let you past.\n");
	return 1;
    }
    ::move();
    return 1;
}

read(str) {
    if(str == "runes") {
        write("You are unable to read them.\n");
        write("They are written in blood though!\n");
        return 1;
    } else {
         notify_fail("Read what?\n");
    }
}

query_door() {
    return !door_is_open;
}

open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}
