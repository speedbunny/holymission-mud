inherit "room/room";
 
void reset(int arg) {
// Clone list is used when you wish to create simple monsters in the
// room. It aids in saving memory, and is called every reset, therefore
// it needs to be before a ::reset(). Some things to note about simple
// monster generation. set_name is necessary for any monster. also, in
// set_alias_list, you do not need to repeat the name or race you set,
// because they are automatically included. set_name should be called
// before any other description sets and set_level should be called
// before any other attribute alterations, such as set_wc, set_ac, etc.
// The first number is the id of the monster, for the purpose of using
// clone_list, the second number is the number of monsters of this
// type you want cloned. The 3rd item, which is a string, is the id
// of the object that will be checked for at reset to determine whether
// it needs to be replaced or not. The 4th item is the file you are
// cloning the monster from. And the fifth item contains all the
// information you wish to set on the monster.
// Man clone_list for more information.
  clone_list = ({
    1, 1, "farmers wife", "obj/monster", ({
      "set_name", "farmer's wife",
      "set_alias_list", ({"wife","farmers wife"}),
      "set_gender", 2,
      "set_level", 6,
      "set_short", "The farmer's wife",
      "set_long", "The farmer's wife is about 50, and rather overweight.\n",
    }),
  });
 
  set_light(1);
  short_desc = "The farmhouse kitchen";
 
  long_desc =
    "You are inside the kitchen. There is a stove here, and a sink. "+
    "The walls used to be whitewashed, but they now seem to be all "+
    "covered in soot.\n";
 
  dest_dir = ({
    "/doc/examples/exa01", "north",
  });
 
  items = ({
    "kitchen", "You are standing in it",
    "stove", "The stove seems to be lit, but it is none too warm",
    "sink", "A sink, full of potato peelings",
    "walls", "The walls seem very dirty indeed",
    "soot", "It probably came from the stove",
  });
 
  ::reset(arg);
  replace_program("room/room");
}
