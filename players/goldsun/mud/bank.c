
/* new_broker */

inherit "/players/whisky/obj/std_bank";


void reset(int arg) 
{
   ::reset(arg);
   if(arg==0) 
   {
       set_light(1);
       short_desc="The Association Of The Money Brokers";
       long_desc=
    "You are standing inside the extensive building of The Money Brokers.\n"+
    "Some filthy old men are sitting behind the desk, awaiting your orders.\n"+
    "To the south you notice the entry to the old bank hall. Behind the\n"+
    "counter there is a information 'sign' fixed to the wall.\n";

     dest_dir=
     ({
         "room/narr_alley","east",
         "room/bank","south",
     });
     items = 
     ({
     "bottom","The bottom is made of oak",
     "sign","There is something written on it",
     "counter","Behind the counter Goldfinger counts the coins",
     "walls","They are made of spruce wooden lathes",
     "goldfinger","He is grinning at you, rubbing his hands",
    });
    clerk = "Goldfinger";
    taxes = 4;
    save_file = "/room/newbroker";
    ::daily_taxes();
  }
}

