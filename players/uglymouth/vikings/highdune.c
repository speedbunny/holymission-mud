/* highest point around here, so you can see some hints */
inherit "room/room";

void reset(int arg)   {
   if(arg) return;

   set_light(1);
   short_desc="The highest dune in the area";
   long_desc="You climb to the top of the highest dune in the area. \n"
           + "To the south-east you have a magnificent view over the bay. Look at it! \n"
           + "You feel the warm seawind blow gently around you.  This is a nice place to be. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_m","north",
              "/players/uglymouth/vikings/bay_ne","east",
              "/players/uglymouth/vikings/bay_nw","southwest", });
   items=({
           "dune","This is the highest point in the area. It has a great view",
           "view","You can see miles around from here: \n"
                + "To the north and west you see more dunes. \n"
                + "To the east look away over the sea, and see it melt with the air \n"
                + "at the horizon. Both air and water almost shine in a heavenly blue. \n"
                + "South-west you see the border of the jungle surrounding the bay. \n"
                + "South-east you look out over the bay. At the other end lies a small village. \n"
                + "At the entrance to the bay lies a ship at anchor",
           "village","A small coastal village. A dark cloud of smoke hangs above it",
           "ship","A large ship of unknown design. You vaguely remember some rumours about Vikings",
           "smoke","In your experience you can see that it must be caused by a REAL BIG FIRE",
           "cloud","It's bigger and darker than chimneys alone can cause. And it's not the weather",
           });

   }

void vikings_leave() {
   items=({
           "dune","This is the highest point in the area. It has a great view",
           "view","You can see miles around from here: \n"
                + "To the north and west you see more dunes. \n"
                + "To the east look away over the sea, and see it melt with the air \n"
                + "at the horizon. Both air and water almost shine in a heavenly blue. \n"
                + "South-west you see the border of the jungle surrounding the bay. \n"
                + "Southeast you look out over the bay. At the other end lies a small village. \n",
           "village","A small coastal village. A dark cloud of smoke hangs above it",
           "smoke","In your experience you can see that it must have been caused by a REAL BIG FIRE",
           "cloud","It's bigger and darker than chimneys alone can cause. And it's not the weather",
      });
   return;
   }

void vikings_arrive() {
   items=({
           "dune","This is the highest point in the area. It has a great view",
           "view","You can see miles around from here: \n"
                + "To the north and west you see more dunes. \n"
                + "To the east look away over the sea, and see it melt with the air \n"
                + "at the horizon. Both air and water almost shine in a heavenly blue. \n"
                + "South-west you see the border of the jungle surrounding the bay. \n"
                + "South-east you look out over the bay. At the other end lies a small village. \n"
                + "At the entrance to the bay lies a ship at anchor",
           "village","A small coastal village. A dark cloud of smoke hangs above it",
           "ship","A large ship of unknown design. You vaguely remember some rumours about Vikings",
           "smoke","In your experience you can see that it must be caused by a REAL BIG FIRE",
           "cloud","It's bigger and darker than chimneys alone can cause. And it's not the weather",
      });
   return;
   }
