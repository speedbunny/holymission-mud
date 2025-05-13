inherit "/obj/std_shop";
#include "/players/whisky/genesis/sys/break_string.h"

#define  BS(x) break_string(x+"\n",60)

void reset(int arg)
{
  ::reset(arg);
  short_desc="The town shop";
  long_desc = BS(
  "You have entered the town shop. A smiling merchant is " +
  "standing behind the counter, ready to help you.  Type 'list' for " +
  "more information.");
   set_light(1);
   store = "/players/emerald/town/store";
   keeper = "Griswald";

  dest_dir = ({ "/players/emerald/town/t20", "east", });

  items=({"counter","The service area of the shop",
  });

    move_object(clone_object("/obj/torch"),query_store());
    move_object(clone_object("/players/cashimor/objects/match"),query_store());

}

query_property(arg)
{
   return arg=="no_fight";
}
