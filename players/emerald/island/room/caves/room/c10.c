inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="You are standing in a narrow part of a hidden passage through "+
            "the volcano.  A few beams of light fall into the passage from "+
            "an opening to the north.  The floor is damp, and a thin "+
            "film of green slime coats the walls.\n";

  items=({"part","It's very narrow and cramped here",
          "passage","A hidden passage through the volcano",
          "volcano","An active and rather grumpy volcano",
          "beams","Beams of light, blinding in the darkness of the cave",
          "light","Sunshine",
          "opening","It leads to the outside and sunshine",
          "floor","The floor of the passage is damp",
          "film","A thin coating of green slime",
          "slime","Nasty green slime, happily growing on the walls",
          "walls","Thick, rough, granite walls",
        });
  dest_dir=({"/players/emerald/island/room/caves/room/c9","south",
             "/players/emerald/island/room/caves/room/c11","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
