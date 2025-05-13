inherit "room/room";
#include "ansi.h"

reset(arg)
{
  ::reset(arg);
   set_light(1);
   short_desc="teststuff";
   long_desc="This is a test of "+BOLD+" - ansi.h - "+NORMAL+"\n";
   dest_dir=({"room/church",BLINK+"church"+NORMAL});
}
init()
{ ::init();
  add_action("correct","correct");
}

correct(str)
{
  tell_object(find_player(str),NORMAL+RESET+CLS);
  return 1;
}
