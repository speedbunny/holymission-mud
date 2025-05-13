//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are on a dirt path that is surrounded by "+
    "beautiful wild flowers.  You notice a rather "+
    "large tree that has grown in the middle of the "+
    "path.  You hear the faint rustling of leaves in "+
    "the distance.\n";
 
    dest_dir=({
               "players/dragonn/area/ctr01", "north",
               "players/dragonn/area/ctr09", "east",
               "players/dragonn/area/ctr15","south",
             });

    items=({ 
             "flowers","You are surrounded by beautiful wild flowers",
   "flower","A beautiful wild flower",
 "tree","You notice that someone has carved an inscription "+
                   "into the side of the tree",
   "inscription","This is a very dangerous place. "+
          "There are a lot of large creatures which will not hesitate to kill you.\n",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
