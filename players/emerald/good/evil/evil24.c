inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(0);

  short_desc="The Hag's Lab";
  long_desc="This is where the old hag makes strange things. Beakers " +
            "and broken bottles are strewn all over the room. You " +
            "wonder what the old hag was creating before she was killed.\n";

  dest_dir=({"/players/emerald/good/evil/evil6", "up",
          });

  items=({"beakers","They are filled with evil-looking liquids",
          "bottles","Broken bottles which once held chemicals",
          "room","It's messy",
        });

  clone_list=({
    1,1,"oil","obj/thing", ({
      "set_name","oil",
      "set_short","A bottle of oil",
      "set_long","A bottle of thick oil, good for cleaning rusty objects!\n",
      "set_weight",1,
      "set_value",10,
    }),
  });

  ::reset();
  replace_program("/room/room");

}

