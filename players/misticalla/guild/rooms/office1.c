inherit "room/room";


reset(arg) {

   short_desc="Assistant Guildmaster's Office";

    long_desc=
        "You have entered the assistant guildmaster's office "+
        "in the upper southeast corner of the abbey. There is a desk "+
        "here and some papers. There is also a large bookcase against "+
        "one wall. You hear chanting in the next room, or "+
        "perhaps it is the room itself which makes these sounds. "+
        "The corridor to the north leads into another room in the "+
        "abbey, used for nuns to congregate. A room similar to it "+
       "lies to the west.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "room","Yep, this is absolutely, positively a room",
            "books","There are several books here that have been read many times",
            "papers","They are written in another language",
            "desk","It is neat and organized",
          });

    property=({ "no_teleport" });   


   dest_dir = ({
            "/players/misticalla/guild/rooms/nun1","west",
            "/players/misticalla/guild/rooms/nun2","north",
             });

    ::reset(arg);

    replace_program("room/room");
}

