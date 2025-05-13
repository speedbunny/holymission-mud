inherit "room/room";


reset(arg) {

     short_desc="Bishop's Quarters in an abbey";

    long_desc=
       "This is the quarters of the bishop of the abbey. You feel you should "+
       "not be here but you glance around anyway. There "+
       "are several bookcases covering the walls. They are full of "+
      "old books and journals. There is a desk here along with a "+
       "chair. A bed is in the far corner. The Bishop must rest "+
       "there. The prayer room is back to the south.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
          });

    property=({ "no_teleport" });   


   dest_dir=({ "players/misticalla/guild/rooms/prayroom","south",});

    ::reset(arg);

    replace_program("room/room");
}

