#define RELIGION "Illuvatar"
#include "/obj/lw.h"
/* mud@mud.edvz.uni-linz.ac.at 930205 Herp aka Herbert Rosmanith */
/* Modified for taking hat of when entering 090393 Cashimor      */
/* Modified for smell after death 250393 Ethereal Cashimor       */
/* Modified for lighttext when believing 230493 Cashimor         */

inherit "room/room";

int lamp_is_lit;

reset(arg) {

  if (!arg) {
    set_light(1);
    short_desc="Village church";
    long_desc=
	"You are in the local village church. The church has the service of\n"
      + "reviving ghosts. Dead people come to church and pray. There is a\n"
      + "huge pit in the center. At the west wall you see a door with a\n"
      + "button besides it, back on the north wall is an entrance to the\n"
      + "new Holy Mission Wedding Chapel. In the east wall you notice\n"
      + "the entrance to a small side room, the church portal opens to the\n"
      + "south.\n"
      + "You feel the peace and holiness of this place and you are sure the\n"
      + "gods would punish the sacrilege of shedding blood here.\n\n"
      + "Please note: We don't like serial killers.\n"
      + "             Offenders will be punished.\n\n"
      + "@@display_button";
    dest_dir=({
	"players/moonchild/wedding/chapel","north",
	"room/vill_green","south",
	"players/herp/room/father","east" });
    items=({
	"clock", "@@display_clock",
	"door", "@@display_door",
	"candles", "They are secured by your conscience.\n",
	"pit",  "In the middle of the church is a deep pit.\n"+
		"It was used for sacrifice in the old times, but nowadays\n"+
		"it serves the rats for domicile",
	"altar", "The altar is golden and is lit by long white candles.\n",
	"wall", "Which of the walls",
	"walls", "Which of the walls",
	"portal", "Daylight falls in from the south side",
	"west wall", "There is a door in the west wall, whith a button"+
		     "besides it",
	"east wall", "It has a small entrance to the east",
	"north wall",
	"You see a beautifull golden altar and white candles burning on it.\n"+
	"In the wall there is an entrance to the wedding chapel to the north.\n"
	+"Over the altar you see a big church clock",
	"entrance", "The north entrance leads to the wedding chapel.\n"+
		    "The east entrance leads to a praying room"
	});
		
    property=({ "no_fight", "no_steal", "has_fire" });
  }
}

init() {
object hat;

  ::init();
  if(this_player()->query_religion()==RELIGION) {
    if(hat=present("helmet",this_player())) {
      if(hat->query_worn())
        call_out("remove_hat",1);
    }
  }
  add_action("move","down");
  add_action("move","west");
  add_action("move","enter");
  add_action("push_button","push");
  add_action("push_button","press");
  add_action("open_door","open");
  add_action("close_door","close");
  add_action("remove_ghost","pray");
}

remove_hat() {
  write("You take off your hat, respecting "+RELIGION+".\n");
  say(lw(this_player()->query_name()+" takes off "
       + this_player()->query_possessive()+" hat in the church.\n"));
  command("remove helmet",this_player());
}

move(str) {
string verb;

  verb=query_verb();
  switch (verb) {
  case "enter": if (str!="pit") return;	/* Fallthrough */
  case "down":	this_player()->move_player("down#players/herp/room/pit");
		return 1;
  case "west":
	if ("room/elevator"->query_level()!=2 ||
	   !("room/elevator"->query_door())) {
	   notify_fail("The door is closed.\n");
	   return 0;
	}
	this_player()->move_player("west#room/elevator");
	return 1;
  }
  return ::move(str);
}

push_button(str) {
  if (str=="button") {
     if ("room/elevator"->call_elevator(2)) lamp_is_lit = 1;
     return 1;
  }
}

open_door(str) {
  if (str=="door") {
     if ("room/elevator"->query_level()!=2)
	write("You can't when the elevator isn't here.\n");
     else "room/elevator"->open_door("door");
     return 1;
  }
}

close_door(str) {
  if (str=="door") {
     "room/elevator"->close_door("door");
     return 1;
  }
}

remove_ghost(str) {
string belief;

  /* Religion added to the pray command, by Ethereal Cashimor, 090293 */
  belief=this_player()->query_religion();
  if(!belief) {
    write("You are now a devote follower of "+RELIGION+".\n");
    this_player()->set_religion(RELIGION);
    return 1;
  }
  if(belief!=RELIGION) {
    notify_fail("You are not a follower of "+RELIGION+"!\n");
    return 0;
  }
  if(!this_player()->remove_ghost()) return 0;
  this_player()->set_smell("Smells as if just reborn.");
  return 1;
}

try_attack(ob) {

  tell_object(ob,"The gods are angry about your sacrilege. You feel bad.\n");
  say("A flash strikes "+ob->query_name()+".\n",ob);
  ob->reduce_hit_point(random(100)+1);
  return 1;
}

elevator_arrives() {
  say("The lamp on the button beside the elevator goes out.\n");
  lamp_is_lit=0;
}

display_button() {
  if (lamp_is_lit) return "The lamp beside the elevator is lit.\n";
  else return "";
}

display_door() {
  if ("room/elevator"->query_door() && ("room/elevator"->query_level()==2))
       return("The door is open");
  else return("The door is closed");
}

display_clock() {
  return "It is labeled from I to XII";
}

/* Lighttext renewed by Cashimor, otherwise the light function is a bit 
   unclear. 090293 */

light_text(str) {
  write("You hold the "+str+" into the holy candles of the altar to light it.\n");
  say(this_player()->query_name()+" lights a "+str+",\n"
    + "using the holy candles of the altar.\n");
  if(this_player()->query_religion()==RELIGION) {
    write("You feel very bad doing this at the altar of your own god!\n"
        + "his revenge might take you one day!\n");
  }
}







