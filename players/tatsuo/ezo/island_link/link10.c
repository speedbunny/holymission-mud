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
   short_desc = "An intersection";
   long_desc = 
      "An intersection in this tunnel. Various ways lead to various\n"+
      "with surely various destinations. And .... various fates !\n";

	dest_dir = ({ PPATH + "link11", "northwest",
                      PPATH + "link9", "southeast",
		      PPATH + "dt4", "northeast", 
                      PPATH + "dt5", "southwest"});
}
