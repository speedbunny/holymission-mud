

/* shop */

inherit "/obj/std_shop";
#include "/players/whisky/genesis/sys/break_string.h"

#define  BS(x) break_string(x+"\n",60)

void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In a diry little shop";
  long_desc = BS(
  "Welcome to our shop. Look around and buy what you like. The shopkeeper thinks "+
  "that you are intelligent, so he will not explain the buy and sell commands.");
   set_light(1);
   store = "/players/tegerl/jabberwocky/rooms/town/store";
   keeper = "The keeper";



  dest_dir = ({ "/players/tegerl/jabberwocky/rooms/town/street3","east" });

    move_object(clone_object("/obj/torch"),query_store());
    move_object(clone_object("/players/cashimor/objects/match"),query_store());

}

query_property(arg) 
{
   return arg=="no_fight";
}
