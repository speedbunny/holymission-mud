inherit"room/room";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Walhalla sea port",
    long_desc="This is Walhalla seaport. You are near the old devine\n" +
              "castle. The sea is very rough as every and only brave\n" +
              "ones should look for a free boat. If you are a brave one\n" +
              "buy a ticket from the old sailor.\n"; 
    
    items=({"sea","It's very rough today",
            "boats","You see lots of old tiny boats",
            "boat","What a lovely old fishing boat",
            "castle","You see the big black tower of Walhalla"});

    property =({"no_sneak","no_hide"});

    dest_dir =({"/players/beardy/asgard/room/start001","north"});


    smell = "You smell the fresh air of the open sea";

   move_object(clone_object("/players/beardy/east_harbour/obj/sign"),this_object());
    move_object(clone_object("/players/beardy/east_harbour/monster/sailor"),this_object());
  }
}


void init()
{ ::init();
  if(!present("boat",this_object()))
    move_object(clone_object("/players/beardy/east_harbour/obj/ship"),this_object());
}
