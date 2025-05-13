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
   short_desc = "Extending tunnel";
   long_desc = 
      "The tunnel is extending here. It also slopes slightly downwards.\n"+
      "You think, you are still under Ezo, but the sea cannot be far away.\n";

	dest_dir = ({ PPATH + "link4", "north",
                 PPATH + "dt1", "west",
					  PPATH + "link2", "southeast", });
}
