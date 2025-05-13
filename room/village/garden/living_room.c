inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  set_light(1);
  short_desc = "Chantilly's living room";
  long_desc =
    "Chantilly's living room is very beautiful and meticulous. It "+
    "looks like she has spent years gathering all of her little "+
    "display items and furniture. There is a doorway to the north and "+
    "stairs leading up against the wall.\n";

  items = ({
    "items", "There are many including books on gardening, birds, flowers, "+
      "and insects; little figurines of animals, both exotic and "+
      "normal; and pictures of herself, her father and mother, and of "+
      "Leo",
    "books", "There are two books on flowers, two on birds, one on insects, "+
      "and one on gardening",
    "figurines", "There are a total of 10 figurines, made out of either "+
      "crystal, obsydian or jade",
    "crystal figurines", "The 6 crystal figurines are of a deer, fox, "+
      "elephant, sheep, eagle, and shark",
    "obsidian figurines", "The 2 obsydian figurines are of a panther and "+
      "a stallion",
    "jade figurines", "The 2 jade figurines are of a unicorn and dragon. "+
      "They are of such exquisite beauty that it must have been a dwarf "+
      "or another fine craftman to make this kind of quality figurine",
    "pictures", "There are 3 pictures at which to gaze upon. None are "+
      "signed, however, it appears all were painted by the same hand",
    "picture 1", "The first picture is of Chantilly from about 5 years "+
      "ago it seems",
    "picture one", "The first picture is of Chantilly from about 5 years "+
      "ago it seems",
    "first picture", "The first picture is of Chantilly from about 5 years "+
      "ago it seems",
    "picture 2", "The second picture is of Chantilly's parents in their "+
      "50s. They must have been quite old when Chantilly was born",
    "picture two", "The second picture is of Chantilly's parents in their "+
      "50s. They must have been quite old when Chantilly was born",
    "second picture", "The second picture is of Chantilly's parents in their "+
      "50s. They must have been quite old when Chantilly was born",
    "picture 3", "The third picture is of the archwizard Leo. It seems "+
      "out of place here",
    "picture three", "The third picture is of the archwizard Leo. It seems "+
      "out of place here",
    "third picture", "The third picture is of the archwizard Leo. It seems "+
      "out of place here",
    "furniture", "There are about 4 comfortable chairs, two tables, and "+
      "a bookcase in the room",
    "doorway", "It leads to the kitchen",
    "stairs", "They lead up into a room",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "kitchen", "north",
    VILLAGE_GARDEN + "entrance", "south",
    VILLAGE_GARDEN + "bedroom", "up",
  });

  ::reset(arg);
  replace_program("/room/room");
}

