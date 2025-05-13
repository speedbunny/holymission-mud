inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc Caves";

  long_desc="This is the entrance to a vast cave.  There is a sickly-sweet "+
            "smell in the air.  Bones are strewn over the floor, and the "+
            "stone walls are stained with blood.  Strange noises come from "+
            "the north.\n";

  items=({"entrance","The entrance of a large cave",
          "cave","It's a big cave",
          "air","It smells foul",
          "bones","They could be yours someday..",
          "floor","It is littered with bones",
          "walls","Blood is splashed over the walls",
          "blood","It could be your blood on the walls in a few minutes",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f9","south",
             "/players/emerald/island/room/caves/room/ci2","north",
           });

  smell="The scent of death and decay.";
 
  ::reset(arg);
  replace_program("/room/room");

}
