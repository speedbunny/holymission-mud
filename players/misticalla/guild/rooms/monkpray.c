inherit "room/room";


reset(arg) {

  short_desc="Prayer Room in an Abbey";

    long_desc=
         "This is a room where monks can pray for things. It is "+
         "a room of rest and relaxation as well. There is an altar "+
         "on one wall and rows of books to study against another. "+
         "It is very quiet here, as it is required for all to "+
         "remove their shoes before prayer, and only silent "+
         "prayers are permitted. \n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "books","There are many old books here to read",
            "altar","It is made of wood and is lit with candles",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


    dest_dir = ({
             "/players/misticalla/guild/rooms/monk1","north",
            "/players/misticalla/guild/rooms/stairs3","south",
             });

    clone_list =
          ({1, 4, "monk", "/players/misticalla/guild/monsters/monka", 0, });

    ::reset(arg);

    replace_program("room/room");
}

