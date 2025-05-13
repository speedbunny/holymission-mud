inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Blob's Room";
    long_desc="It smells terrible in here!\n" +
              "There is filth and grime all over the place.\n";

    dest_dir=({PATH + "workroom","south",
               PATH + "workroom","north",
    });
    items=({"room","What a mess",
    });
    set_light(1);
    smell="It really stinks in here!";
    move_object(clone_object(MNST + "blob1"),this_object());
return 1;
  }
}
