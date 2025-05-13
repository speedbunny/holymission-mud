inherit "room/room";
#include "/players/baer/baerdefs.h"
string shield;

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {

         set_light(1);

         short_desc=RED+"       Welcome to the Snakepit"+RESET;

        long_desc=
            "\n" +
	    "\n";

        dest_dir=({
            "/players/baer/codingroom.c",                 "code",
            "/players/baer/room/testroom",                "test",
	    "room/church",                                "church",
            "players/tuppence/workroom",                  "tups",
            "players/exos/harem/bar",                     "bar",
            "players/matt/newworld/city/rooms/votebooth", "booth",
                 });

        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });

        property = ({
                     "no_sneak",
                     "no_steal",
                     "no_snoop",
                     "no_fighting",                
                   });

     smell = "Smells like a Snakepit should";

    }
}
init()
{
  ::init();
  add_action("_bring", "bring");
  add_action("_shield","shield");
    if (shield && (TP->RNAME) != "baer") {
	write("Baer has locked the room.\n");
	move_object(TP,"/room/church");
    }
    if (FP("baer") && TP->RNAME != "baer" && !shield) {
      tell_object(FP("baer"),CAP(TP->RNAME) +" has entered your workroom.\n");
    }
}

_shield(str) {
    if (str == "on") {
	shield = "on";
	return 1;
    }
    if (str == "off") {
	shield = !shield;
	return 1;
    }
    if (!str && !shield) {
	write("shield is off\n");
	return 1;
    }
    if (!str && shield) {
	write("shield is on\n");
	return 1;
    }
 }
_bring(str) {
  object target, troom;
  target = find_player(str);
  if(target) {
    troom = environment(target);
    write("You bring " + target->NAME + " into your Workroom.\n");
    say(TP->NAME + " brings " + target->NAME +
	" into the Workroom.\n");
    TELL(target, "You decide to go for a walk.\n");
    MOVE(target, TO);
    TELLR(troom, target->NAME + " was abducted by aliens.\n");
    return 1;
  }
  write("Bring whom?\n");
  return 1;
}

