inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;

     short_desc = "Fields";
     long_desc = "You are in the south-western part of the fields where" +
                 " the city\ngrows all its crops.\n";

      dest_dir = ({ATTACH + "field3","north",
                   "room/crop5","south",
 
                     });
    items = ({
        "crop","It's corn, but not very ripe",
        "crops","It's corn, but not very ripe",
        "field","It's full of corn, waving it's stalks in the wind",
        "fields","Looks like they can grow much corn",
        "corn","It's not very ripe",
        "stalks","Nice looking, healthy stalks of corn",
    });

       set_light (1);
      smell="You smell earth and growing corn.";
return 1;
RR;
}
