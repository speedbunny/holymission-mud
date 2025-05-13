inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A vast grassy plain";


  long_desc="You are standing amidst of sea of waving grass.  The wind " +
            "is causing the stalks to bend in long rippling waves which " +
            "shimmer in the sunlight.  Here and there, the bloom of a " +
            "wild daisy breaks the golden monotony.  Far to the north " +
            "the plain is bordered by a high mountain range.  The dread " +
            "Ilkin Forest lies south and east.  West lies the enchanted " +
            "path, the only safe passage through this region.\n";

  dest_dir=({"/players/emerald/plain/p04","north",
             "/players/emerald/plain/p03","east",
             "/players/emerald/plain/p01","south",
             "/players/kryll/rooms/path/ep13","west",
             "/players/emerald/plain/p05","northeast",
             "/players/kryll/rooms/path/ep14","northwest",
             "/players/kryll/rooms/path/ep12","southwest",
           });

  items=({"grass","Long stalks of golden grass",
          "stalks","The dried stems of grass",
          "waves","They travel across the plain, moved by the wind",
          "daisy","A small white and yellow flower",
          "plain","A flat area of grassland",
          "range","It is quite distant from here",
          "forest","The dark and dangerous Ilkin Forest",
        });

  clone_list=({
    1,1,"snake","obj/monster", ({
      "set_name","snake",
      "set_race","reptile",
      "set_level",14,
      "set_short","A garter snake",
      "add_money",130,
    }),
    -1,1,"skin","obj/armour", ({
      "set_name","snake skin",
      "set_alias","skin",
      "set_ac",4,
      "set_value",100,
      "set_weight",1,
      "set_size","small",
      "set_short","A mottled snake skin",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
