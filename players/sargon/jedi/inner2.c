inherit "room/room";

#include "/players/mangla/defs.h"



void reset(int arg) {

    object board;

    if(arg)
        return;

    short_desc = "Inner Sanctum";

    long_desc =


              "This is the inner sanctum of the Jedis Guild.\n" +
              "Only members of the guild are allowed this far\n" +
              "and only members may pass this point. This is also\n" +
              "the place to leave any unused but valuable equipment\n" +
              "for your fellow jedis to use. Please be kind and only\n" +
              "leave and take what you need.\n" +
              RESET;

    set_light(1);

    property=({"no_teleport"});

    smell="\nThe scent of ozone crispness is ever present.\n";

    dest_dir=({PATH + "guild/caperoom","east",
               PATH + "guild/room","up"

             });

    MOVE(clone_object("/boards/guilds/jedi_guild"),TO);
//    MOVE(clone_object(PATH+"guild/yoda"),TO);
}


init() {
  ::init();
   if(TP->query_real_guild()!= 4 && !TP->query_immortal()) {
    say("You are not one with the force, you must leave this place.\n");
    printf("You cannot enter here.\n");
    TP->MOVEP("is moved#/players/mangla/guild/room");
    return;
    }
}
