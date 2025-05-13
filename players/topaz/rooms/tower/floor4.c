inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "Top floor of demon tower";
     long_desc = "This is the top floor of the demon tower.  You sense\n" +
                 "a source of great evil in the room to the north.\n" +
                 "You think that now might be a good time to turn around\n" +
                 "and go home, while you still can!\n";

      dest_dir = ({"players/topaz/rooms/tower/floor4a","north",
                   "players/topaz/rooms/tower/floor3","down",
 
                     });

     items =({"tower","This has to be the most oppressive room you've ever seen",
              "stairs","You think you should be going down them right now",
              "stairway","You think you should be going down it right now",
              });
       clone_list = ({ 1, 1, "black Demon Soldier", MTOWER "soldier4",
           ({"set_name","black Demon Soldier",
            "set_long","An ugly demon.\n" +
            "This demon soldier will fight to protect its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       2, 1, "black Demon Corporal", MTOWER "corporal4",
           ({"set_name","black Demon Corporal",
            "set_long","An ugly demon.\n" +
            "This demon corporal won't let you out of this room alive!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       3, 1, "black Demon Lieutenant", MTOWER + "lieutenant4",
           ({"set_name","black Demon Lieutenant",
            "set_long","An ugly demon.\n" +
            "This demon lieutenant will do all in its power to guard its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       4, 1, "black Demon Captain", MTOWER + "captain4",
           ({"set_name","black Demon Captain",
            "set_long","An ugly demon.\n" +
            "This demon captain is under strict orders not to let anyone by!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       5, 1, "black Demon Colonel", MTOWER + "colonel4",
           ({"set_name","black Demon Colonel",
            "set_long","An ugly demon.\n" +
            "This demon colonel will CRUSH anyone who tries to get by him!\n" +
            "It has a tattoo of a white crown on its chest.\n", }), });
       set_light (1);
    ::reset();
  replace_program("room/room");
}
