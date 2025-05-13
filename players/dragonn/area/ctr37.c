//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "Inside a Log House";
    long_desc=
     "This place has trees hovering above "+
       "you with many branches shading over "+
       "you and protecting you from the sun. "+
       "You see many flowers facing the sun "+
  "and soaking up it rays.\n";

    dest_dir=({
               "players/dragonn/area/ctr33", "north",
               "players/dragonn/area/ctr36", "west",
               "players/dragonn/area/ctr38", "east",

             });

    items=({ 

    "flowers","They are facing the sun",
    "tree","Huge shady tree protecting you from the sun",
    "branches","You spot the branches from a nearby elm tree",

          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
