// The file to inherit to make a standard room.
inherit "room/room";
 
// Reset is called every once in awhile by the parser and it resets
// any objects/variables in the room code befure the ::reset section
void reset(int arg) {
// The room is lit.
  set_light(1);
 
// The short description of the room.
  short_desc = "A moor";
 
// The long description of the room. Note that only one \n is
// needed at the end of the full description. The room desc is
// automatically formatted to 78 characters. Also descriptions
// should be clear and somewhat interesting.
  long_desc =
    "You are standing at the northern edge of a large stretch of "+
    "moorland. A huge mountain towers above you, and an icy wind "+
    "blows down from the cliff-tops.\n";
 
// Possible visible exits. Destination room followed by direction.
  dest_dir = ({
    "/doc/examples/exa03", "north",
    "/doc/examples/exa09", "east",
    "/doc/examples/exa02", "south",
  });
 
// For every noun mentioned in the room description there should
// be an item description in the items var. The first string is
// the item that the player must look at and the second is the
// message given to him/her. Note that there are no \n in the
// message and no punctuation at the end. The line will be
// formatted when it is printed, and a period is appended to
// the line always.
  items = ({
    "moorland", "A very bleak moorland; there seems nothing but "+
      "sheep on it",
    "mountain", "A vast mountain to the north dwarfs everything else "+
      "you can see",
    "cliff-tops", "They are on the mountain",
  });
 
// When you have a basic room such as this and there are no add_actions,
// or the init is not overwritten, then you should end with ::reset()
// and replace_program. It helps to save memory.
  ::reset(arg);
  replace_program("room/room");
}
