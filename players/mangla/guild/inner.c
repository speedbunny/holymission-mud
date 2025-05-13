// 04.15.97 Airborne:  A quick fix for Sargon.  Got rid of some junk.
// Sargon: Tidy up alittle.  Some spaces not there, wouldn't chat to jedi line.
// 04.18.97 Airborne:  Installed into the game.

inherit "room/room";

#include "/players/mangla/defs.h"
#define this_guild GM->query_number("jedi")

void reset(int arg){
 object board;

  if(arg)return;
  short_desc = "Inner Sanctum";
  long_desc =
    "This is the inner sanctum of the Jedi Guild. " +
    "The room is strong with the force which prevents " +
    "everyone except members of the Guild from entering " +
    "and only members may pass this point.  This is also " +
    "the place to leave any unused but valuable equipment " +
    "for your fellow Jedi to use.  Please be kind and only " +
    "take what you need.\n ";

    set_light(1);
  property = ({"no_teleport","no_steal","no_hide","no_fight"});
    smell = "The scent of ozone crispness is ever present.\n";
    dest_dir = ({PATH + "guild/caperoom","east",
               PATH + "guild/room","up"
             });

    MOVE(clone_object("/boards/guilds/jedi_inner"),TO);
//  MOVE(clone_object(PATH+"guild/yoda"),TO);

}

init(){
 ::init();

  if(TP->query_guild()!= 4 && !TP->query_immortal()) {
    say("You are not one with the force, you must leave this place.\n");
    printf("Only those with the force may enter here.\n");
    TP->MOVEP("is repelled by the power of the Force#players/mangla/guild/room");
    return;
  }
  if(TP->query_real_guild()!= 4 && !TP->query_immortal()){
    CD->do_chat(this_guild,  " [* Jedi *] "+
    "There is a great disturbance in the Force.\n");

    return;
  }

}
