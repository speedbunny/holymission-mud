inherit "room/room";

reset(arg){
 if(!arg){
   
   set_light(0);
   short_desc = "Trog village";
   long_desc = 
"You are standing next to a big cliff, standing at least 300 feet in the "+
"air. The surface of the cliff looks difficult to accend, but you might be "+
"able to with the right trappings. Red stains are scattered here and there "+
"along the ground.\n";

   dest_dir = ({"players/airborne/new/town2", "east",
	"players/airborne/new/town10", "south", });

   items = ({"cliff", "A tall cliff at least 300 feet high made of stone",
	"stains", "The look like blood stains. Maybe someone didn't fair too well on the cliff?",
	"ground", "The ground is mainly dirt with red stains scattered about", });

   	}
}

init(){
 ::init();

 add_action("climb", "climb");
 add_action("what", "up");
	}

climb(str){

  if(!str){ 
    write("Climb what?\n"); 
    return 1; }
  if(str=="up" || str=="cliff"){
     if((present("climbing spike", this_player())) && (present("climbing boots", this_player()))){
       	write("With a little work you manage to make it.\n");
        this_player()->move_player("up#players/airborne/new/cave3");
	return 1; }
     else {
	write("Try as you might, you cannot get to the top.\n");
	return 1; } }
  
  else {
	write("Climb what?");
	return 1; } 
}

what(){
   write("You might have to climb to get up there.\n");
   return 1; }

