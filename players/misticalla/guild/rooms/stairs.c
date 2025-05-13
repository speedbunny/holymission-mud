inherit "room/room";


reset(arg) {

   short_desc="Stairwell in Abbey";

    long_desc=
        "This is the northeast corner of the monks abbey. There is a "+
        "spiral staircase leading up to the second level. "+
        "The green marble floors are shiny and clean, and the "+
        "walls are beautifully etched with ancient writing. A monk is "+
        "studying it intently. You see the bar to the south and hear "+
        "growling to the west.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
	    "writing","It is old and appears to be important",
	    "floor","You see your reflection in the marble",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
              "/players/misticalla/guild/rooms/bar","south",
              "/players/misticalla/guild/rooms/pantheroom","west",
              "/players/misticalla/guild/rooms/stairs2","up",
             });

    clone_list = 
          ({1, 1, "monk", "/players/misticalla/guild/monsters/monkb", 0, });


    ::reset(arg);

    replace_program("room/room");
}

