inherit "room/room";


reset(arg) {

  short_desc="Socialization room in an abbey";

    long_desc=
      "You pass through the archway and enter a room with a "+
       "board in the upper northeastern area of the "+
       "abbey. There is a board here for socialization purposes. "+
       "There is an idea board for the guild located in the "+
        "southwestern part of the abbey. The archway "+
      "to the west leads to another room. To the east "+
       "is a stairwell.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
              "/players/misticalla/guild/rooms/monk2","west",
              "/players/misticalla/guild/rooms/stairs2","east",
             });

    ::reset(arg);

    replace_program("room/room");
}

