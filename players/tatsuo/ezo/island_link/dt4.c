#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object();

inherit "/room/deathtrap";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(0);
   short_desc = "Speartops in the ground, looking deadly";
   long_desc = 
      "This tunnel is surely under the sea. You can see this, because\n"+
      "water is running down the walls. There is a skeleton lying here,\n"+
      "covered with rotten clothes. All over the floor of the room are\n"+
      "shimmering speartips. They appear to be fixed somewhere under the\n"+
      "floor, maybe applied with a wicked DEADLY mechanism !?\n";

	dest_dir = ({ PPATH + "link10", "southwest", });

   set_time_to_trigger(0);
   set_dt_msg(
      "CLICK\n\nDamned, you triggered the trap. Spears are shooting out of\n"+
      "the ground and down the ceiling, making you look like a cactus !!!\n" );
}
