/* Coded by Blade on Holy Mission */
/* 12.3.94 */

inherit "room/room";

#include "/players/blade/area/blade_defs.h"
#define PROOM "/players/blade/guild/contest/plunder_room"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The Thief Contest room";
        long_desc=
"The thief contest room.  A scroll lies upon a pedestal in the center of\n"+
"the room.\n";

   dest_dir=({
            "/players/blade/guild/temple.c","west",
            PROOM,"east",
                 });
   items=({ 
     "scroll","An old scroll.  Perhaps you should read it",
     "pedestal","A granite pedestal with an ancient scroll lying upon it",
 });

        smell = "You smell nothing special.";
        enable_commands();
    }
}

init(){
  ::init();
    add_action("read","read");
    add_action("call_start","start");
  }

call_start(string arg){
  call_other(PROOM,"");
  PROOM->start(arg);
  return 1;
}

read(string str_arg){

if(str_arg=="scroll"){
  write("---------------------------------------------------------\n"+
        "                   The Thief Contest                     \n"+
        "---------------------------------------------------------\n"+
        "                        History                          \n"+
        "---------------------------------------------------------\n"+
        "     Ages ago, the most devout followers of Mask would   \n"+
        "gather once a year to revel in their God's power.  This  \n"+
        "mostly consisted of random acts of wanton evil.  Each    \n"+
        "worshipper would vie for the honor of being the one who  \n"+
        "was the most evil.  The Maskians always had a problem    \n"+
        "deciding what was the most evil act, and how these acts  \n"+
        "compared to the other worshipper's acts of evil.  So the \n"+
        "gathering would often end up in large fights and caused  \n"+
        "faction among the Maskians.  So one year, in an effort to\n"+
        "make thier evils more measurable, decided that stealing  \n"+
        "was to be the offical evil to be measure each persons    \n"+
        "devotion to Mask.  Later, a particularly confident       \n"+  
        "Maskian proposed that he would bet all his plunder that  \n"+
        "he was the best evildoer.  The others all matched his    \n"+
        "bet, and this tradition has continued until modern times.\n"+
        "---------------------------------------------------------\n"+
        "                        The Rules                        \n"+
        "---------------------------------------------------------\n"+
        "     These are the rules as stated by mutual agreement   \n"+
        "among Maskians for centuries past.                       \n"+
        "     The ritual must be kept secret.  Noone outside of   \n"+
        "religion must know about it, and only religion members   \n"+
        "are allowed to participate in the ritual.                \n"+
        "     The most evil person receives all the spoils of the \n"+
        "ritual, and the honor of being Mask's most devout        \n"+
        "follower, and thereby hope to receive more power from    \n"+
        "Mask.                                                    \n"+
        "---------------------------------------------------------\n"+
        "                    Contest Syntax                       \n"+
        "---------------------------------------------------------\n"+
        "     start contest for <integer> minutes                 \n"+
        "         to run the contest for <integer> minutes        \n"+
        "     contest                                             \n"+
        "         show who is in the lead                         \n");
  return 1;
}
return 0;
}









