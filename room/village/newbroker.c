inherit "/room/inherit/std_bank";

#include "/room/room_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc="The Association Of The Money Brokers";
  long_desc=
    "You are standing inside the extensive building of The Money Brokers. "+
    "Some filthy old men are sitting behind the desk, counting "+
    "money and awaiting your orders. "+
    "To the north you notice the old bank hall. Behind the "+
    "counter there is an informational 'sign' affixed to the wall.\n";

  dest_dir= ({
    HM_VILLAGE + "bank","north",
    HM_VILLAGE + "road2","south",
  });

  items = ({
    "bottom","The bottom is made of oak",
    "sign","There is something written on it",
    "counter","Behind the counter Goldfinger counts the coins",
    "walls","They are made of spruce wooden lathes",
    "goldfinger","He is grinning at you, rubbing his hands",
  });

  clerk = "Goldfinger";
  taxes = 0;
  save_file = "/room/newbroker";
  load_info();

// If you wanted taxes in your bank then add the following line.
//  ::daily_taxes();
}

