//Dragonn-coderrrrio...'96
#define CO clone_object
#define TP this_player()

inherit "room/room";
 reset(arg){
::reset(arg);
if(arg) return;
    set_light(1);
    short_desc= "Path";
    long_desc=
"You are standing on a path which  leads in an east-west direction. "+
"To the west lies a beautiful garden, while off to the "+
"east opens into dangerous countryside of Pavi.\n";



    dest_dir=({
               "players/jug/room/garden/gard_ent", "west",
               "players/dragonn/area/ctr01", "east",
             });

    items=({ 
      "path","A simple path",
   "garden","You notice the garden to the east",
      "countryside","Dangerous countryside of Pavi",
         
          });
}
