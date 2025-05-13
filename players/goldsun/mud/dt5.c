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
      
   set_light(0);
   short_desc = "Abandoned mine entrance, full of magical energy";
   long_desc = 
      "This appears to be an abandoned mine entrance, probably made by\n"+
      "dwarves. The walls are skillfully worked and the entrance is richly\n"+
      "ornamented. Unfortunately the gate is closed and it is shimmering\n"+
      "in a faint blue light, like as the whole room seems to shimmer in\n"+
      "this light. Surely this is magic.\n";

	dest_dir = ({ PPATH + "link10", "northeast", });

   set_time_to_trigger(0);
   set_dt_msg(
      "As you enter the room, you can remember, that you have seen this\n"+
      "kind of light again. It is the same, the lightnings, used by mages\n"+
      "look like. Recognising this in the last second, you panically turn\n"+
      "around and try to get out of the room. But before you even have\n"+
      "finished the turn, you are torn apart by lightnings, shooting out of\n"+
      "seemingly everywhere in the room ....\n" );
}
