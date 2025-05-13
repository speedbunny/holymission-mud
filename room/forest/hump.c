inherit "room/room";

#include "/room/room_defs.h"

status searched;

void reset (int arg) {
  searched  = 0;

  ::reset(arg);
  if(arg) return;

  set_light (1);
  short_desc = "Humpbacked bridge";

  long_desc =
    "You are on a humpbacked bridge, crossing a " +
    "peaceful river flowing from the north, greened " +
    "with bushes and sappy beech trees. On the " +
    "bridge a small heap of beech twigs and rotting " +
    "leaves spread a sweetened moldy smell.\n";

  items = ({
    "bridge", "An old, wellbuilt bridge made of heavy " +
      "stones, framed by a dirty heap of leaves " +
      "on each side",
    "bushes", "Sappy green bushes, which drink from " +
      "the water of the river",
    "beeches", "They look healthy, getting their water from "+
      "the river",
    "beechtrees", "They look healthy, getting their water "+
      "from the river",
    "beech trees", "They look healthy, getting their water "+
      "from the river",
    "trees", "They look healthy, getting their water from the "+
      "river",
    "leaves", "@@heapdesc@@",
    "heap", "@@heapdesc@@",
    "beech twigs", "@@heapdesc@@",
    "twigs", "@@heapdesc@@",
    "water", "It is clear and looks very deep",
    "river", "The river is very deep, too deep for a " +
      "man to stand on the bottom",
  }); 
       
  dest_dir = ({
    HM_VILLAGE + "street12", "east",
    FOREST + "wild1", "west",
  });
}

string heapdesc() {
  return ("Many twigs, sticks and half-rotten leaves from " +
    "the last storm cover the trash that people have " +
    "dropped or lost there. It might be an idea to " +
    "search the leaves if there is something useful " +
    "left in that heap");
}

void init() {
  ::init();
  add_action("_search","search");
}

status _search(string str) {
  string invis_msg;
  object temp;

  invis_msg = "You hear a rustling noise as the heap of " +
              "leaves moves aside!";

  switch(str) {
    case "bridge" :
    case "room" :
      write("You search on the street and find a heap of twigs "+
            "and leaves.\n");
      return 1;
    case "heap" :
    case "twigs" :
    case "leaves" :
    case "beech twigs" :
      if(TP->query_ghost()) {
        write("Your incorporeal hands pass right through the heap.\n");
        return 1;
      }

      if(searched) {
        write("You stir up the leaves, but you find " +
                   "nothing useful left.\n");
        if(TP->INV) {
          say(invis_msg + "\n");
          return 1;
        }
        say(lw(TP->NAME + " stirs up the leaves on the road.\n"));
        return 1;
      }
      searched = 1;

      write("You find 10 gold coins and a dry, combustable stick.\n");
      if(TP->INV)
        say(lw(invis_msg +
               " Some gold appears - and disappears again very "+
               "mysteriously! " +
               "A dry, combustible stick rises from the ground and "+
               "then vanishes also.\n"));
      else 
        say(lw(TP->short() + " stirs up the leaves and finds " +
               "some money and a dry stick.\n"));
      TP->add_money(10);

      temp = clone_object("obj/torch");
      temp->set_name("stick");
      temp->set_short("a stick");
      temp->set_long("This stick is slightly black on one end.\n");
      temp->set_fuel(500);
      temp->set_weight(1);
    
      if(transfer(temp, TP)) {
        write("You have no hands left to pick up the stick.\n");
        if(TP->INV) {
          say("A stick falls to the ground.\n");
        }
        else
          say(TP->short() + " drops a stick.\n");
        move_object(temp, TO);
      } 
      return 1;
    default : 
      notify_fail("Search what?\n");
      return 0;
  }
}
