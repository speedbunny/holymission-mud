inherit "obj/thing";
#include "../harbour.h"
#include "rent.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    set_name("small boat");
    set_alias("boat");

    set_short("little boat");
    set_long("Little boat.\n"+
	"It's a tiny ship with some oars and a small sail.\n"+
	"The bottom is a little bit dirty and there are many\n"+
	"little holes in it.\n");


    set_value(0);
    set_weight(100);
    CM("teller");
  }
}

int get() { return 0; }
int drop() { return 1; }

void init()
{ ::init();
  add_action("myrent","rent");
}
