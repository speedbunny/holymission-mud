inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "Throne Room";
    long_desc =
"This is a large circular room with a high domed ceiling.\n"+
"A large ornate throne sits on a raised dais at the north\n"+
"end of the room. You can't tell if anyone is sitting in it,\n"+
"maybe you should take a closer look?\n";

    dest_dir = ({
      TFIRE + "hell_hall", "south"
    });

    items = ({
"throne","The throne appears to be made of solid gold. You still can't\n"+
         "tell if it is occupied. May be you should climb up the stairs\n"+
         "leading up the dais to the throne",
"dais","As you look closer, you see that it is possible to climb up\n"+
       "the stairs leading to the throne"
    });
  }
}

void init() 
{
  ::init();
  add_action("do_climb", "climb");
}

int do_climb(string str) 
{
  if (str == "up" || str == "dais" || str == "up dais" || "stairs")
  {
    write("You manage to scramble up the dais.\n");
    MPL("up the dais !!#players/tamina/teds/fire/king"); 
    return 1;
  }
  else
  {
    NFAIL("Climb what?\n");
    return 0;
  }
}
