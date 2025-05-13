inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The edge of a grassy plain";
  long_desc="Dark and ancient trees line the southern border of the vast " +
            "grassy plain.  A ridge of mountain peaks marks the northern " +
            "boundary.  A sea of grass is the only thing visible between " +
            "those two landmarks.  Dotting the plain with splashes of " +
            "colour are a few flowers.\n";

  dest_dir=({"/players/emerald/plain/p18","north",
             "/players/emerald/plain/p10","east",
             "/players/emerald/plain/p08","west",
             "/players/emerald/plain/p19","northeast",
             "/players/emerald/plain/p17","northwest",
           });

  items=({"trees","Gnarled trunks of oak, elm, and maple",
          "plain","A veritable sea of grass",
          "ridge","Grey peaks which break up the northern horizon",
          "peaks","Snow-capped mountain peaks",
          "grass","Long golden stems of waving grass",
          "flowers","They grow in between the clumps of grass.  You could "+
                    "probably pick one",
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
    move_object(clone_object("/players/emerald/plain/aconite"),this_player());
    return 1;
  }
}
