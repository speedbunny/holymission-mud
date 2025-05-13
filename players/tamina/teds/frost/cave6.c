inherit "room/room";

#include "/players/tamina/defs.h"

int trap, found;

void reset(int arg) 
{
  trap = 1;
  found = 0;
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. It is also getting more humid.\n";

    dest_dir = ({
      TFROST + "cave7", "north",
      TFROST + "cave5", "east"
    });
  }
}

void init() 
{
  ::init();
  add_action("north", "north");
  add_action("search", "search");
  add_action("disarm", "disarm");
  add_action("my_look", "look");
  add_action("my_look", "exa");
}

int my_look(string str) 
{
  if ((str == "trap" || str == "at trap") && found && trap) 
  {
    write("It looks like some kind of dart trap.\n");
    write("Maybe you could disarm it?\n");
    return 1;
  }
  if ((str == "trap" || str == "at trap") && !trap)
    write("A disarmed trap.\n");
  if (!str && found && trap) 
  {
    long();
    write("There is a trap here.\n");
  }
  if (!str && !trap)
  {
    long();
    write("There is a disarmed trap here.\n");
  }
  if(!str && !found) return 0;
  return 1;
}

int north() 
{
  if(random(10) <= 7 && trap) 
  {
    write("As you travel through the northern passage you step on ");
    write("something!!\nSuddenly you are hit by a small dart!\n");
    HIT(random(20));
 }
}

int search(string str) 
{
  if (str == "cave")
  {
    if (random(6) >= 3 && !found) 
    {
      write("You find a trap!\n");
      say(TPN+" finds a trap!\n");
      found = 1;
      return 1;
    }
    if (!trap) 
    {
      write("You find a disarmed trap.\n");
      return 1;
    }
    if (found) 
    {
      write("Besides the trap, there is nothing of interest.\n");
      return 1;
    }
    write("You don't find anything of interest.\n");
    say(TPN+" searches around.\n");
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}

int disarm(string str) 
{
  if (str == "trap")
  {
    if (trap && found) 
    {
      if (TP->DEX >= 3 + random(20)) 
      {
        write("You disarm the trap!\n");
        say(TPN+" disarms a trap.\n");
        trap = 0;
        return 1;
      }
      write("You fail to disarm the trap and accidently set it off!!!\n");
      HIT(5 + random(20));
      write("You are hit by a small dart!\n");
      say(TPN+" is hit by a small dart!\n");
      return 1;
    }
    if (!trap && found) 
    {
      write("The trap has already been disarmed.\n");
      return 1;
    }
  }
  else
  {
    NFAIL("Disarm what?\n");
    return 0;
  }
}
