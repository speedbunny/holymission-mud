inherit "room/room";
status searched;

reset(arg){
searched = 0;

 if(!arg){

   set_light(1);
   short_desc = "Max's treasure store";
   long_desc =
"This looks like it could be Max's private area. There is a strange glowing "+
"ball hanging above the room shedding enough light to see. Unfortunately, "+
"Max hasn't been down here in a long time so it is very dusty and dirty. "+
"Max probably doesn't remember what he has here himself.\n";

   dest_dir = ({"players/airborne/new/tent", "up" });

   items = ({"ball", "Looks like a magic spell that caused that light",
	"glowing ball", "Looks like a magic spell that caused that light",
	"dust", "Enough dust to make your mom mad that you were even here",
	"dirt", "Dirt is everywhere", });

   smell = "Stale air permiates the area.";

	}
}

init(){
::init();

 add_action("search", "search");
	}

search(){
object horn;

  if(searched==1){
	write("You find nothing here.\n");
        return 1; }

  else if (searched==0){
        write("You find a horn of a unicorn!\n");
    	horn = clone_object("players/airborne/new/horn");
        move_object(horn, this_object());
        searched = 1;
	return 1; }

	}	
