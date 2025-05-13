/*  This is the West Walled Garden  */

#include "/players/tamina/defs.h"

inherit "room/room";
object bush, frog;

void reset(int arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "West Walled Garden";
	long_desc = 
"On entering the small, sheltered wall-garden to the west of the Quadrangle,\n"+
"the first thing you notice is the pond full of stagnant, dirty water.\n"+
"Mounds of muck and algae float around the water, desperately trying to \n"+
"drown the few lillies that remain.  Beside the small pond is a stone seat,\n"+ 
"naturally placed so as to catch as much sunlight as possible.  Strands of\n"+ 
"delphinium and climbing ivy grasp the wall, like the spindly legs of a \n"+
"spider.  Behind the  pond are clumps of overgrown bramble bushes, with \n"+
"trails of bindweed, and ground elder strangling the last remnants of any\n"+
"beautiful flowers that once flourished here.\n";

	dest_dir = ({
          CROOMS + "w_cloister","east",
        });

	items = ({
  "pond",
"This is now well-past any state in which one should venture drinking.  The water "+
"looks thoroughly ugly, and unsavoury, being full of algae and moss.  Those lillies "+ 
"remaining on the pond look as though they have lost the battle to stay afloat",
  "seat",
"This is made from solid marble, but looks very dirty...not as if someone has "+
"recently sat here",
  "delphinium",
"This is a long climbing plant that scales the far wall, entwining in a strange "+
"dance with the ivy",
  "ivy",
"A scaling plant that climbs the stone wall, almost defying gravity",
  "bush",
"A thorny bush, related to the blackberry bush, which may still contain a few "+ 
"brambles",
  "bramble bush",
"A thorny bush, related to the blackberry bush, which may still contain a few "+ 
"brambles",
     });

  bush = CLO(COBJ + "bush");
  MO (bush, TO); 

  frog = CLO("obj/monster");

  frog->set_name("frog");
  frog->set_short("A frog");
  frog->set_frog(1);
  frog->set_long("A cute, little green frog, which belches now and then.\n");
  frog->set_level(2);

  MO (frog, TO);
}

init() {
  ::init();
  add_action("sit","sit");
  add_action("drink","drink");
}

int sit (string str) 
{ 
  if (str == "on seat" || str == "seat")
  { 
    write("You sit down on the cold marble seat, and let\n"+
          "the sunshine wash over you.\n");
      say(TPN+" sits down on the marble seat, and shivers!\n");

    return 1;
  }
  else
  {
    NFAIL("Where will you sit?\n");
    return 0;
  }
}

int drink (string str) 
{
  if (str == "water")
  {
    write("You drink the water from the pond...\n");
      say(TPN+" rather stupidly drinks the water from the stagnant pond!\n");

    HIT(15);
  
    return 1;
  }
  else
  {
    NFAIL("What will you drink?\n");
    return 0;
  }
}
