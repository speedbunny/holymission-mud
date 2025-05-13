inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  object ob;
  if (!arg) {
    set_light(1);
    short_desc = "bedroom";
    long_desc = "This must be the master bedroom.  Interesting decor.\n"
      +"There is a stale smell about this room, as if it hadn't been opened for years. "
      +"It is dominated by a large luxurious bed -- definitely king-sized.\n";
    smell="It smells, as if the room hadn't been opened for years";
    dest_dir = ({
        COTTAGE+"sittingroom", "west"
      });
    items = ({
        "decor","Well, Really very beautiful"
      });
  }
  ob = CASTLE->add_monster("lakmir",this_object());
  if (environment(ob)!= this_object()) move_object(ob,this_object());
  CASTLE->add_interior ("interior",this_object(),"mirror");
  CASTLE->add_interior ("interior",this_object(),"nightstand");
  CASTLE->add_interior ("interior",this_object(),"bed");
}
