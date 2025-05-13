inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The edge of the plains";
  long_desc="You are standing amidst a sea of waving grass at the northern "+
            "edge of the dark and dreary Ilkin Forest.  Across the plain, " +
            "to the north, rise the snow-capped peaks of high craggy " +
            "mountains.  The wind can be heard rustling the long stalks " +
            "of golden grass as it blows over the plain.  A tall flower " +
            "grows unmolested on a little tuffet of dirt.\n";

  dest_dir=({"/players/emerald/plain/p19","north",
             "/players/emerald/plain/p11","east",
             "/players/emerald/plain/p09","west",
             "/players/emerald/plain/p20","northeast",
             "/players/emerald/plain/p18","northwest",
           });
  items=({"grass","It is long and golden",
          "sea","The wind causes the grass to move in waves",
          "forest","It is dark and impenetrable at this point",
          "plain","A vast area of grassland",
          "peaks","Cold snowy mountain peaks",
          "mountains","They are quite high",
          "stalks","Golden and brown stems of grass",
          "grass","The heads are ripening in the sunlight",
          "flower","A tall flower.  You could pick it",
        });

  ::reset();

}

void init() {

  ::init();

  add_action("_pick","pick");

}

_pick(str) {

  if(str!="flower") {
    write("Pick what?\n");
    return 0;
  }

  if(str=="flower") {
    write("You bend down and pick a flower.\n");
    say(this_player()->query_name() + " picks a flower.\n");
    move_object(clone_object("/players/emerald/plain/foxglove"),this_player());
    return 1;
  }
}
