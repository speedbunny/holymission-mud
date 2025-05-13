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
   short_desc = "An unsafe chamber";
   long_desc = 
      "This is another natural room, but looking closely at the ceiling,\n"+
      "you can recognize big cracks in it. It appears to be VERY unstable.\n"+
      "Better get out of here quickly !\n";

	dest_dir = ({ PPATH + "link5", "south",
                 PPATH + "link6", "west" });

   items = ({ "ceiling", "It looks VERY unstable",
              "crack", "Wow, what a huge crack",
              "cracks", "They are long and narrow",
           });

   set_time_to_trigger(10);
   set_dt_msg( "The ceiling collapses !!!!!!!!!!!\n" );
}
