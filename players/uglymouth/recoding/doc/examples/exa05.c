inherit "room/room";
 
void reset(int arg) {
// There is only a bag with items cloned into it.
  clone_list = ({
    1, 1, "bag", "obj/container", ({
      "set_name", "bag",
      "set_short", "A bag",
      "set_long", "A large bag.\n",
      "set_value", 25,
      "set_weight", 1,
      "set_max_weight", 6,
    }),
    -1, 1, "pizza", "obj/food", ({
      "set_name", "pizza",
      "set_alt_name", "pepperoni pizza",
      "set_short", "A pepperoni pizza",
      "set_long", "A hot and spicy pepperoni pizza.\n",
      "set_value", 50,
      "set_weight", 1,
      "set_strength", 8,
      "set_eating_mess", " eats a pizza.\n",
      "set_eater_mess", "Pizza! Pizza!\n",
    }),
    -1, 1, "beer", "obj/alco_drink", ({
      "set_name", "beer",
      "set_short", "A bottle of beer",
      "set_long", "A nice bottle of cold beer.\n",
      "set_value", 15,
      "set_strength", 3,
      "set_drinking_mess", " drinks a beer.\n",
      "set_drinker_mess", "It really is good beer!\n",
      "set_empty_container", "bottle",
    }),
    -1, 1, "juice", "obj/soft_drink", ({
      "set_name", "apple juice",
      "set_alt_name", "juice",
      "set_short", "A bottle of apple juice",
      "set_long", "A nice cold bottle of apple juice.\n",
      "set_value", 15,
      "set_strength", 3,
      "set_drinking_mess", " drinks some apple juice.\n",
      "set_drinker_mess", "Very tasty indeed!\n",
      "set_empty_container", "bottle",
    }),
  });
 
// This room is dark.
  set_light(0);
  short_desc = "The storeroom";
 
  long_desc =
    "This is a store room, it is almost entirely empty.\n";
 
  dest_dir = ({
    "/doc/examples/exa06", "east",
    "/doc/examples/exa04", "south",
  });
 
  ::reset(arg);
  replace_program("room/room");
}
