inherit "room/room";
string oldsearch;
int found;

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {

    oldsearch="NOONE";
     short_desc = "Fields";
     long_desc = "You are in the western part of the fields where" +
                 " the city\ngrows all its crops.\n";

      dest_dir = ({ATTACH + "field1","north",
                   ATTACH + "field4","south",
 
                     });
    items = ({
        "crop","The corn looks pretty ripe here",
        "crops","The corn looks pretty ripe here",
        "field","The corn looks pretty ripe here",
        "fields","The corn looks pretty ripe here",
        "corn","It looks pretty ripe here",
    });

       set_light (1);
       smell="The crops smell pretty ripe here.";
return 1;
  }
}

init() {
  ::init();

    add_action("_search","search");
}

_search(str) {
  if(str=="corn" || str=="crops" || str=="crop" || str=="fields" || str=="field") {
   if(found) {
     write("There are no more ripe crops to be harvested.\n");
     return 1;
   }
   else {
    if(TP->query_real_name()==oldsearch || oldsearch=="NOONE") {
      write("The crops don't seem to be ripe yet.\n");
      oldsearch=TP->query_real_name();
      return 1;
    }
    else {
      object corn;
      write("You search and find some ripe corn.\n");
      say(TP->query_name() + " searches the field and finds some corn.\n");
      transfer(corn=clone_object("players/topaz/obj/attach/corn"),this_player());
      found=1;
      return 1;
    }
   }
  }
  else {
    write("Search what?\n");
    return 1;
  }
}
