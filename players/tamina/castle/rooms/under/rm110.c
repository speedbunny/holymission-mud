/*  This is an Underground Maze  */

#include "/players/tamina/defs.h"

inherit "room/room";
  int searched;

reset(arg) {
   searched = 0;
   if (arg) return ;

      	set_light(-1);
	short_desc = "Underground Passage (w)";
	long_desc = 
"This rooms is not as similar as all the others.\n"+
"Here, there is hay lying piled up in a corner.\n"+
"There is only one exit from this room.\n";

	dest_dir = ({
          UND + "rm100","west",
     });

	items = ({
  "hay","It looks fresh..",
    });

}
init() {
  ::init();
  add_action("search","search");
}

int search(string str) 
{
  object whistle;
  
  if (str == "hay")
  {
    if (searched)  
    {
      write("You search, and search, but find nothing.\n");
      say(TPN+" Doesn't find anything in "+TP->QPOS+" search.\n");

      return 1;
    }
    write("You search in amongst the hay, and find a whistle!\n");
    say(TPN+" produces a whistle from the hay!!\n");

    whistle = CLO("obj/thing");

  whistle->set_id("whistle");
  whistle->set_name("whistle");
  whistle->set_short("A Whistle");
  whistle->set_long("A small, silver whistle, with a strange spidery scrawl..\n");
  whistle->set_value(100);
  whistle->set_weight(2);
  whistle->set_read("A peculiar rune, which you cannot understand.. \n"+
                    "But you do recognise a single letter, 'M'.\n");
  whistle->set_can_get(1);

    TR (whistle, TP);

    searched = 1;

    return 1;
  }
  else
  {
    NFAIL("You cant see that to search here.\n"); 
    return 0;
  }
}

