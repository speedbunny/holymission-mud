//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You notice that the path bends to the south "+
    "ahead of you.  As you glance around you become "+
    "aware of your beautiful surroundings.  You hear "+
    "the faint chirping of crickets in the distance.\n";
    dest_dir=({
               "players/dragonn/area/ctr06", "west",
               "players/dragonn/area/ctr14", "south",
             });

    items=({ 
   "path","You are traveling on a dirt path. It seems to "+
         "be surrounded with flowers and shrubs",
"flowers","Long beautiful flowers and shrubs",
  "surrounding","You notice flowers and large trees surround "+
                   "you entire",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
