#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object();

inherit "/room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(0);
   short_desc = "A tunnel";
   long_desc = 
        "A narrow tunnel, mostly natural, with slight human (or dwarvish)\n"+
        "modifications. It is high enough so that you can walk upright.\n";

	dest_dir = ({ PPATH + "link13", "east",
                      PPATH + "link15", "west", });
}
