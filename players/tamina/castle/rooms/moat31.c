/*  This is the Moat around the Castle  */

inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

      	set_light(1);
	short_desc = "In a Moat";
	long_desc = 
"You have come to what appears to be as far as any sensible\n"+
"person would go through the moat...if they ever got into the moat\n"+
"in the first place !!  There is no bank to climb.\n";

	dest_dir = ({
    CROOMS + "moat3", "east",
    "", "west",
    });

	items = ({
  "water",
"Filthy water which swirls around your waist, getting in all of your "+
"clothes.  But what was that??  Did the surface of the water twitch there?",
  "bank",
"A high edge which looks as though anyone could climb it",
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
  AA("no_west",  "west");
}

int swim(string str)
{
  if (!str || str == "water" || str == "in water")
  { 
     write("You go for a dive in the rather dirty water.\n");
       say(TPN+" dives underneath the surface of the water.\n");

     MPL("beneath the surface of the water#/players/tamina/castle/rooms/umoat31");

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

int no_west()
{
  write("You see that the ripples are too strong for you to dare going\n"+
        "in that direction...\n");
  return 1;
}
