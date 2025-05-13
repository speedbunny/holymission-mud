inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "Second floor of demon tower";
     long_desc = "This is the second floor of the demon tower.\n" +
                 "To the east, under the stairway is a small doorway.\n" +
                 "There are ugly statues in the corners of the room.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor3","up",
                   "players/topaz/rooms/tower/floor2a","east",
                   "players/topaz/rooms/tower/floor1","down",
 
                     });

     items =({"tower","You still get nervous when you look at this tower",
              "door","Wonder what's in there",
              "doorway","Wonder what's in there",
              "stairs","Still going up and down",
              "stairway","There is a door under them leading east",
              "stone","The dark stone makes you feel weak",
              "statue","A demon killing a helpless elf",
              "statues","They show various cruel acts",
              "corner","There is a statue in it",
              "corners","There are statues in them",
              });
       property = ({"no_teleport","no_sneak","no_steal"});
       clone_list = ({ 1, 1, "black Demon Soldier", MTOWER "soldier2",
           ({"set_name","black Demon Soldier",
            "set_long","An ugly demon.\n" +
            "This demon soldier will fight to protect its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       2, 1, "black Demon Corporal", MTOWER "corporal2",
           ({"set_name","black Demon Corporal",
            "set_long","An ugly demon.\n" +
            "This demon corporal won't let you out of this room alive!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       3, 1, "black Demon Lieutenant", MTOWER + "lieutenant2",
           ({"set_name","black Demon Lieutenant",
            "set_long","An ugly demon.\n" +
            "This demon lieutenant will do all in its power to guard its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       4, 1, "black Demon Captain", MTOWER + "captain2",
           ({"set_name","black Demon Captain",
            "set_long","An ugly demon.\n" +
            "This demon captain is under strict orders not to let anyone by!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       5, 1, "black Demon Colonel", MTOWER + "colonel2",
           ({"set_name","black Demon Colonel",
            "set_long","An ugly demon.\n" +
            "This demon colonel will CRUSH anyone who tries to get by him!\n" +
            "It has a tattoo of a white crown on its chest.\n", }), });
       set_light (1);
    ::reset();
  replace_program("room/room");
}
