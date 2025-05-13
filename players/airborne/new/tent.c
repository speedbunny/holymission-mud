inherit "room/room";
status pillow_moved;

reset(arg){
object max;
pillow_moved = 0;

 if(!arg){

   set_light(1);
   short_desc = "Max's tent";
   long_desc = 
"As you enter the tent you see it is just as ostentatious inside as it was "+
"outside. For a small tent, it looks rather comfortable. Large pillows "+
"are scattered along the floor making for a comforable place to rest.\n";

   dest_dir = ({"players/airborne/new/park5", "out", });

   items = ({"tent", "A rather obnoxiously decorated tent",
	"floor", "The floor is covered with pillows", 
	"pillows", "Large tan pillows that look good for resting on", });

if(!present("max", this_object())){
	max = clone_object("players/airborne/new/monsters/max");
	move_object(max, this_object());
		}

	}
}

init(){
::init();

  add_action("move_it", "move");
  add_action("rest_here", "rest");
  add_action("down", "down");

	}

move_it(str){

 if(str=="pillow" || str=="pillows"){
   if(pillow_moved == 1){
	write("They have been moved already.\nYou can see the way down.\n");
	return 1; }
   else if(pillow_moved == 0){ 
     write("You move aside some pillows and notice a way down");
     say(this_player()->query_name()+" moved aside some pillows.\n");
     pillow_moved = 1;
     return 1; }

 
   else { 
	write("Move what?\n");
	return 1; }
	 }
}

rest_here(){
   write("You rest on some pillows.\nAhh... how relaxing.\n");
   say(this_player()->query_name()+" sits down on some pillows.\n"); 
   return 1; }

down(){
  if(pillow_moved){
    write("You leave through the secret exit.\n");
    this_player()->move_player("through a secret exit#players/airborne/new/secret");
	return 1; }
  
  else {
    write("What?\n");
    return 1; }

	}
