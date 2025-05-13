#include "/players/arthur/defs/ardefs.h"
inherit "room/room";
string tpqs;
reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Arthur's Forest Entrance";

        long_desc=
         "You are standing at the edge of town. Two the north you can see\n"+
         "Sherwood Forest. To the south the main road in Sherwood continues\n"+
         "A bar sits towards the west where you can here the local gossip\n"+
         "from many of the village people. Two the east, there is a Weapon\n"+
         "and Armoury shop where you can buy many of the local favorite\n"+
         "adventuring items.\n";
        
        dest_dir=({
          AFOR+"forest1.c", "north",
          AAREA+"main_dr3", "south",
          AAREA+"ar_bar", "west",
          AAREA+"ar_shop", "east",

                 });

        items=({
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        property = ({
                     "no_teleport",
                    });
    }
}

init()
{       
    add_action("ST_QUE","start");
    ::init();
}

ST_QUE() {

        if (!tpqs || tpqs == "no_one" && TPN != "Someone")
         {object queitm;
         tpqs = TPN;
         queitm = clone_object("players/arthur/quest/obj/queitm");
         move_object(queitm,this_player()); 
         write("You have now started the quest!\n");
         say(tpqs+" starts the quest!\n");return 1;}
         
         else write(tpqs+" is already doing this quest.\n"); return 1;
         }
RST_QUE() {
 tpqs = "no_one";
 return 1;
}


