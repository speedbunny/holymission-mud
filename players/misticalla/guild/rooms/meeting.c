inherit "room/room";

reset(arg) {

    short_desc="Meeting room in an abbey";

    long_desc=
       "As you enter the room you see a long mahogany table "+
       "that stretches from one end of the room to the other. "+
       "There are many paintings on the walls and chairs at the "+
       "table. The room is well lit and you see an "+
       "inscription on the wall that reads 'Meeting Room' "+
       "and you assume that this is the place that monks and "
     + "nuns congregate and discuss important matters. "+
       "There is a cross on the wall with flowers woven "+
       "into it. The shop is to the north and the west is the "+
       "chapel.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
            "cross","It is made of some sort of branches woven together",
            "table","It is long and wooden, used for discussions",
            "chairs","They are comfortable chairs",
            "room","Yep, this is absolutely, positively a room",
          });

    property=({ "no_teleport" });   


    dest_dir=({
	"players/misticalla/guild/rooms/chapel","west",
        "/players/misticalla/guild/rooms/shop","north",
             });

    ::reset(arg);

    replace_program("room/room");
}

