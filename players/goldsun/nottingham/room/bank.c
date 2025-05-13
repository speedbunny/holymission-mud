inherit "/players/whisky/obj/std_bank";


void reset(int arg) 
{
   ::reset(arg);
   if(arg==0) 
   {
       set_light(1);
       short_desc="The Nottingham Bank";
       long_desc=
   "You are standing inside The Nottingham Bank. A small staircase leads up\n"+
   "to the BoardRoom. Simko the officer is sitting behind the desk, awaiting\n"+
 "your orders. Behind the counter there is a information 'sign' fixed to the\n"+
 "wall.\n";

    dest_dir=({"/players/goldsun/nottingham/room/road16","north",
	       "/players/goldsun/nottingham/room/boardroom","up"});

    property=({"no_fight"});

     items = 
     ({
     "bottom","The bottom is made of oak",
     "sign","There is something written on it",
     "counter","Behind the counter Simko counts the coins",
     "walls","They are made of spruce wooden lathes",
     "staircase","The staircase leads to the up",
     "simko","He is grinning at you, rubbing his hands",
    });

    clerk = "Simko";
    taxes = 2;
    save_file = "/players/goldsun/nottingham/room/bank";
    ::daily_taxes();
  }
}

