inherit "room/room";

int lamp_is_lit;
object leo;

reset(arg) {
    if (!arg) {
	set_light(1);
        short_desc="wizards hall";
        long_desc=
    "You are in the hall of the wizards.\n" +
    "There is a door to the west and a shimmering field to the north.\n"+
    "@@lamp_desc";
        no_obvious_msg="";
        hidden_dir=({
            "room/elevator","west",
            "room/quest_room","north",
                   });
    }
    if (!leo) {
	leo = clone_object("obj/leo");
	move_object(leo, this_object());
    }
}

init() {
    ::init();
    add_action("west", "west");
    add_action("open", "open");
    add_action("close", "close");
    add_action("push", "push");
    add_action("push", "press");
    add_action("north", "north");
}

lamp_desc() {
    if (lamp_is_lit)
	return("There is a lit lamp beside the elevator.\n");
    else return "";
}

open(str) {
    if (str != "door")
	return 0;
    if (call_other("room/elevator", "query_level", 0) != 1) {
	write("You can't when the elevator isn't here.\n");
	return 1;
    }
    call_other("room/elevator", "open_door", "door");
    return 1;
}

close(str) {
    if (str != "door")
	return 0;
    call_other("room/elevator", "close_door", "door");
    return 1;
}

west() {
    if (!"room/elevator"->query_door() ||
	"room/elevator"->query_level() != 1) {
	write("The door is closed.\n");
	return 1;
    }
    return ::move();
}

push(str) {
    if (str && str != "button")
	return 0;
    if ("room/elevator"->call_elevator(1))
	lamp_is_lit = 1;
    return 1;
}

elevator_arrives() {
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}

north() {
    if (!this_player()->query_wizard()) {
	write("A strong magic force stops you.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    return ::move();
}
