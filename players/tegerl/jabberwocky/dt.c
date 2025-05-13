#define PPATH "/players/patience/ezo/island_link/"
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
      
   set_light(1);
   short_desc = "";
   long_desc = "";

   dest_dir = ({ "/room/church", "church", });

   set_time_to_trigger(0);
   set_dt_msg("You are walking slowly to the west.\n"+
              "Sphinxes open eyes.\nLightning bolts smash you.\n");
}


