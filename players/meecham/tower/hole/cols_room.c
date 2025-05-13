inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  CLONE("coldrik","coldrik");
  if(!arg)
  {
    set_light(0);
    short_desc="Closest thing to hell";
    long_desc=
      "\This room is covered with dust.  The room is dominated by a giant man\n\
relaxing on a throne in the center.  His eyes glitter almost as much as his\n\
armor.  The room is bare, but for the dust and the throne.  The walls are\n\
rounded and smooth, directing all attention towards the throne in the\n\
middle of the room.\n";
    items=({
      "throne","The throne looks dull as it is offset by Coldrik's armor",
    });
    dest_dir=({
      PM+"tower/hole/path_to_col","up",
    });
  }
}

init() {
  ::init();
  add_action("_xx","xx");
}

_xx() {
  object mon;
  mon = CO(MON + "coldrik");
  mon->set_hp(1);
  destruct(present("shield",mon));
  destruct(present("armour",mon));
  MO(mon,TO);
  return 1;
}
