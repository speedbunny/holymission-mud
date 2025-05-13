inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "A Small Room";
    long_desc =
"This small room is starkly furnished with a bed and\n"+
"a small desk. A note is tacked to the wall over the\n"+
"desk. A large window look east. You think you see something\n"+
"out of it.....\n";

    dest_dir = ({
      TFIRE + "tower2", "west"
    });

    items = ({
"window","As you look out the window, you see a small courtyard\n"+
         "surrounded by high walls. As you look a Fire Giant walks\n"+
         "from a small door in the east wall to the double doors and enters",
"desk","This is a small wooden desk. It has nothing on it, only a pen\n"+
       "and a stack of paper, none of which interests you",
"note","It seems to be writen in your language. Maybe you should read it?"
    });
  }
}

void init() 
{
  ::init();
  add_action("do_read", "read");
}

int do_read(string str) 
{
  if (str == "note")
  {
    write("To Captain Vacard:\n"+
          "Please remember to interogate our frost giant prisoner soon.\n"+
          "He may have important information about the giant conference\n"+
          "on human bashing. He WAS the frost giant kings messenger......\n"+
          "I have heard rumours that the frost giants have found a very\n"+
          "valuable treasure. He may know something about it......\n"+
          "                      King Thelborn\n");
    say(TPN+" reads a note.\n");
    return 1;
  }
  else
  {
    NFAIL("Read what?\n");
    return 0;
  }
}
