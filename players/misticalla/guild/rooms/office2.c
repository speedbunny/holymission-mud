inherit "room/room";


reset(arg) {

      short_desc="Guildmaster's Office";

    long_desc=
        "You have entered the office of the monk guildmaster "+
        "in the upper northwest corner of the abbey. There is a desk "+
        "here and some papers. There is also a large bookcase against "+
       "one wall. To the east and south are monk study "+
        "rooms.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
            "books","There are several books here that have been read many times",
            "papers","They are written in another language",
            "desk","It is neat and organized",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
           "/players/misticalla/guild/rooms/monk1","south",
           "/players/misticalla/guild/rooms/monk2","east",
             });

    ::reset(arg);

    replace_program("room/room");
}

