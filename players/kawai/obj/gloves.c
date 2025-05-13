inherit "obj/armour";
#include <lw.h>

int id(string str)
  {return str=="kq1-glo"||str=="climbing gloves"||str=="gloves"||
  str=="armor"||str=="armour";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_name("climbing gloves");
    set_short("climbing gloves");
    set_long(lw("These gloves seem to have been made especially for the purpose of "+
    "climbing various surfaces.  The palms of the glove have several small "+
    "spikes to keep the climber from slipping.\n"));
    set_value(25);
    set_weight(1);
    set_alias("kq1-glo");
    set_type("glove");
    set_size(0);
    set_ac(1);}}
