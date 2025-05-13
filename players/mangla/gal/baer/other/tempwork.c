inherit "room/room";
#include "/players/baer/baerdefs.h"
string shield;

reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
         set_light(1);
         short_desc=RED+"       Welcome to the Snakepit"+RESET;
         long_desc="\n";
         
         dest_dir=({
	    "room/church",                                "church",
            "players/tuppence/workroom",                  "tups",
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
  move_object(clone_object("obj/mail_reader"), this_player());
//  
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

exit() {
    object ob;
    if (ob = present("mailread", this_player()))
	destruct(ob);
    if (FP("baer") && TP->RNAME != "baer") {
      tell_object(FP("baer"),CAP(TP->RNAME) +" has left your workroom.\n");
  }
}

