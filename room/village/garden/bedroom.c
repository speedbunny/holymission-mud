inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  clone_list = ({
    1, 1, "Chantilly's cat", "obj/monster", ({
      "set_name", "Chantilly's cat",
      "set_short", "Chantilly's cat",
      "set_long", "This must be Chantilly's persian cat. It likes "+
        "to laze around on her bed.\n",
      "set_alias_list", ({ "persian cat", "chantilly's cat" }),
      "set_race" , "cat",
      "set_level", 10,
      "set_gender", 2,
      "set_whimpy", 30,
      "set_wc", 10,
    }),
  });

  set_light(1);
  short_desc = "Chantilly's bedroom";
  long_desc =
    "Chantilly's bedroom is even larger than her living room. "+
    "There is a king-sized canopy bed draped with fine silk, "+
    "A gorgeous dresser, chest, two bed tables and two chairs "+
    "fill out the rest of the room. There is another picture "+
    "of Leo in here also.\n";

  items = ({
    "bed", "It is a huge canopy bed that could fit 3 or 4 quite "+
      "easily, unless they were trolls",
    "dresser", "A fine dresser made out of a strange wood",
    "chest", "The chest is made of wood, but is as hard as iron",
    "tables", "The bed tables have a couple of small boxes on them",
    "boxes", "They can't be opened",
    "chairs", "They are for changing",
    "picture", "This looks to be a more personal picture of Leo",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "closet", "north",
    VILLAGE_GARDEN + "living_room", "down",
  });

  ::reset(arg);
  replace_program("/room/room");
}

