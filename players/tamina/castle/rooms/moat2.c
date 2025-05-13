/*  This is in the Moat of Camelot  */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return ;

      	set_light(1);
	short_desc = "In the Moat";
	long_desc = 
"On going east, you see that the water here is getting decidedly\n"+
"deeper.  You start to wonder if it is going to be safe continuing\n"+
"on this path.  Apart from this, you can see that the water is also\n"+
"getting more cloudy, so that you cannot see very far through the \n"+
"water.\n";

	dest_dir = ({
          CROOMS + "moat21","east",
          CROOMS + "moat","west",
        });

	items = ({
  "water",
"It is now beginning to get muddy, so that you cannot see very much"+
" through the murk.  Beneath you, the water is getting quite deep "+
"and your feeting are starting to lose any purchase they might have had",
     });

}

int check()
{
  if (TP->query_size() == 2)
  {
    write("You _really_ do not think you can proceed any further, \n"+
	  "because of your diminutive stature...\n");
      say(TPN+" looks like he is going to drown, because of his small size.\n");
    return 1;
  }
}

void init() 
{
  ::init();
  AA("swim",  "swim");
  AA("swim",  "dive");
  AA("drink", "drink");
  call_out("swirl", 19);
}

void swirl()
{
  TRM(TO, 
    "The ripples on the surface of the water start to get more pronounced.\n");
}

int swim(string str)
{
  if (!str || str == "water" || str == "in water")
  { 
     write("You go for a dive in the rather dirty water.\n");
       say(TPN+" dives underneath the surface of the water.\n");

     MPL("beneath the surface of the water#/players/tamina/castle/rooms/umoat2");

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
