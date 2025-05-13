inherit "room/room";


reset(arg) {

    short_desc="Prayer room in an abbey";

    long_desc=
    "You are in the western part of the abbey. This is a room for "+
    "monks and nuns to pray in. There is a beautiful altar here "+
    "with a place for people to kneel. The marble floors in this room "+
    "allow you to wander about the room without disturbing "+
    "anyone else. The courtyard is to the east.\n";
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
          });

    property=({ "no_teleport" });   


     dest_dir=({
         "players/misticalla/guild/rooms/courtyard3","east",
         "players/misticalla/guild/rooms/quarters","north",
             });

    ::reset(arg);

    replace_program("room/room");
}

