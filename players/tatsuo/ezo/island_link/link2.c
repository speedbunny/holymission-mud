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
   short_desc = "A narrow tunnel";
   long_desc = 
      "A really narrow tunnel, but at least you can crawl in it.\n"+
      "It is hewn out of the rock very unskillfully and you have to keep\n"+
      "your head down.\n";

	dest_dir = ({ PPATH + "link3", "northwest",
					  PPATH + "link1", "south", });
}
