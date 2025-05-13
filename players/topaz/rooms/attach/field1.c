inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;

     short_desc = "Fields";
     long_desc = "You are in the north-western part of the fields where" +
                 " the city\ngrows all its crops.\n";

      dest_dir = ({ATTACH + "field2","west",
                   ATTACH + "field3","south",
                          "room/crop2","east",
 
                     });
        items =({
        "crops","It's corn, but it's not very ripe at all",
        "crop","It's corn, but it's not very ripe at all",
        "field","It is full of stalks of corn which are waving in" +
                "the breeze",
        "fields","They look like they could yield much corn",
        "corn","It isn't very ripe at all",
        "stalks","Healthy looking corn stalks",
        });

       set_light (1);
    smell="You inhale and smell the corn.";
    return 1;
  RR;
}
