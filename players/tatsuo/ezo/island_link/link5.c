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
   short_desc = "Large tunnel";
   long_desc = 
      "This tunnel is very large. It also appears to be a natural tunnel,\n"+
      "with only slight modifications made by human hands.\n";

	dest_dir = ({ PPATH + "dt3", "north",
                 PPATH + "dt2", "northwest",
					  PPATH + "link4", "southeast", });
}
