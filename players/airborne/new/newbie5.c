#define TP this_player()
#define TPN this_player()->query_name()

inherit "room/room";
status searched;

reset(arg){
searched=0;
 if(!arg){

   set_light(1);
   short_desc = "Complete newbie area";
   long_desc = 
"    Every room on Holy Mission will be special in its own way. Each room "+
"description will contain details and hints about the special commands that "+
"will be used in the room. For example, some rooms may hint that you should "+
"search the room. Other times you will be prompted to perhaps climb a rope "+
"or maybe move a stone, all depending on the room description.\n"+
"     Searching rooms can be very useful if you find yourself stuck. Many "+
"times a room will be hiding something that you may have over looked. You "+
"may want to search this room as well, who knows what you might find.\n\n"+
"    When you are ready, exit lesson 5.\n";
	no_obvious_msg = "";

   items = ({"rope", "There really isn't a rope here, just an example",
	"stone", "There is no stone here, just an example", });

   property = ({"no_tport_in", "no_tport_out", "no_steal"});
	}
}
init(){
 ::init();
	add_action("search", "search"); add_action("climb", "climb");
	add_action("move", "move");	add_action("leave", "leave");
	add_action("next", "lesson");
	}
next(str){
  if(!str){
	write("What lesson?\n");
	return 1; }
  if(str=="5"){
	write("You leave lesson 5.\n");
	this_player()->move_player("lesson 5#players/airborne/new/newbie6");
	return 1; }
  else {
	write("You are not ready for that lesson yet");
	return 1; }
	}
move(){
 write("There is really nothing to move here, but you are getting the idea.\n");
   return 1; }

climb(){
  write("There is nothing to climb here, but you are getting the idea.\n");
  return 1; }
leave(){
  write("You are leaving Airborne's newbie area.\n");
  write("Please mail him with any problems or suggestions.\n");
   	this_player()->move_player("after stopping the lessons#players/airborne/new/station");
 	return 1; }

search(){
object ob;

	if(searched){
	 write("Someone else must have searched here, you find nothing.\n");
	 return 1; }
  else {
		ob = clone_object("obj/treasure");
		ob->set_id("newbie_stone");
		ob->set_name("stone");
		ob->set_alt_name("green stone");
		ob->set_short("A green stone");
		ob->set_alias("stone");
		ob->set_long("A beautiful green stone.\n");
		ob->set_weight(1);
		ob->set_value(10);
	   transfer(ob, this_object());
	    	write("You found a small green stone!\nBetter get it before someone else does.\n");
	say(TPN+" found a green stone.\n");
	    searched =1;
	     	return 1; }
	}
