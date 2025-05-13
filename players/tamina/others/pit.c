inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

  set_light(1);
  property = "no_teleport";
  short_desc = "A Bottomless Pit";
  long_desc =
    "You are falling in a deep, dark pit, which seems to have\n"+
    "no bottom.  You have been put here, because you have been\n"+
    "very naughty.  You might get out later...\n";
  no_obvious_msg = "    There are no exits.\n";
}

void init() 
{
  ::init();
  AA("no_way", "quit");
  AA("no_way", "shout");
  AA("no_way", "tell");
  AA("no_way", "mt");
  AA("no_way", "monk");
  AA("no_way", "monk/");
  AA("no_way", "fighter");
  AA("no_way", "fighter/");
  AA("no_way", "fshout");
  AA("no_way", "jedi");
  AA("no_way", "jedi/");
  AA("no_way", "mage");
  AA("no_way", "ninja");
  AA("no_way", "ninja/");
  AA("no_way", "rwhere");
  AA("no_way", "who");
}

int no_way() 
{
  write("You're not going to get away that easy !!\n"+
        "You are here to be punished.\n");
  return 1;
}

int free(string arg) 
{
  object target;
  target = find_player(arg);

  if (present(arg, this_object())) 
  {
    write("You free "+target->NAME".\n");
    TOBJ(target, "\nYou have been freed.\n\n");
    move_object(target, "/room/church");
    say(target->NAME+" is freed.\n");
    return 1;
  }
}
