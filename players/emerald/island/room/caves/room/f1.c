inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";

  long_desc="The branches of the trees in this dark forest move slightly "+
            "in the wind.  There are frightful shadows on the ground.  The "+
            "rustling of the leaves sounds eerie and strange.  Off in the "+
            "distance you can hear the eternal rumblings of the volcano.  "+
            "Dense shrubs block the way to the west.\n";

  items=({"branches","They creak in the wind",
          "trees","Oak, beech, and pine",
          "forest","A mixed decidous forest",
          "wind","It causes the branches to swing",
          "shadows","Strange shadows on the ground",
          "ground","It is covered with dead leaves",
          "leaves","They make a strange sound in the wind",
          "volcano","You are on a volcanic island",
          "shrubs","They cannot be climbed",
        });
  dest_dir=({"/players/emerald/island/room/caves/room/f2","east",
             "/players/emerald/island/room/caves/room/p5","south",
             "/players/emerald/island/room/caves/room/f6","northeast",
           });

  ::reset(arg);
  replace_program("/room/room");

}
