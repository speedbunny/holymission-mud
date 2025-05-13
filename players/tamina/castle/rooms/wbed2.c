/*  This is the second Bedchamber in the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";
int found;

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Bed Chamber";
	long_desc = 
"Here, you can see another large four-poster bed standing against the\n"+
"far wall as you enter the room.  The room looks as though it were of a\n"+
"respectable living standard, a true testament to the castle cleaners\n"+
"when they were here.  On the walls however, are obvious lighter patches\n"+
"where paintings, or portraits once hung, and the sunlight has faded the\n"+
"walls.  About the base of the bed are littered several signs of previous\n"+ 
"habitation, like ripped clothes, and worthless jewelry.\n";

	dest_dir = ({
          CROOMS + "wwing5","east",
        });

	items = ({
  "bed",
"It is a large four-poster bed, but looks in very bad condition, as if "+
"no one has bothered to look after it for quite some time",
  "clothes",
"Old, worn garments that appear to have belonged to a noble lady some "+
"time in the past",
  "jewelry",
"Very old pieces of useless junk that no one would be interested in",
     });

}

init() 
{
  ::init();
  AA("_search",  "search");
}

int _search(string str)
{
  object neck;

  if (str == "jewelry")
  {
    if (found)
    {
      write("You search, but find nothing interesting.\n");
        say(TPN+" searches through the jewelry.\n");

      return 1;
    }
    write("You search through the odd pieces of jewelry, and find a \n"+
	  "sparkling silver necklace.\n");
      say(TPN+" finds a necklace amongst the jewelry.\n");

    neck = CLO (COBJ + "quest/neck");
    TR (neck, TP);

    found = 1;
    return 1;
  }
  else
  {
    NFAIL("You search, but find nothing interesting.\n");
    return 0;
  }
}
