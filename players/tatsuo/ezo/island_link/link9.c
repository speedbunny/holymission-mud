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
      "You are in a natural cave. The cave is sloping up to the north.\n"+
      "A lot of rubble is here, nobody seems to need.\n";

      items = ({"rubble","What do you expect, to find some jewels ?",});

	dest_dir = ({ PPATH + "link10", "northwest",
		      PPATH + "link8", "east", });
}
