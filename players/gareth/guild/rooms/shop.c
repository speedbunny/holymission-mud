#include "/players/gareth/define.h"
inherit "/obj/std_shop";

   reset(arg)
   {
   ::reset(arg);
   short_desc = "Alexander T. Great's pawn shop";
   long_desc =
   "You are in a small shop. It's gloomy in here. The walls are made\n"+
   "of gray granite and the bottom covered with large silver shields.\n"+
   "This shop was started up by 'Alexander T. Great' he buys and sells all \n"+
   "kinds of stuff. There is a sign saying: 'type list' fixed to the wall,\n"+
   "behind a silver counter.\n";
 
    store = "/players/gareth/guild/rooms/store";
    items = ({
         "shop","You are just standing in the shop", 
         "bottom","It's covered with spruce wooden lathes", 
         "walls","They are made of grey granite", 
         "granite","Just grey, smooth rock", 
         "alexander","Alex, the warrior is staying behind the counter", 
         "sign","You see a small silver sign saying: type list",
         "scales","You see the scales of a large silver dragon",
           });
    dest_dir = ({ "/players/gareth/guild/rooms/hall","south" });

    if (!present("torch",query_store()))
      TR(CO("/obj/torch"),query_store());
    keeper = "alexander";
}
