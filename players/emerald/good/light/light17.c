inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);
  short_desc="The end of the prarie";

  long_desc="The prairie has become an endless monotony of waving grass.  " +
            "To travel any further into the prairie, without food or water, "+
            "would be tantamount to committing suicide.  "+
            "Not a single living thing can be seen for miles in any " +
            "direction.  Even gophers have never inhabited this desolate " +
            "spot.\n";

  dest_dir=({"players/emerald/good/light/light16", "west",
           });

  items=({"prairie","It is quite boring, landscape-wise",
          "grass","There's lots of grass here",
          "spot","You are on a prairie",
        });

  ::reset();
  replace_program("/room/room");

}

