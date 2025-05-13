inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="You are slogging through kneedeep water in a hidden passage "+
            "through the volcano.  The walls are covered with a green "+
            "slime which oozes a caustic-looking substance.  The cave "+
            "continues to the east and west.\n";

  items=({"water","Foul, acidic water",
          "passage","A hidden passage through the volcano",
          "volcano","A very active and unhappy volcano",
          "walls","The are covered in green slime",
          "slime","Really nasty green slime",
          "substance","It is eating through the granite walls",
          "cave","It leads further to the east and west",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c7","east",
             "/players/emerald/island/room/caves/room/c9","west",
           });

  ::reset(arg);
  replace_program("/room/room");

}
