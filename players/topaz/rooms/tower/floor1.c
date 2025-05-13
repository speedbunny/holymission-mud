inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "First floor of demon tower";
     long_desc = "The inside of this tower is no less impressive than the\n" +
                 "outside.There is a broad stairway leading up and down.\n" +
                 "The black stone of the tower oppresses you spirits even\n" +
                 "more from in here.  You know that there is great evil in\n" +
                 "this tower.  There are tapestries on the walls which\n" +
                 "depict gruesome acts of violence.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor2","up",
                   "players/topaz/rooms/tower/towerdoor","south",
                   "players/topaz/rooms/tower/treasury","down",
 
                     });

     items =({"tower","The black stone walls give you chills",
              "tapestries","They show helpless victims being slain mercilessly",
              "stairs","They go up and down.  Wonder where they lead",
              "stairway","It leads up and down.  You can only imagine where",
              "stone","Darker than night.  You hate to look at it",
              "wall","The wall is made of black stone",
              "walls","There are tapestries on them",
              });
       property=({"no_steal","no_sneak"});
       clone_list = ({ 1, 1, "black Demon Soldier", MTOWER "soldier1",
           ({"set_name","black Demon Soldier",
            "set_long","An ugly demon.\n" +
            "This demon soldier will fight to protect its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       2, 1, "black Demon Corporal", MTOWER "corporal1",
           ({"set_name","black Demon Corporal",
            "set_long","An ugly demon.\n" +
            "This demon corporal won't let you out of this room alive!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       3, 1, "black Demon Lieutenant", MTOWER + "lieutenant1",
           ({"set_name","black Demon Lieutenant",
            "set_long","An ugly demon.\n" +
            "This demon lieutenant will do all in its power to guard its king!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       4, 1, "black Demon Captain", MTOWER + "captain1",
           ({"set_name","black Demon Captain",
            "set_long","An ugly demon.\n" +
            "This demon captain is under strict orders not to let anyone by!\n" +
            "It has a tattoo of a white crown on its chest.\n", }),
                       5, 1, "black Demon Colonel", MTOWER + "colonel1",
           ({"set_name","black Demon Colonel",
            "set_long","An ugly demon.\n" +
            "This demon colonel will CRUSH anyone who tries to get by him!\n" +
            "It has a tattoo of a white crown on its chest.\n", }), });
       set_light (1);
    ::reset();
  replace_program("room/room");
}
