inherit "room/room";

/*
 * This is an elevator.
 * floor 2: church
 */

#define STILL	0
#define DOWN	1
#define UP	2

int level;
int door_is_open;
int time_to_close_door;
int dest;		/* Where we are going. */
int moving_time;	/* How long we are going to move. */
int delay_to_reset;	/* Move back to origin automatically after a delay. */
string *outside;

init() {
    ::init();
    add_action("press", "press");
    add_action("press", "push");
    add_action("open_door", "open");
    add_action("close_door", "close");
    add_action("go_east", "east");
}

reset(arg) {
    if (!arg) {
        set_light(1);
        short_desc="elevator";
        long_desc=
            "You are in the elevator. On the wall are three buttons,\n"+
            "numbered 1 to 3.\n"+
            "@@door_desc@@.\n";
        items=({
            "door","@@door_desc",
            "button","There are three buttons, numbered 1 to 3",
            "buttons","The buttons can be used to select the desired level",
              });
        no_obvious_msg="";
        level = 2;
        dest = 2;
        moving_time = 0;
        outside=({"room/wiz_hall", "room/church", "room/attic" });
    }
    door_is_open = 0;
    remove_call_out("auto_close");
}

/*
 * Return true if door is open.
 */

query_door() { return door_is_open; }

door_desc() {
    if (door_is_open)
	return("There is an open door to the east");
    if (!door_is_open)
	return("There is a closed door to the east");
}

press(button) {
    string b;
    if (!button)
	return 0;
    if (door_is_open) {
#if 0
	write("Nothing happens.\n");
#endif
	return 1;
    }
    if (moving_time > 0) {
#if 0
	write("The elevator is still moving.\n");
#endif
	return 1;
    }
    if (sscanf(button, "button %s", b) != 1)
	b = button;
    if (b == "1" || b == "one")
	dest = 1;
    if (b == "2" || b == "two")
	dest = 2;
    if (b == "3" || b == "three")
	dest = 3;
    if (dest == level) {
	write("You are already at level " + dest + ".\n");
	return 1;
    }
    if (dest > level) {
	moving_time = dest - level;
	write("The elevator jerks upward.\n");
	say("The elevator jerks upward.\n");
    }
    if (level > dest) {
	moving_time = level - dest;
	write("The elevator starts moving downward.\n");
	say("The elevator starts moving downward.\n");
    }
    if (dest == 1 || level == 1)
	moving_time += 10;
    moving_time += 1;
    set_heart_beat(1);
    return 1;
}

auto_close() {
    tell_room(this_object(),"The door swings shut.\n");
    tell_room(outside[level-1],"The door of the elevator swings shut.\n");
    door_is_open = 0; 
    time_to_close_door = 0;
}

heart_beat() {
    if (time_to_close_door > 0) {
	time_to_close_door -= 1;
	if (time_to_close_door == 0) {
	    say("The door swings shut.\n");
	    door_is_open = 0; 
            remove_call_out("auto_close");
	}
    }
    if (moving_time <= 0)
	return;
    moving_time -= 1;
    if (moving_time > 0) {
	say("The elevator continues...\n");
	return;
    }
    say("The elevator slows down and stops\n");
    set_heart_beat(0);
    level = dest;
    outside[level-1]->elevator_arrives();
}

open_door(str)
{
    if (str != "door")
	return 0;
    if (door_is_open) {
	write("It is already open!\n");
	return 1;
    }
    if (moving_time > 0) {
	write("The door is stuck.\n");
	return 1;
    }
    door_is_open = 1;
    time_to_close_door = 3;
    call_out("auto_close",10);
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " opened the door.\n");
    return 1;
}

close_door(str)
{
    if (str != "door")
	return 0;
    if (!door_is_open) {
	write("It is closed!\n");
	return 1;
    }
    remove_call_out("auto_close");
    door_is_open = 0;
    time_to_close_door = 0;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) + " closed the door.\n");
    return 1;
}

go_east() {
    if (moving_time > 0) {
	write("You can't go anywhere when the elevator is moving.\n");
	return 1;
    }
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    this_player()->move_player("east#"+outside[level-1]);
    return 1;
}

query_level() { return level; }

/*
 * This routine is called from various rooms that the elevator connects to.
 */
call_elevator(button) {
    if (door_is_open) {
	write("The door seems to be open...\n");
	return 0;
    }
    if (moving_time > 0) {
	write("The lift is still moving:"+moving_time+"\n");
	return 0;
    }
    dest = button;
    if (dest == level)
	return 0;
    write("A little white lamp beside the button lights up.\n");
    say("A little white lamp beside the button lights up.\n");
    if (dest > level)
	moving_time = dest - level;
    if (level > dest)
	moving_time = level - dest;
    if (dest == 1 || level == 1)
	moving_time += 10;
    moving_time += 1;
    set_heart_beat(1);
    return 1;
}

/*
 * Only list inventory if not looking at anything special.
 */
can_put_and_get()
{
    return 0;
}
/*
 * Called by others to see if the elevator is moving
 */
is_moving() { 
    if (level == dest )
	/* Still */
	return 0;
    if(level > dest)
	/* down */
	return 1;
    /* up */
    return 2;
}
