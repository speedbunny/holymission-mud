inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {

     short_desc = "Demon King's room";
     long_desc = "You are sorry you came in here!\n" +
                 "This is the room of the demon king.  This place is pure\n" +
                 "evil!  You almost faint just from the great presence of\n" +
                 "the Demon King.  His throne is made from the same black\n" +
                 "stone that the tower is made of.  The throne is covered\n" +
                 "with skulls of many unfortunate victims.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor4","south",
 
                     });

     items =({"tower","The tower seems to draw evil power from the Demon King",
              "throne","The sight of all those skulls repulses you",
              "skulls","They are of many different races",
              "stone","The stone throbs with evil power",
              "black stone","The stone throbs with evil power",
              });
      clone_list = ({ 1, 1, "black Demon King", MTOWER + "king",
            ({"set_name","black Demon King",
            "set_long","The ugly Demon King, Eriscull!\n" +
            "It sits upon its throne in smug arrogance.  It is\n" +
            "wearing a white crown on its head, and you sense\n" +
            "great power coming from the crown.  The king returns\n" +
            "your gaze and you are forced to look away.\n", }),
                      2, 1, "black Demon General", MTOWER + "general",
             ({"set_name","black Demon General",
              "set_long","An ugly demon.\n" +
              "This demon general will SMASH you!\n" +
              "It has a tattoo of a white crown on its chest.\n", }), });
       set_light (1);
      ::reset();
    replace_program("room/room");
}
