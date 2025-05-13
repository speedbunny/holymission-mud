inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="The long stems of billowing grass flow out around you in all " +
            "directions.  Their spread is hindered to the north by sheer " +
            "mountains which rise high into the sky.  Above, the sun is " +
            "the lone occupant in the intensely blue sky.  Far away to the "+
            "south, the treeline of the Ilkin Forest is barely visible.\n";

  dest_dir=({"/players/emerald/plain/p32","north",
             "/players/emerald/plain/p14","south",
             "/players/emerald/plain/p25","east",
             "/players/emerald/plain/p23","west",
             "/players/emerald/plain/p33","northeast",
             "/players/emerald/plain/p15","southeast",
             "/players/emerald/plain/p31","northwest",
             "/players/emerald/plain/p13","southwest",
           });

  items=({"stems","Long stems of golden grass",
          "grass","It ripens in the sunlight",
          "mountains","Dark and silent grey mountains",
          "sun","Gazing directly at the sun will damage your retinas",
          "sky","A clear blue sky",
          "treeline","You can just barely see it from here",
          "forest","A decidedly dark forest of ill-repute",
        });

  clone_list=({
    1,1,"wolf","obj/monster", ({
      "set_name","wolf",
      "set_short","A grey wolf",
      "set_race","canine",
      "set_long","A cautious grey wolf.\n",
      "set_level",20,
      "add_money",400,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
