inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="This is a hidden passage deep inside the volcano.  Filthy "+
            "water reaches up to your knees, and nasty green fungus grows "+
            "on the walls.  The passage continues futher to the west and "+
            "south.\n";

  items=({"water","The water is dirty and mildly acidic",
          "walls","Granite walls with green fungus on them",
          "passage","A hidden passage inside the volcano",
          "volcano","You are inside an active volcano",
          "knees","They are yours and covered in icky water",
          "fungus","Icky, nasty, slimy, green fungus",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c4","west",
             "/players/emerald/island/room/caves/room/c2","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
