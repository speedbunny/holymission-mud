#include "/players/gareth/define.h"
inherit "/obj/std_shop";

   reset(arg)
   {
   ::reset(arg);
   short_desc = "Dolza's pawn shop";
   long_desc =
   "You are in a small shop. It's gloomy in here. The walls are made\n"+
   "of black granite and the bottom covered with large silver scales.\n"+
   "This shop was established by 'Nusidian Dolza' he buys and sells all \n"+
   "kinds of stuff. There is a sign saying: 'type list' fixed to the wall,\n"+
   "behind a gold counter.\n";
 
    store = "/players/gareth/evil/town/store"; 
   items = ({
         "shop","You are just standing in the shop", 
         "bottom","It's covered with spruce wooden lathes", 
         "walls","They are made of black granite", 
         "granite","Just black, rough rock", 
         "dolza","Dolza, the drow is staying behind the counter glaring at you", 
         "sign","You see a small iron sign saying: type list",
         "scales","You see the scales of a large silver dragon",
           });
    dest_dir = ({ "/players/gareth/evil/town/tr4","west" });

    if (!present("torch",query_store()))
      transfer(CO("/obj/torch"),query_store());
    keeper = "dolza";
}
