inherit"room/room";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Ground floor of Walhalla",
    long_desc="This is the ground floor of Walhalla. The room is very\n" +
              "high and the bottom is covered with strange fog. There \n" +
              "are some strange holes in the ceiling.\n"; 
    
    items=({"fog","Huh ! It's cold",
            "bottom","What a dense fog",
            "ceiling","There are lots of holes in there",
            "holes","Oops ! They seem to be burned"});

    property =({"no_sneak","no_teleport","no_hide"});

    dest_dir =({"/players/beardy/walhalla/room/floor1","south",
                "/players/beardy/walhalla/room/floor3","west",
                "/players/beardy/walhalla/room/floor4","north",
                "/players/beardy/walhalla/room/floor6","east",
                "/players/beardy/walhalla/room/floor7","southeast",
                "/players/beardy/walhalla/room/floor5","northeast"});

    smell = "It smells divine in here";
  }
}
