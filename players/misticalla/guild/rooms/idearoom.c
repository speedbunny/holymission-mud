inherit "room/room";


reset(arg) {

  short_desc="Idea Room in an abbey";

    long_desc=
        "This room is in the upper southwestern part of the abbey. "+
        "It is a place where ideas can be posted for the guild. "+
        "This is not a place for socialization, only ideas and "+
        "problems, or bugs may be posted. To the west is the "+
        "stairwell and to the east is a nuns room.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
             "/players/misticalla/guild/rooms/nun1","east",
             "/players/misticalla/guild/rooms/stairs3","west",
             });

    ::reset(arg);

    replace_program("room/room");
}

