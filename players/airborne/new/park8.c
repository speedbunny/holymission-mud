inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc =
"The park stays lit by the glowing moss and the bushes and flowers are "+
"prospering because of it. There seems to be a broken path leading through "+
"the bushes to the south and the cobblestone path leads north, east, and "+
"west in the park.\n";

   dest_dir = ({"players/airborne/new/park5", "north",
		"players/airborne/new/park9", "east", 
		"players/airborne/new/park7", "west", });

   items = ({"park", "A calm and relaxing park",
	"moss", "The moss is glowing lightly",
	"path", "A grey cobblestone path leading through the park",
	"broken path", "A path going through bushes leading outside the park",
	"bushes", "Small bushes and other shrubery", });

if(!present("duegar", this_object())){
object fake;

    fake = clone_object("obj/monster");
    fake-> set_name("duegar");
    fake-> set_alt_name("trog");
    fake-> set_race("duegar");
    fake-> set_alias("ugly trog");
    fake-> set_short("An ugly trog");
    fake-> set_long
("At first you see what you think is the ugliest Trog ever made, however \n"+
 "he turns quickly and you notice that it isn't a Trog, but a Duegar!\n");
    fake-> set_level(10);
    fake-> set_gender(1);
    fake-> set_ac(6);
    fake-> set_wc(10);
    fake-> add_money(200);
   	move_object(fake, this_object());
		}
	}
}

init(){
::init();

   add_action("no_south", "south");
   add_action("pick", "pick");
   add_action("pick", "gather");

	}

pick(){
   write("There doesn't seem to be anything you can pick here.\n");
   return 1; }


no_south(){

  if(!present("duegar", this_object())){
	write("You leave south.\n");
        this_player()->move_player("south#players/airborne/new/path1");
	return 1; }

  else {
     write("The Duegar jumps in front of you and stops you.\n");
     return 1; }

	}  
