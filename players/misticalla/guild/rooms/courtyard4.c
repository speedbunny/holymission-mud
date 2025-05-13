inherit "room/room";


reset(arg) {

    short_desc="Northeast Courtyard";

    long_desc=
       "You have entered the northeast corner of a courtyard. "+
       "The abbey surrounds this courtyard. Stone pathways lead "+
       "you to various parts of the monk's guild. Fragrant flowers "+
       "grow in beds next to the pathways, and in the center of "+
       "the courtyard is a beautiful fountain. The water "+
       "is fresh and clean. The sun reflects off of the water and "+
       "dances across the stones in the bottom of the "+
       "fountain. There is a shade tree here with a bench to rest on. "+
       "To the east is the monk bar, the north is a small room, and "+
       "the courtyard continues to the west, south, and southwest.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "fountain","It is bursting forth fresh water",
            "flowers","There are many here",
            "beds","They are full of flowers",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


  dest_dir=({
         "/players/misticalla/guild/rooms/pantheroom","north",
	 "/players/misticalla/guild/rooms/courtyard3","west",
	 "/players/misticalla/guild/rooms/courtyard2","south",
	 "/players/misticalla/guild/rooms/courtyard1","southwest",
	 "/players/misticalla/guild/rooms/bar","east",
             });

    ::reset(arg);

    replace_program("room/room");
}

