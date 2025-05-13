inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prarie";

  long_desc="You are standing on a small prairie on the volcano.  Huge black "+
            "rocks block the prairie to the north and east.  A small "+
            "opening to the south leads down into the volcano.  The peaks "+
            "of mountains surround the prairie.  Bushes and grass grow "+
            "thickly in the rich soil, while far off to the north, a dark "+
            "forest begins.\n";

  items=({"prairie","A small prairie on a plateau on the volcano",
          "volcano","An active, rumbling, and unhappy volcano",
          "rocks","Massive chunks of basalt",
          "opening","It leads down into the volcano",
          "peaks","The rounded caps of mountains",
          "mountains","Volcanic mountains",
          "bushes","Dense shrubs",
          "grass","Thick stands of tall grass",
          "soil","Rich volcanic soil",
          "forest","A dark forest, lurking in the distance",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c11","down",
             "/players/emerald/island/room/caves/room/p3","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
