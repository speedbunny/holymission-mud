inherit "/obj/std_scroll";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
add_name("invisibility");
set_alias("scroll");
set_short("An invisibility scroll");
set_long(
"This scroll is rolled tightly but seems to quiver with power.  Strange "+
"symbols and letters cover both sides of the scroll.  It is sealed with "+
"a lump of wax.  The seal of Bismarck is pressed into the center of the "+
"wax.\n");
set_value(1000);
set_weight(1);
}

void init(){
  ::init();
  add_action("do_read","read");
  }

do_read(string arg)
{
 if (arg == "scroll") { do_invis(); return 1; }
 if (!arg) { return write("Read What?\n"),1; }
}

do_invis()
{

 if (this_player()->query_invis()) { return write("You are already invisible.\n"
),1; }
      set_shadow("/obj/shadows/invis_shad",180);
 destruct(this_object());
 return 1;
}
