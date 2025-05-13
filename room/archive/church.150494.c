/* CHURCH.C - Programmed by Herp. */
/* 090293: Ethereal Cashimor: Religion added, light_text added */
/* 090393: Ethereal Cashimor: Taking hat off when entering church */
/* 250393: Ethereal Cashimor: Smell after death */
/* 230493: Ethereal Cashimor: New light_text when believing */
/* 240693: Ethereal Cashimor: Old elevator installed */
/* 260693: Moonchild: Time till reboot shown on clock (sorta) */
/* 240793: Galadriel: Corrected descs of altar and candles */
/* 240793: Galadriel: Updated west wall desc, added hole desc */
/* 150993: Ethereal Cashimor: Wheel changed to main reset instead of first */
/* 300993: Ethereal Cashimor: Moved the elevator one way to the west */

#define RELIGION "Illuvatar"
#include "/obj/lw.h"

inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
    short_desc="Village church";
    long_desc=
	"You are in the local village church. The church has the service of "
      + "reviving ghosts. Dead people come to church and pray. There is a "
      + "huge pit in the center. Back on the north wall is an entrance to the "
      + "new Holy Mission Wedding Chapel. In the east wall you notice "
      + "the entrance to a small side room, the church portal opens to the "
      + "south. You feel the peace and holiness of this place and you are sure"
      + " the gods would punish the sacrilege of shedding blood here. There is"
      + " a sideroom to the west.\n\n"
      + "Please note: We don't like serial killers.\n"
      + "             Offenders will be punished.\n\n"
      +"WE ARE NOT OFFICIALLY OPEN - YOU PLAY AT YOUR OWN RISK. "
      +"SO BE WARNED AND DON'T COME CRYING IF YOU DIE! ALSO "
      +"TAKE NOTE THAT THE MUD IS OPEN TEMPORARILY. IT COULD "
      +"CLOSE OR CRASH AT ANY TIME. BE WARNED!!!!!!\n\n";
    dest_dir=({
	"players/moonchild/wedding/chapel","north",
	"room/vill_green","south",
	"players/herp/room/father","east",
        "players/cashimor/rooms/sideroom","west" });
    items=({
	"clock", "@@display_clock@@",
	"candles", "They are secured by your conscience",
	"pit",  "In the middle of the church is a deep pit.\n"+
		"It was used for sacrifice in the old times, but nowadays\n"+
		"it serves the rats for domicile",
	"altar", "The altar is golden and is lit by long white candles",
	"wall", "Which of the walls",
	"walls", "Which of the walls",
	"portal", "Daylight falls in from the south side",
        "west wall", "In the west wall is an exit to a sideroom",
        "hole", "It leads to a vertical shaft in the west wall",
	"east wall", "It has a small entrance to the east",
	"north wall",
	"You see a beautiful golden altar and white candles burning on it.\n"+
	"In the wall there is an entrance to the wedding chapel to the north.\n"
	+"Over the altar you see a big church clock",
	"entrance", "The north entrance leads to the wedding chapel.\n"+
		    "The east entrance leads to a praying room"
	});
		
    property=({ "no_fight", "no_steal", "has_fire" });
    smell="The smell of burning incense and candles hangs here.";
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
  add_action("move","enter");
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
  }
  return ::move(str);
}

remove_ghost(str) {
string belief;
object church;

  belief=this_player()->query_religion();
  if(!belief) {
    write("You are now a devout follower of "+RELIGION+".\n");
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

display_clock() {
  if("obj/tick"->qry_timer_value()<0)
    return "The clock shows midnight, and appears to have stopped";
  return "It is labeled in gothic lettering, from I to XII.\n"
	+ "It currently shows the time to be "
	+ ctime(82800-"obj/tick"->qry_timer_value())[11..15]
	+ ".\nBelow it is inscribed: The world endeth at midnight";
}

light_text(str) {
  write("You hold the "+str+" into the holy candles of the altar to light it.\n");
  say(this_player()->query_name()+" lights a "+str+",\n"
    + "using the holy candles of the altar.\n");
  if(this_player()->query_religion()==RELIGION) {
    write("You feel very bad about doing this at the altar of your own god!\n"
        + "His revenge might take you one day!\n");
  }
}
