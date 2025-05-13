/* Changed by Cashimor: added candles and has_fire */
/* 011092, 021092 */
#include "std.h"

int lamp_is_lit, reboot_time, time_from_reset, last_reset_cycle;
int list_length;

reset(arg)
{
    if (time_from_reset)
	last_reset_cycle = time() - time_from_reset;
    time_from_reset = time();
    if (arg)
	return;
    set_light(1);
    reboot_time = time();
}

query_property(arg) {      /* the curch is a no_fighting area */
  switch(arg) {
  case "no_fight": return 1;
  case "has_fire": return 1;	/* For the candles */
  case "no_steal": return 1;
  }
} 

try_attack(ob) {
  tell_object(ob,"The gods are angry about your sacrilege. You feel bad.\n");
  say("A flash strikes "+ob->query_name()+".\n",ob);
  ob->reduce_hit_point(random(100)+1);

  return 1; /* HERP non-attacking areas will return 1, att. will return 0 */

}

init()
{
    add_action("west", "west");
    add_action("open", "open");
    add_action("down", "down");
    add_action("push", "push");
    add_action("push", "press");
    add_action("close", "close");
    add_action("pray", "pray");
    add_action("pray", "regenerate");
    add_action("south", "south");
    add_action("east", "east");
    add_action("north", "north");
    add_action("enter", "enter");
}

short() {
    return "Village church";
}

long(str)
{
    if (str == "clock") {
	int i, j;
	write("The clock shows ");
	i = time() - reboot_time;
	j = i / 60 / 60 / 24;
	if (j == 1)
	    write("1 day ");
	else if (j > 0)
	    write(j + " days ");
	i -= j * 60 * 60 * 24;
	j = i / 60 / 60;
	if (j == 1)
	    write("1 hour ");
	else if (j > 0)
	    write(j + " hours ");
	i -= j * 60 * 60;
	j = i / 60;
	if (j == 1)
	    write("1 minute ");
	else if (j > 0)
	    write(j + " minutes ");
	i -= j * 60;
	if (i == 1)
	    write("1 second");
	else if (i > 0)
	    write(i + " seconds");
	write("\n");
	if (call_other(this_player(), "query_level") < 20)
	    return;
	write("Time since reset is " + (time() - time_from_reset) +
	      " seconds.\n");
	if (last_reset_cycle)
	    write("Reset cycle: " + last_reset_cycle + "\n");
	write("Free block list length: " + list_length + "\n");
	return;
    }
    if (str == "door") {
	if (!call_other("room/elevator", "query_door", 0) &&
	    call_other("room/elevator", "query_level", 0))
	    write("The door is open.\n");
	else
	    write("The door is closed.\n");
	return;
    }
  if(str=="candles") {
    write("They are secured by your conscience.\n");
    return;
  }
    if (str == "pit") {
	write("In the middle of the church is a deep pit.\n"+
	      "It was used for sacrifice in the old times, but nowadays\n" +
	      "it serves the rats for domicile.\n");
	return;
    }
  if(str=="altar") {
    write("The altar is golden and is lit by long white candles.\n");
    return;
  }
  if((str=="wall")||(str=="walls")) {
    write("Which of the walls?\n");
    return;
  }
  if(str=="portal") {
    write("Daylight falls in from the south side.\n");
    return 1;
  }
  if(str=="west wall") {
    write("There is a door in the west wall, with a button besides it.\n");
    return;
  }
  if(str=="east wall") {
    write("It has a small entrance to the east.\n");
    return;
  }
  if(str=="north wall") {
    write("You see a beautiful golden altar and white candles burning on it.\n"
        + "In the wall there is an entrance to the wedding chapel to the north.\n"
	 + "Over the altar you see a big church clock.\n");
    return;
  }
  if(str=="entrance") {
    write("The north entrance leads to the wedding chapel.\n"
	+ "The east entrance leads to a praying room.\n");
    return;
  }
  write("You are in the local village church. The church has the service of\n"
      + "reviving ghosts. Dead people come to church and pray. There is a\n"
      + "huge pit in the center. At the west wall you see a door with a\n"
      + "button besides it, back on the north wall is an entrance to the\n"
      + "new Holy Mission Wedding Chapel. In the east wall you notice\n"
      + "the entrance to a small side room, the church portal opens to the\n"
      + "south.\n"
      + "You feel the peace and holiness of this place and you are sure the\n"
      + "gods would punish the sacrilege of shedding blood here.\n");
      write("\nPlease note: We don't like serial killers.\n"
            + "             Offenders will be punished.\n");
      write("\n");
  if (lamp_is_lit) write("The lamp beside the elevator is lit.\n");
  write("     There are three obvious exits: north, south and east.\n");
}

id(str) {
  return str=="door"  || str=="east wall" || str=="clock"  || str=="candles" ||
         str=="altar" || str=="entrance"  || str=="portal" || str=="wall"    ||
         str=="walls" || str=="west wall" || str=="pit"    ||
         str=="north wall";
}

xyzzy() {
    write("Everything shimmers.\n");
    write("You wake up elsewhere...\n");
    call_other(this_player(), "move_player", "elsewhere#room/test");
}

west() {
    if (call_other("room/elevator", "query_door", 0) ||
	call_other("room/elevator", "query_level", 0) != 2) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "west#room/elevator");
    return 1;
}
open(str)
{
    if (str != "door")
	return 0;
    if (call_other("room/elevator", "query_level", 0) != 2) {
	write("You can't when the elevator isn't here.\n");
	return 1;
    }
    call_other("room/elevator", "open_door", "door");
    return 1;
}

close(str)
{
    if (str != "door")
	return 0;
    call_other("room/elevator", "close_door", "door");
    return 1;
}

push(str)
{
    if (str && str != "button")
	return 0;
    if (call_other("room/elevator", "call_elevator", 2))
	lamp_is_lit = 1;
    return 1;
}

elevator_arrives()
{
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}

pray() {
    return call_other(this_player(), "remove_ghost", 0);
}

prevent_look_at_inv(str)
{
    return str != 0;
}

south() {
    call_other(this_player(), "move_player", "south#room/vill_green");
    return 1;
}

east() {
    this_player()->move_player("east#players/herp/room/father");
    return 1;
}

down() {
    this_player()->move_player("down#players/herp/room/pit");
    return 1;
}

north() {
    if(!this_player()->query_npc())
	this_player()->move_player("north#players/moonchild/wedding/chapel");
    return 1;
}

enter(str) { if (str=="pit") return down(); }

query_drop_castle() {
    return 1;
}

light_text(str) {
  write("You hold the "+str+" into the holy candles of the altar to light it.\n");
  say(this_player()->query_name()+" lights a "+str+",\n"
    + "using the holy candles of the altar.\n");
}
