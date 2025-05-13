inherit "/room/room";

void reset(int arg){
  if(arg) return;

  set_light(1);
  short_desc="The eastern orc caves";

  long_desc="You are sneaking through the secret orc caves.  There are "+
            "tiny holes in the eastern side of the cave wall.  Beams "+
            "of light and the sounds of birds and the sea stream in through "+
            "the holes.  The passage leads further to the north and "+
            "south.  Strange noises come from the north.\n";

  items=({"caves","The secret orc caves",
          "holes","A view of the sea, seagulls, and a sandy beach can "+
                  "be glimpsed through the holes",
          "side","There are holes in the side of the cave",
          "wall","There are holes in the cave wall",
          "beams","Tiny beams of sunlight",
          "light","Tiny beams of sunlight",
          "birds","Looking through the holes, you can see some seagulls",
          "sea","Looking through the holes, you can see the sea",
          "passage","It leads to the north and south",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci21","north",
             "/players/emerald/island/room/caves/room/ci19","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
