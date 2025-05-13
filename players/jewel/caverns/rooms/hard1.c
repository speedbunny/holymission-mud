inherit "room/room";

reset(arg) 
{
    if (!arg)
    {
       set_light(0);
       short_desc = "Crystal Cavern";
       no_castle_flag = 0;                                    
       long_desc = "The first cavern of the northwest branch.\n"+
       "All around you feel impending danger and doom.  The walls are wet.\n";
       dest_dir = 
           ({"players/jewel/room/hard2", "west",
             "players/jewel/room/central", "southeast" 
           });
       items =
           ({"floor","Here you see limestone stalagmites protruding from the floor.\n"+
              "Also the floor is covered with gooey ooze",
             "wall","The wall is wet with the remnants of slimy ooze",
             "walls","The walls are wet with the remnants of slimy ooze",
             "ceiling","You see several sharp stalactites, dripping water on your uplifted face ",
             "stalagmite","Limestone stalagmite protruding from the floor. Maybe you can break it off",   
             "stalactite","Limestone stalactite dripping water onto your face"
           });
    }

}
init()
{
  add_action("break_stalag","break");
  ::init();
}

break_stalag(arg)
{
    if(arg == "stalagmite")
    {
        write("Well, oneday this will be a weapon\n");
    }
    return 1;
}

query_light() {
    return 1;
}



