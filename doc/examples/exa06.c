inherit "room/room";
 
status found; // for the _search function
 
void reset(int arg) {
// Initialize a basic variable to indicate whether successfully
// searched or not. Note: This gets called every reset.
  found = 0;
 
  clone_list = ({
    1, 3, "frog", "obj/monster", ({
      "set_name", "frog",
      "set_short", "A frog",
      "set_long", "A vicious man-eating frog?\n",
      "set_level", 13,
      "set_al", -50,
      "set_wc", 10,
      "set_aggressive", 1,
    }),
  });
 
  ::reset(arg);
  if(arg) return; /* Return unless this is initialising */
 
  set_light(1);
  short_desc = "The bottom of a lake";
 
  long_desc =
    "You are at the shore of a lake. There are weeds growing "+
    "everywhere. The water in the lake is very murky, and looks "+
    "quite cold.\n";
 
  dest_dir = ({
    "/doc/examples/exa07", "east",
    "/doc/examples/exa05", "west",
  });
 
  items = ({
    "lake", "A damp, still lake",
    "weeds", "There are weeds all around the lake. They might "+
      "be hiding something",
    "water", "Dark, murky water",
    "shore", "The edge of the lake",
  });
}
 
void init() {
// Do the default init.
  ::init();
// Add an action for search that calls _search. Note: this is a
// redundant add_action in this case since players have a search
// command that looks for the function _search in the room.
  add_action("_search", "search");
}
 
status _search(string str) {
  object stone; /* Declare the stone */
 
// By default id(str) for the room returns 1 if str is equal to
// anything defined in items, else it returns 0. Therefore, if
// id(str) returns 0, you should pass a notify_fail message and
// return 0, to see if there are any other search functions to
// go through.
  if(!id(str)) {
    notify_fail("Search what?\n");
    return 0;
  }
 
// Checks to see if there is a frog in the room.
  if(present("frog"), this_object()) {
    write("The frog prevents you fromsearching anything!\n");
    return 1;
  }
 
// If "weeds" is being searched and somebody hasn't already found
// the stone, go through this. write goes to the player searching,
// and say goes to everyone else in the room. Then move the newly
// cloned object to the room and set its attributes.
  if(str=="weeds" && !found) {
    write("You search the weeds and find a strange stone!\n");
    say(this_player()->query_name() +
        " searches the weeds and finds something.\n", this_player());
    move_object(stone=clone_object("obj/treasure"), this_object());
 
    stone->set_id("stone");
    stone->set_short("A small stone");
    stone->set_long("A small shimmering black stone. "+
                    "It looks as if it may have magical properties.\n");
    stone->set_value(250);
    stone->set_weight(2);
 
// Set the found variable indicating the stone was found
    found=1;
    return 1;
  }
 
// If all other tests fail, then it means the weeds have been searched
// already and there is no stone there, so need to give a different
// message to the players.
  say(this_player()->query_name() + " searches the " + str +
      " and finds nothing.\n", this_player());
  write("You search the " + str + " and find nothing.\n");
  return 1;
}

