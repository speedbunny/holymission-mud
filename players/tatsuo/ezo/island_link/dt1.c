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
   short_desc = "A huge chamber";
   long_desc = 
      "This chamber is roughly hewn out of the rock. The rocks are massive\n"+
      "and sharp. Looking closely to the rocks you can see long, narrow,\n"+
      "vertical slots running along a wall. Inside the slots, the shimmer\n"+
      "of iron can be seen. You feel very unsafe in this room !\n";

   items = ({ "slot", "The iron inside the slot looks like a sharp blade",
              "slots", "The iron inside looks like a sharp blade",
           });

	dest_dir = ({ PPATH + "link3", "east", });

   set_time_to_trigger(6);
   set_dt_msg(
      "Suddenly long sharp blades are flashing out of slots, slicing you "+
      "apart !!!\n" );
}
