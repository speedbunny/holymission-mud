#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object()

inherit "/room/deathtrap";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(0);
   short_desc = "A bottomless chimney";
   long_desc = 
        "This is chimney. You can whether see the ceiling nor the floor\n"+
        "of it, they are FAR beyond sight !\n";

	dest_dir = ({ PPATH + "link5", "southeast", });

   set_time_to_trigger(0);
   set_dt_msg(
      "You fall ....\n\nand fall .....\n\nand fall .....\n\n"+
      "you arrived !!!!!!!\n\nUnfortunately pierced by a stalagmite\n" );
}
