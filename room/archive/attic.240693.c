inherit "room/room";

int lamp_is_lit;

reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_light(1);
        short_desc="The attic";
        long_desc=
            "This is the attic above the church.\n" +
	    "There is a door to the west,\n"+
            "and you notice a glowing portal to the north.\n"+
            "@@lamp_desc";
        dest_dir=({
            "room/elevator","west",
            "room/statroom","north",
                 });
        items=({ 
            "door","@@door_desc",
              });
    }
}

init() {
    ::init();
    add_action("west","west");
    add_action("open", "open");
    add_action("push", "push");
    add_action("push", "press");
    add_action("close", "close");
}

lamp_desc() {
    if (lamp_is_lit)
        return("The lamp beside the elevator is lit.\n");
    else return "";
}

door_desc() {
    if ("room/elevator"->query_door() &&
        "room/elevator"->query_level()==3)
        return("The door is open");
    else
        return("The door is closed");
}

west() {
    if ((!"room/elevator"->query_door()) ||
	"room/elevator"->query_level() != 3) {
	write("The door is closed.\n");
	return 1;
    }
    ::move();
    return 1;
}

open(str) {
    if (str != "door")
	return 0;
    if ("room/elevator"->query_level() != 3) {
	write("You can't when the elevator isn't here.\n");
	return 1;
    }
    "room/elevator"->open_door("door");
    return 1;
}

close(str) {
    if (str != "door")
	return 0;
    "room/elevator"->close_door("door");
    return 1;
}

push(str) {
    if (str && str != "button")
	return 0;
    if ("room/elevator"->call_elevator(3))
	lamp_is_lit = 1;
    return 1;
}

elevator_arrives() {
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}
