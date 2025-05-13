inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="In the dunes";
  long_desc="You have reached the southern end of the dunes.  The dark " +
            "and brooding Ilkin Forest lies to the south and west, its " +
            "thick branches obscuring the view to the interior.  The " +
            "sand evens out to the east, forming a broad beach leading " +
            "to a clear blue sea whose waves roll in steadily from the " +
            "vast expanse of water beyond.\n";

  dest_dir=({"/players/emerald/plain/d03","north",
             "/players/emerald/plain/b04","east",
             "/players/emerald/plain/b06","northeast",
             "/players/emerald/plain/d02","northwest",
             "/players/emerald/plain/b02","southeast",
           });

  items=({"dunes","High mounds of sand",
          "forest","A refuge for evil of all sorts",
          "branches","They seem to naturally weave together to block " +
                     "entrance into the forest",
          "interior","It is hidden",
          "beach","A broad white sand beach",
          "sea","A clear blue sea",
          "waves","They leave trails of foam as they break upon the beach",
          "water","Water in mass quantities to form a sea",
        });

  clone_list=({
    1,1,"snake","obj/monster", ({
      "set_name","snake",
      "set_race","reptile",
      "set_short","A small brown snake",
      "set_long","A small brown snake warming itself in the hot sand.\n",
      "set_level",5,
      "add_money",20,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
