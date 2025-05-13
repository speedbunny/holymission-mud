inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="You've entered the cell, but you can't seem to go much further " +
            "than the doorway.  It could be just the size of the cell.  " +
            "Or it could be that there is an enormous giant blocking the " +
            "way.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h23", "east",
           });

  items=({"cell", "Dark, dirty, moldy, the basic dungeon cell",
          "doorway","A normal doorway",
        });

  clone_list=({
    1,1,"giant","/players/emerald/dungeon/monster/giant",0,
  });

  ::reset();
  replace_program("room/room");

}
