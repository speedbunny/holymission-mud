inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="Under the shadow of the mountains";
  long_desc="The immensity of the grey mountains which rise to the north " +
            "dwarf all else in the landscape.  A sea of grass flows away " +
            "from the mountains.  Far off to the south, a dark line at the "+
            "horizon marks the end of the plain and the beginning of the " +
            "ancient and evil Ilkin Forest.\n";
  dest_dir=({"/players/emerald/plain/p33","east",
             "/players/emerald/plain/p31","west",
             "/players/emerald/plain/p24","south",
             "/players/emerald/plain/p25","southeast",
             "/players/emerald/plain/p23","southwest",
           });

  items=({"mountains","Their height is incomprehensible",
          "landscape","It is mostly flat, except for the mountains",
          "sea","The grassland is unending like the sea",
          "grass","It glints gold in the sunlight",
          "line","Probably a treeline",
          "horizon","The meeting of land and sky",
          "plain","A vast expanse of waving grasses",
          "forest","Ancient, and utterly corrupt",
        });

  clone_list=({
    1,1,"eagle","obj/monster", ({
      "set_name","bald eagle",
      "set_race","bird",
      "set_alias","eagle",
      "set_wc",10,
      "set_level",20,
      "add_money",500,
      "set_short","A fierce bald eagle",
      "set_long","A mighty and wild bald eagle.\n",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
