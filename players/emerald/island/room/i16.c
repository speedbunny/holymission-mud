inherit "/room/room";

void reset(int arg) {
  if(arg)return;

  set_light(1);
  short_desc="On an island";

  long_desc="Scrubby bushes surround the plateau.  A few black rocks, the "+
            "remnants of old lava flows, block any exit to the east.  To "+
            "the north and west, the plateau drops off, leading down to the "+
            "sea.  It would be an easy jump from here to the sea below.  "+
            "The path continues further to the south and up the volcano.\n";

  items=({"bushes","They surround the plateau",
          "plateau","A small plateau on the volcanic island",
          "rocks","Weathered basalt",
          "flows","Lava flows cooled to form the basalt rocks",
          "sea","Jumping into the sea from here would be quite possible",
          "path","It leads to the south and up the volcano",
          "volcano","You are on a path which leads up and down a volcano",
        });

  dest_dir=({"/players/emerald/island/room/i17", "up",
             "/players/emerald/island/room/i11", "south",
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/green",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_short","A green dragonskin",
      "set_long","The excellent armour of the green volcano Dragon.\n",
      "set_value",1000,
      "set_weight",2,
    }),
  });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_jump","jump");
}

int _jump() {
  write("************  Y o u   a r e   f a l l i n g ************!\n\n"+
        "************  Y o u   a r e   f a l l i n g ************!\n\n"+
        "************  Y o u   a r e   f a l l i n g ************!\n");
  this_player()->move_player("down#players/emerald/island/room/i10");
  return 1;
}
