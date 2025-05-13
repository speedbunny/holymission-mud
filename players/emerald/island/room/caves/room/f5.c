inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";

  long_desc="The shadows formed on the ground by the waving of the tree "+
            "branches through the air create eerie images.  The rustling of "+
            "the leaves makes you constantly turn and look over your "+
            "shoulder.  Dense shrubs block the way to the east.  The "+
            "eternal rumblngs of the volcano can be heard in the distance.\n";

  items=({"shadows","They are terribly creepy",
          "ground","It is covered with a thick layer of leaves",
          "branches","They creak in the wind",
          "air","The air is thick and stifling in the forest",
          "leaves","They shiver in the wind",
          "shoulder","Your shoulder.  It looks a little lumpy",
          "shrubs","Thick, high shrubs, armed with long thorns",
          "volcano","It sounds like it might erupt at any moment",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f4","west",
             "/players/emerald/island/room/caves/room/p9","south",
             "/players/emerald/island/room/caves/room/f8","northwest",
           });

  ::reset(arg);
  replace_program("/room/room");

}
