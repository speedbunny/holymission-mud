inherit "room/room";


reset(arg) {

   short_desc="Stairwell in Abbey";

    long_desc=
       "This is the upper northeast corner of the abbey. "+
       "There is a nice view of the courtyard from here "+
       "and you pause briefly to enjoy it. To the south is "+
     "a prayer room for the nuns, and to the west you see a board. \n";
       "spiral staircase leading down to the first level. "+
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
            "courtyard","It is quiet and you can see the fountain",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
              "/players/misticalla/guild/rooms/socialroom","west",
	      "/players/misticalla/guild/rooms/nunpray","south",
	     "/players/misticalla/guild/rooms/stairs","down",
             });

    ::reset(arg);

    replace_program("room/room");
}

