
//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
"You are traveling on a path that continues "+
"to your north and south.  You notice a trail "+
"branching off to your east with flowers growing "+
"all around it.  You spot a house in the distant "+
"southwest.\n";

    dest_dir=({
               "players/dragonn/area/ctr29", "north",
               "players/dragonn/area/ctr33", "east",
               "players/dragonn/area/ctr36", "south",

             });

    items=({ 
  "path","You are standing on a dirt path.  It continues to "+
         "the north and south",
  "trail","You spot a dirt trail branching off to your east",
  "flowers","You see many beautiful wild flowers protruding from "+
        "the ground",
  "house","You notice a house to your distant southwest.  It might "+
        "be a nice place to check out",

          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
