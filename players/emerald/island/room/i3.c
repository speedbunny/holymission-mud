inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="The sun shines brightly against the white sand of the beach.  "+
            "It's a beautiful spot, and you feel like staying here for a "+
            "while.  A few palm trees grow to the north, their tops "+
            "swaying in a light breeze which cannot be felt at the beach.\n";

  items=({"beach","A long sandy beach",
          "trees","Really tall palm trees",
          "sun","Its rays beat down on the hot sand of the beach",
          "sand","The sand is hot under your feet",
          "beach","A soft, white, sandy beach",
          "tops","The tops of the trees sway in the breeze",
          "breeze","A light breeze, unfelt at sea-level",
        });

  dest_dir=({"/players/emerald/island/room/i1", "south",
             "/players/emerald/island/room/i7", "north",
             "/players/emerald/island/room/i2", "west",
             "/players/emerald/island/room/i4", "east",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/blue",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A blue dragonskin",
      "set_long","The excellent armour of the blue volcano Dragon.\n",
      "set_value",2000,
      "set_weight",2,
    }),
    2,1,"shell","obj/thing",({
      "set_name","shell",
      "set_short","A seashell",
      "set_long","A small seashell.\n",
      "set_can_get",1,
      "set_weight",1,
      "set_value",5,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
