//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
   "You are traveling on a countryside path that "+
    "continues to the north and south.  You notice "+
    "a dirt trail leading west with small shrubs and "+
  "flowers by its side.\n",


move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    dest_dir=({
               "players/dragonn/area/ctr14", "north",
               "players/dragonn/area/ctr20", "west",
               "players/dragonn/area/ctr27", "south",
             });

    items=({ 
            "flowers","You spot yellow and white flowers growing all around"+
                      " you",
            "path","You notice a small countryside path that leads "+
                   "north to south",             
            "trail","You spot a dirt trail that leads west",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
