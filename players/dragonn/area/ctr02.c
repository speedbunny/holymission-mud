//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
   ::reset(arg);
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
 "You are walking on a small dirt path that leads "+
    "through the beautiful countryside of Pavi.  You "+
    "notice wild flowers growing off the sides of the "+
    "path.\n";


    dest_dir=({
               "players/dragonn/area/ctr01", "west",
               "players/dragonn/area/ctr03", "east",
               "players/dragonn/area/ctr09", "south",
             });

    items=({ 
             "flowers","You notice a bunch of flowers",
            "path","You are standing on a dirt path that is in the middle "+
                   "of the beatiful countryside of Pavi",             
    "smell flowers","You recognize a smell of flowers\n",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
