inherit"room/room";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Magi's isle sea port",
    long_desc="This is the port at the Isle of Magi.\n" +
              "Some birds are crossing you way and you see the open\n" +
              "land east from here.\n";
    
    items=({"sea","It's very rough today",
            "boats","You see lots of old tiny boats",
            "boat","What a lovely old fishing boat",
            "castle","You see the big black tower of Walhalla"});

    property =({"no_sneak","no_hide"});

    dest_dir =({"/room/south/sislnd9","east"});

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
