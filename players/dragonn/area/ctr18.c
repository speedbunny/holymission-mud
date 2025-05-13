//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You notice a small pond to your northeast. "+
    "You spot a small female deer drinking from "+
    "the water.  She is standing in a patch of "+
    "beautiful flowers that are sprinkled "+
    "throughout the countryside.\n";

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());

    dest_dir=({
               "players/dragonn/area/ctr11", "north",
               "players/dragonn/area/ctr17", "west",
               "players/dragonn/area/ctr19", "east",
               "players/dragonn/area/ctr24", "south",
             });

    items=({ 
            "deer","You are looking at a small female deer that could "+
                   "easily be mistaken for some food",
            "flowers","There are patches of flowers covering the beautiful"+
                      " countryside",             
            "pond","You notice how crystal clear the pong is."+
                   "You can see the fish easily",
            "fish","You spot a two pound trout wimming near the shore",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
