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
   short_desc = "Three way intersection";
   long_desc = 
       "A three way intersection. Pathes leading east, west, southeast.\n"+
       "However, a terrible stench comes from the east and you hear\n"+
       "weird noises.\n";

	dest_dir = ({ PPATH + "link10", "southeast",
                      PPATH + "link12", "west",
                      PPATH + "cc_cave", "east", });
}
