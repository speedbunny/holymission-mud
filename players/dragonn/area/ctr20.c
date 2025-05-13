//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
   "You are roaming around the beautiful countryside "+
  "of Pavi.  You notice the land is dotted with "+
    "beautiful flowers and small rose bushes.  This "+
    "land has to be a creation of the Gods due to "+
   "its peaceful atmosphere.\n",
  
move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    dest_dir=({
               "players/dragonn/area/ctr13", "north",
               "players/dragonn/area/ctr19", "west",
               "players/dragonn/area/ctr21", "east",
               "players/dragonn/area/ctr26", "south",
             });

    items=({ 
   "flowers","You spot many different color flowers growing "+ 
                      "from beautiful grass",
            "bushes","You notice a few rose bushes growing among the"+
                     " countryside",             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
