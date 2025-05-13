inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The dragon's lair";
  long_desc="You have entered an immense cell in the dungeon.  The ceiling " +
            "appears to be about forty feet about you.  The walls are " +
            "quite some distance apart, although they don't seem to be " +
            "quite far enough.  An immense dragon and its equally immense " +
            "hoard of treasure are squeezed into that space.\n";

  dest_dir=({"players/emerald/dungeon/rooms/hole", "southeast",
           });

  items=({"hole", "A hole in the wall leading to another cell",
          "walls","Black basalt walls",
          "cell","Rather large and spacious, as cells go",
          "ceiling", "The ceiling is far above you",
          "hoard", "A gigantic pile of treasure",
        });
 

  clone_list=({
    1,1,"dragon","/players/emerald/dungeon/monster/dragon",0,
    2,1,"coins", "obj/money", ({ "set_money",8000 }),
    3,1,"sapphire", "obj/treasure", ({
      "set_name", "sapphire",
      "set_short","A deep blue sapphire",
      "set_id", "sapphire",
      "set_value", 800,
      "set_short", "A sapphire",
      }),
    4,1,"emerald", "obj/treasure", ({
      "set_name", "emerald",
      "set_short","A sparkling green emerald",
      "set_id", "emerald",
      "set_value", 750,
      "set_short", "An emerald",
      }),
  });

  ::reset();

}

init() {

  ::init();

  add_action("get_it","get");
  add_action("get_it","take");
}
get_it(str) {
  if(!str) {
    notify_fail("Take what?\n");
    return 0;
  }

  if(present("dragon")) {
    write("The dragon jealously guards his hoard!\n");
    return 1;
  }
}
