
inherit "/obj/std_shop";

#include "/players/tatsuo/area/tatsuo_defs.h"
int x;
void reset(int flag)
{
    ::reset(flag);
    short_desc = "The Merchant's Tent";
    long_desc =
      "A small tent with objects cluttered around the room.\n" +
	"You can buy and sell items here.\n" +
	  "Commands are:\n" +
	"  'list', 'buy <num>', 'buy <item>', 'sell <item>', \n" +
	  "          'sell <all>', 'value <item>'.\n";
    store = "/players/tatsuo/area/forest1/shop_store.c";
    keeper = "A burly merchant";
    dest_dir = ({F1PATH+"road6.c", "south",
	     F1PATH+"forest9.c",  "north",
             F1PATH+"forest6.c", "east" });
    if (!present("torch",query_store()))
    {
        for(x=0;x<5;x++)
        {
            move_object(clone_object("/players/whisky/obj/torch"),
                        query_store());
        }
     }
/*
    if (!present("matchbox",query_store()))
    {
        for(x=0;x<3;x++)
        {
            move_object(clone_object("/players/whisky/obj/matchbox"),
                        query_store());
        }
     }
    if (!present("snare",query_store())) {
        for(x=0;x<3;x++)
        {
            move_object(clone_object("/players/tatsuo/guild/obj/snare"),
                        query_store());
        }
   }
*/

  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}



