inherit "room/room";


reset(arg) {

  short_desc="Room in an abbey";

    long_desc=
       "This is a dimly lit room in the abbey of the monks. You "+
       "see nuns congregating here and studying their texts. "+
      "The floors are of wood and creek slightly beneath your weight. "+
      "To the south is an office and to the north is a prayer room.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
              "players/misticalla/guild/rooms/office1","south",
              "players/misticalla/guild/rooms/nunpray","north",
             });
  
    clone_list =
          ({1, 2, "monk", "/players/misticalla/guild/monsters/nunb", 0, });


    ::reset(arg);

    replace_program("room/room");
}

