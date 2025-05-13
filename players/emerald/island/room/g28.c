inherit "obj/std_shop";

void reset(int arg) {
  if(arg) return;
  short_desc="In a cavern";
  long_desc="You are in a big cave in the volcano.  It's really hot, "+
            "but has a friendly feel to it.  The walls are made of black "+
            "stones and there are lighted torches fixed to the walls.  "+
            "There are a lot of little footsteps leading south.  There is "+
            "a SIGN fixed on the wall and a big wooden desk in the room.\n";

  store="/players/emerald/island/room/ostore";
  keeper="Krznrk";

  items=({"cave","The cave leads back to the south",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footsteps","You see a lot of tiny gnomish footsteps, leading south",
          "volcano","You are just inside the volcano",
          "krznrk","He is sitting behind the desk waiting patiently",
          "sign","A big iron sign.  Maybe you should read it",
          "desk","A big oaken desk"
        });

  dest_dir=({"/players/emerald/island/room/g24","south"
           });

  move_object(clone_object("/obj/torch"),query_store());
  move_object(clone_object("/obj/torch"),query_store());
  move_object(clone_object("/obj/torch"),query_store());
  move_object(clone_object("/obj/rope"),query_store());

  clone_list=({
    1,1,"blackmoon","/players/whisky/guild/monster/blackmoon",0,
  });
  ::reset(arg);

}

init() {
  ::init( );
  add_action("do_read","read");
}

int do_read(string str) {
  if (str!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("Here you can: list, buy, sell, value all kinds of stuff.\n");
  return 1;
}
