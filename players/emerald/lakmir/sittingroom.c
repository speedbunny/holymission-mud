/* Uglymouth 970721: Recoded to use inheritble door room. 
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Lakmir's sittingroom";
  long_desc="This sittingroom is an extravagant, luxurious room, yet it " +
            "feels strangely oppressive. This room is dominated by a large " +
            "fireplace set in a red brick wall. Thick beams line the " +
            "ceiling, while a window breaks up the stone supporting wall. "
            "There is a door leading to the south.\n";

  smell="You smell the scent of a wood fire";

  dest_dir=({"/players/emerald/lakmir/bedroom","east",
             "/players/emerald/lakmir/anteroom","south",
          });

  items=({"window", "Through this portal you can see the dark forest"
          "fireplace","Dry wood rests within the fireplace",
          "wall","There is a window in the wall",
          "room","The sitting room of the Druid Lakmir",
          "beams","The beams are made of fine carved wood",
          "ceiling","Thick beams line the ceiling",
          "door", "dummy door description needed for doorroom",
        });

  ::reset();
  replace_program( DOOR_ROOM );

}
