inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "Third floor of demon tower";
     long_desc = "This is the third floor.\n" +
                 "There isn't much here.  Just some blood stains on\n" +
                 "the floor.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor4","up",
                   "players/topaz/rooms/tower/floor2","down",
 
                     });

     items =({"floor","It has blood stains on it",
              "tower","You feel as bad as ever because of the tower's evil aura",
              "stairs","You feel like you should get back down them",
              "stairway","It leads up to the unknown and back down to where you were",
              "blood","Looks like there was a fight here"
              "stains","The blood of a careless creature who wandered in here",
              "stone","The black stone still makes you feel uncomfortable",
              });
       clone_list = ({ 1, 1, "black Demon Soldier", MTOWER "soldier3",
           ({"set_name","black Demon Soldier",
            "set_long","An ugly demon.\n" +
            "This demon soldier will fight to protect its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       2, 1, "black Demon Corporal", MTOWER "corporal3",
           ({"set_name","black Demon Corporal",
            "set_long","An ugly demon.\n" +
            "This demon corporal won't let you out of this room alive!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       3, 1, "black Demon Lieutenant", MTOWER + "lieutenant3",
           ({"set_name","black Demon Lieutenant",
            "set_long","An ugly demon.\n" +
            "This demon lieutenant will do all in its power to guard its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       4, 1, "black Demon Captain", MTOWER + "captain3",
           ({"set_name","black Demon Captain",
            "set_long","An ugly demon.\n" +
            "This demon captain is under strict orders not to let anyone by!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       5, 1, "black Demon Colonel", MTOWER + "colonel3",
           ({"set_name","black Demon Colonel",
            "set_long","An ugly demon.\n" +
            "This demon colonel will CRUSH anyone who tries to get by him!\n" +
            "It has a tattoo of a white crown on its chest.\n", }), });
       set_light (1);
    ::reset();
  replace_program("room/room");
}
