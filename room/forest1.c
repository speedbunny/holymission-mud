inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="In a forest";

    long_desc=
              "You are in a big forest. You can see trollish footprints"+
              " leading off south.\n";

    dest_dir=({
               "players/moonchild/trollslayer/troll1","south",
               "room/wild1", "east",
               "room/clearing", "west",
             });

    clone_list = ({ 1, 1, "leather jacket", "obj/armour", 
                         ({"set_name", "leather jacket",
                           "set_short", "A leather jacket",
                           "set_alias", "jacket",
                           "set_long", "A worn but sturdy leather jacket.\n" +
                                       "On the back is a lot of rivets " +
                                       "making the pattern of a star.\n",
                           "set_weight", 2,
                           "set_value", 50,
                           "set_size", 3,
                           "set_ac", 2,
                           "set_type", "armour/arm", }),
                 });

    ::reset();
    replace_program("room/room");
}
