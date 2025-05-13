inherit"room/room";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Shore sea port",
    long_desc="This is the seaport near the shore of the town.\n" +
              "You see lots of seagulls flying around here and a\n" +
              "nice old man is selling tickets for a boat trip.\n";
    
    items=({"sea","It's very rough today",
            "boats","You see lots of old tiny boats",
            "boat","What a lovely old fishing boat",
            "castle","You see the big black tower of Walhalla"});

    property =({"no_sneak","no_hide"});

    dest_dir =({"/room/shore/s50","west"});

    smell = "You smell the fresh air of the open sea";

    move_object(clone_object("/players/beardy/east_harbour/monster/sailor"),this_object());
   move_object(clone_object("/players/beardy/east_harbour/obj/sign"),this_object());
  }
}


void init()
{ ::init();
  if(!present("boat",this_object()))
    move_object(clone_object("/players/beardy/east_harbour/obj/ship"),this_object());
}
