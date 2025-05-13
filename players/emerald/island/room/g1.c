
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light( 1 );

  short_desc="In a cavern";

  long_desc="You are at the entrance of a big cavern leading further into "+
            "the volcano.  The walls are made of black stones and there are "+
            "lighted torches fixed to the walls.  Heavy stones are lying "+
            "on the ground and there is a small path leading further north "+
            "and some light coming from the south.\n";

  items=({"cavern","The cavern leads further to the north and south",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "entrance","You are just standing at the entrance of the cavern",
          "walls","The walls are dark and made of black stones",
          "ground","The ground is full of dark stones",
          "path","The path is dark and leading further to the north",
          "light","Light coming from the south",
          "volano","You are just inside the volcano"
        });

  dest_dir=({"/players/emerald/island/room/g2","north",
             "/players/emerald/island/room/i22","south"
           });

  clone_list=({
    1,1,"dragon","/players/emerald/island/obj/white",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
