inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
object mag;
  ::reset(arg);
  if(!arg) {
    short_desc="Allport Magic Shop";
    long_desc="This is the Allport Magic Shop.\n" +
              "There are torches along the walls and a feeling of\n" +
              "great power is evident in the whole place.\n"+
              "  There is a sign magically suspended behind the\n" +
              "shop's counter.\n";

    dest_dir=({CONT + "west_road4","west",
               GUILDS + "mages_guild1","east",
    });
    items=({"room","It looks well kept",
            "sign","It reads:\n\n" +
                   "         Magnacious will tolerate NO FIGHTING here!\n\n" +
                   "This means you",
            "counter","An ancient looking piece of furniture",
            "torches","They give this place a mystic light",
            "walls","There are many magical looking paintings on them",
            "paintings","They are very artistic and realistic",
    });
    property = ({
                 "no_fight","has_fire",
       });
    smell="You can smell the smoke from the torches.";
    set_light(1);
    move_object(mag=clone_object(MNST + "cont/magnacious"),this_object());
return 1;
  }
}
