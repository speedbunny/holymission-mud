//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;
::reset(arg); 

    set_light(1);
    short_desc= "Inside a Log House";
    long_desc=
       "You are standing before a small log house. "+
       "The house looks like it is very run down "+
       "and in a state of disarray.  You notice "+
       "a tree to your east with a wooden board attached "+
       "to it by some rope.\n";


    dest_dir=({
               "players/dragonn/area/ctr32", "north",
          "players/dragonn/area/ctr35","west",
          "players/dragonn/area/ctr37","east",
             });

    items=({ 

    "board","A simple board",
    "house","You notice the small log house to your west. It looks like a "+
        "place to check out",
"tree","You notice a tall elm tree to your east "+
         "with a swing "+
        "attached to it",
      "rope","You see a old rope",
    "swing","Just a simple swing",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
