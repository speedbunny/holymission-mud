inherit"room/room";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="dragon island seaport",
    long_desc="This is the seaport of the dragon island. You see lots\n" +
              "dragons around here and some of the are carring ships.\n" +
              "Next to you there is an old sailor who sells tickets for\n" +
              "boat trips. Maybe you buy one ?\n";
    
    items=({"dragons","Wow ! What strong ones",
            "ships","Normal little fisherboats"});

    dest_dir =({"/players/whisky/island/room/island25","west"});

    smell = "You smell the fresh air";

    move_object(clone_object("/players/beardy/east_harbour/monster/sailor"),this_object());
   move_object(clone_object("/players/beardy/east_harbour/obj/sign"),this_object());
  }
}


void init()
{ ::init();
  if(!present("boat",this_object()))
    move_object(clone_object("/players/beardy/east_harbour/obj/ship"),this_object());
}
