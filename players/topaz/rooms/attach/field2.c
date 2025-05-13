inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;

     short_desc = "Fields";
     long_desc = "You are in the western edge of the fields where the city" +
                 " grows\nall its crops.  There is a muddy path leading west.\n";

     dest_dir = ({ATTACH + "field1","east",
                  ATTACH + "path1","west",
 
                     });
     items = ({"path","It looks well used",
               "muddy path","It looks well used",
        "crop","It is corn, but not very ripe",
        "crops","It is corn, but not very ripe",
        "field","A field full of growing corn",
        "fields","They look like they can grow much corn",
        "corn","It is not very ripe",
     });

       set_light (1);
    smell="You smell ripening corn.";
return 1;
RR;
}
