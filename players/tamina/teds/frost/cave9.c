inherit "room/room";

#include "/players/tamina/defs.h"

int cave_in, test;

void reset(int arg) 
{
  cave_in = 0;
  test = 1;
  ::reset(arg);
  if (!arg) 
  {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. The floor and walls have been cut and\n"+
"shaped by tools. It is quite different than the natural cave\n"+
"you had been traveling through.\n";

    dest_dir = ({
      TFROST + "cave10", "north",
      TFROST + "cave8", "southeast"
    });
  }
}

int id(string str) 
{
  if(::id(str)) return 1;
  return (str == "rocks" || str == "pile" || str == "cave in");
}

void long(string str) 
{
  ::long(str);
  if((str == "rocks" || str == "pile" || str == "cave in") && cave_in) {
   write("This is part of the cave ceiling that has colapsed onto the floor\n");
   write("It looks quite new.......\n");
  }
 if(cave_in && !str)
   write("There is a pile of rocks blocking the north passage.\n");
}

void init() 
{
  ::init();
  add_action("do_move", "north");
}

int do_move() 
{
  if (cave_in) 
  {
    write("The cave in blocks you from going north.\n");
    say(TPN+" is blocked from going north by the cave in.\n");
    return 1;
  }
  write("As you go north, you step on a counter balanced flagstone.\n");
  write("Suddenly part of the cave ceiling colapses. However, you\n");
  write("are quick enough to jump back to safety.\n");
  say("As "+TPN+" leaves north, "+TP->QPRO+" trips a hidden spring\n"+
      "and causes a cave in !!!\n");
  cave_in = 1;
  return 1;
}
