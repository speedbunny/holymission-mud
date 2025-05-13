inherit "obj/armour";
#include <lw.h>

int id(string str)
  {return str=="kq1-ring"||str=="ring"||str=="fancy ring";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_name("A fancy ring");
    set_short("A Fancy ring");
    set_long(lw("This is a large, elaborately inlaid ring of kingly quality.  Set "+
    "all around the gold band are numerous rubys and emeralds.\n"));
    set_value(5000);
    set_weight(1);
    set_alias("ring");
    set_type("ring");
    set_size(0);
    set_ac(1);}}

int query_quest_obj()
  {return 1;}

