inherit "room/room";

#include "/players/tamina/defs.h"

int found;

void reset(int arg) 
{
  found = 0;
  ::reset(arg);
  if (!arg) 
  {
    set_light(1);
    short_desc = "Base of Mountain";
    long_desc =
"You are standing at the base of a huge snow covered mountain.\n"+
"It's sides are to steep and slippery to climb. You notice\n"+
"something unusual about the mountain side\n";

    dest_dir = ({
      TCOLD + "frost_giant", "south"
    });

    items = ({
  "mountain side",
"You sense something is not quite as it seems here",
  "side",
"You sense something is not quite as it seems here",
  "mountain",
"You sense something is not quite as it seems here",
    });
  }
}

void init() 
{
  ::init();
  add_action("do_enter", "enter");
  add_action("do_enter", "north");
  add_action("search", "search");
  add_action("my_look", "look");
  add_action("my_look", "exa");
}

int id(string str) 
{
  if(::id(str)) return 1;
  return str == "cave";
}

int search(string str) 
{
  if (str == "mountain" || str == "mountain side" || str == "side")
  {
    if (found) 
    {
      write("You don't find anything new.\n");
      say(TPN+" searches around.\n");
      return 1;
    }
    write("You find a cave entrance hidden in the snow!\n");
    say(TPN+" finds a cave entrace.\n");

    found = 1;
    return 1;
  }
  else
  {
    NFAIL("You don't find anything of intererest.\n");
    return 0;
  }
}

int my_look(string str) 
{
  if (found && (str == "cave" || str == "at cave" || str == "side")) 
  {
    write("This dark opening seems to lead deeper into the montain.\n");
    write("It looks like you could enter the cave if you wished.\n");
  }
  if (found && !str) 
  {
    write("There is a cave half hiden in the snow covered mountain side\n");
  }
}

int do_enter(string str) 
{
  if (str == "cave")
  {
    if (found) 
    {
      write("You shove ice and snow out of your way and enter the cave.\n");
      MPL("into a cave#players/tamina/teds/frost/cave1");
      return 1;
    }
    write("Enter what?\n");
    return 1;
  }
  else
  {
    NFAIL("Enter what?\n");
    return 0;
  }
}
