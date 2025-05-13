inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The town well";

  long_desc="You have entered a simple wooden building.  In the middle of " +
            "it stands a stone well.  People patiently wait in queues " +
            "to fill up their buckets with water.\n";

  dest_dir=({"/players/emerald/town/t12","east",
           });

  items=({"well","An old stone well that gives the town its drinking water",
        });


  clone_list=({
    1,1,"rope","obj/rope",0,
  });
  ::reset(arg);
  replace_program("room/room");

}
