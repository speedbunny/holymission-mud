inherit "room/room";


reset(arg) {

   short_desc="Stairwell in Abbey";

    long_desc=
       "You are in the upper southwest corner of the abbey. "+
        "There is a beautiful view of the courtyard from "+
        "here. You hear chanting to the north and see a "+
        "room to the east.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
             "/players/misticalla/guild/rooms/monkpray","north",
              "/players/misticalla/guild/rooms/idearoom","east",
              "/players/misticalla/guild/rooms/guildroom","down",
	     });

    ::reset(arg);

    replace_program("room/room");
}

