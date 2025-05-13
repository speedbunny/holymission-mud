inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Gateway";
  long_desc = 
      "This is the gateway to other rooms.  That is all !!!\n";
  property=({
      "no_teleport",
  });
  dest_dir=({
      "/players/matt/newworld/city/rooms/votebooth", "booth",
      "/room/church", "church",
      "/players/saffrin/misc/room/croom", "coding",
      HAM+"room/enter", "hamlet",
      TOWER+"room/outer", "mguild",
      PK+"room/d", "pk",
      "/room/post", "post",
      "/players/saffrin/workroom", "saffrin",
      TINK+"room/joy1", "tinkers",
  });
  ::reset();
  replace_program("room/room");
}
