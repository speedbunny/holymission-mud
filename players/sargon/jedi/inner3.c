inherit "room/room";

#include "/players/mangla/defs.h"
#define this_guild GM->query_number("jedi")



void reset(int arg) {

    object board;

    if(arg)
        return;

    short_desc = "Inner Sanctum";

    long_desc =




//I added to desc to justify query_real_guild  -Sargon_
              "This is the inner sanctum of the Jedis Guild.\n" +
              "The room is strong with the force which prevents\n" +

              "everyone except members of the guild from entering\n" +
              "and only members may pass this point. This is also\n" +
              "the place to leave any unused but valuable equipment\n" +
              "for your fellow jedis to use. Please be kind and only\n" +
              "leave and take what you need.\n" +
              RESET;

    set_light(1);

    property=({"no_teleport","no_steal","no_hide"});

    smell="\nThe scent of ozone crispness is ever present.\n";
    dest_dir=({PATH + "guild/caperoom","east",
               PATH + "guild/room","up"

             });

    MOVE(clone_object("/boards/guilds/jedi_guild"),TO);
//    MOVE(clone_object(PATH+"guild/yoda"),TO);
//if(( TP->query_immortal()) ||
//        (TP->query_guild() == this_guild))
//        return;
//    else {
//        write("You are not allowed in this place!\n");
//        TP->MOVEP("is moved#players/mangla/guild/room");
//  Changed by Sargon on 4/4/97
}


init() {
  ::init();
 if(TP->query_real_guild()!=4 && !TP->query_immortal()) {
    say("You are not one with the force, you must leave this place.\n");
    printf("Only those with the force may enter here.\n");
    TP->MOVEP("is moved#room/church");

             

}

}
