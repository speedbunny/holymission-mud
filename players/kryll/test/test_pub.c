inherit "/players/kryll/test/std_pub";

void reset(int arg) {
  set_light(1);
  short_desc = "The local pub";
  long_desc =
    "You are in the local pub. It looks quite deserted at "+
    "the moment, but there is a sign on the wall.\n";
 
  items = ({
    "sign", "Perhaps you should read it",
    "wall", "It is just a wall",
  });
 
  set_waiter("Mack");
  set_header("Mack's Place");
 
// Prevents teleporting in or out of the room.
  property = ({ "no_teleport" });
 
  dest_dir = ({
    "/doc/examples/exa07", "north",
    "/doc/examples/exa09", "south",
  });

  add_item("beer", 20, 2, "alco", 5, "A glass of beer");
  add_item("ale", 50, 5, "alco", 10, "A glass of ale");
  add_item("whiskey", 200, 10, "alco", 30, "A shot of whiskey");
  add_item("water", 2, 1, "soft", 0, "A glass of water");
  add_item("bread", 15, 3, "food", 10, "A slice of bread");

  ::reset(arg);
  replace_program("/players/kryll/test/std_pub");
}
