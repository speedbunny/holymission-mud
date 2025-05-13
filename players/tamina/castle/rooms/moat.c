/*  This is the Moat around the Castle  */

inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

      	set_light(1);
	short_desc = "In a Moat";
	long_desc = 
"You are standing waist-deep in dirty water, which constitutes the\n"+
"Moat around the castle, Camelot.  The water feels terribly cold\n"+
"and you wish you were somewhere else.  But as for getting out of\n"+
"the Moat, you can only see that the bank here is far to steep to\n"+
"try and climb up.  The extent of the Moat does continue around the\n"+
"castle though.\n";

	dest_dir = ({
          CROOMS + "moat2","east",
          CROOMS + "moat3","west",
        });

	items = ({
  "water",
"Filthy water which swirls around your waist, getting in all of your "+
"clothes.  But what was that??  Did the surface of the water twitch there?",
  "bank",
"A very high edge which looks as though you could not climb it",
  "moat",
"Filthy water which swirls around your waist, getting in all of your "+
"clothes.  But what was that??  Did the surface of the water twitch there?",
     });

}

init() {
  ::init();
  AA("swim",  "swim");
  AA("swim",  "dive");
  AA("drink", "drink");
  call_out("swirl", 19);
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

     MPL("beneath the surface of the water#/players/tamina/castle/rooms/umoat");

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
