/*  This is the Moat around the Castle  */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

      	set_light(1);
	short_desc = "In a Moat";
	long_desc = 
"You decide to head west through the moat.\n"+
"Here, the water level seems to be dropping more, and the bank\n"+
"is getting distinctly smaller.  The water however is not any\n"+ 
"cleaner, and you would be glad to get out of here...\n";

	dest_dir = ({
          CROOMS + "moat","east",
          CROOMS + "moat31","west",
        });

	items = ({
  "water",
"Filthy water which swirls around your waist, getting in all of your "+
"clothes.  But what was that??  Did the surface of the water twitch there?",
  "bank",
"A very high edge which looks as though only a very experienced climber "+ 
"could climb it",
  "moat",
"Filthy water which swirls around your waist, getting in all of your "+
"clothes.  But what was that??  Did the surface of the water twitch there?",
     });

}

void init() 
{
  ::init();
  AA("swim",     "swim");
  AA("swim",     "dive");
  AA("drink",    "drink");
  AA("climb",    "climb");
  call_out("swirl", 17);
}

void swirl()
{
  TRM(TO, "You notice a the surface of the water ripple slightly.\n");
}

int swim(string str)
{
  if (!str || str == "water" || str == "in water")
  { 
     write("You go for a dive in the rather dirty water.\n");
       say(TPN+" dives underneath the surface of the water.\n");

     MPL("beneath the surface of the water#/players/tamina/castle/rooms/umoat3");

     return 1;
  }
}

int drink(string str)
{
  if (!str || str == "water")
  {
    write("Glug    Glug    Glug !!\n"+
	  "You take a drink from the dirty water.\n"+
	  "     -=  Yeuch !! =-\n");
      say("You hear a 'glugging' sound coming from "+TPN+".\n");

    return 1;
  }
}

int climb(string str)
{
  if (str == "bank" || str == "wall")
  {
    if (TP->DEX < 19 + random(5) && TP->query_level() > 7)
    {
      write("You do not manage to make it up the bank...\n"+
            "And fall back down to the water, with a resounding\n\n"+
            "          * * * S P L A S H * * *\n\n");
      return 1;
    }
    else
    {
      write("You succeed in climbing up the bank, and get out\n"+
            "from the moat.\n");
      MPL("up the bank#/players/tamina/teds/forest/rm7");

      return 1;
    }
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}
