inherit "room/room";
 
reset(arg) {
    if(arg) return;
    long_desc ="A small room\n" + 
         "\n" +
         "     You have entered a small room.\n" +
         "     The walls here all look ridden with\n" +
         "     holes. You notice mice scurrying into the\n" +
         "     shadows and the walls avoiding the light.\n" +
         "     Mice droppings are everywhere. You step\n" +
         "     into a rather large one and hear a SQUISH!\n" +
         "\n";
    short_desc = "Small room";
    dest_dir = ({
        "/players/animal/evil11", "south",
        "/players/animal/evil18", "east"
    });
    items = ({
        "wall","You see a small hole in the wall",
        "hole","You look in the hole and see a note",
        "note","You can barely make out part of one word '.noc.'"
    });  
    return; 
} 
 
query_long() { return long_desc; }
 
query_light() { return 0; }

