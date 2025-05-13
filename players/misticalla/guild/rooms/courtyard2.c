inherit "room/room";


reset(arg) {

   short_desc = "Southeast Courtyard";

    long_desc=
      "You have entered the southeast corner of a courtyard. "+
      "The abbey surrounds this courtyard. Stone pathways lead "+
      "you to various parts of the monk's guild. Fragrant flowers "+
      "grow in beds next to the pathways, and in the center of "+
      "the courtyard is a beautiful fountain. The water "+
      "is fresh and clean. The sun reflects off of the water and "+
      "dances across the stones in the bottom of the "+
      "fountain. There is a shade tree here with a bench to rest on. "+
      "The shop is to the east and a engagment chapel "+
      "lies to the south. The courtyard continues to the west, north "+
      "and northwest.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "fountain","It is bursting forth fresh water",
            "flowers","There are many here",
            "beds","They are full of flowers",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


    dest_dir=({
           "/players/misticalla/guild/rooms/shop","east",
           "/players/misticalla/guild/rooms/courtyard4","north",
           "/players/misticalla/guild/rooms/courtyard3","northwest",
           "/players/misticalla/guild/rooms/chapel","south",
  	   "/players/misticalla/guild/rooms/courtyard1","west",
             });

    ::reset(arg);

    replace_program("room/room");
}

