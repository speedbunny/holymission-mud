inherit "room/room";
int i;

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc = 
"The park is small and beautiful. A strange green glowing moss fills the area "+
"with a faint light. Flowers and small bushes seem to be getting enough light "+
"from the moss to make up for the lack of sun. The park path continues south "+
"and east and the east-west road is to the north.\n";

   dest_dir = ({"players/airborne/new/town3", "north",
	"players/airborne/new/park2", "east",
	"players/airborne/new/park4", "south", });

   items = ({"park", "The park is small, yet attracting", 
	"moss", "The moss is giving off a green glow", 
	"flowers", "Little pretty flowers",
	"bushes", "Young little bushes that have many flowers",
	"path", "The path through the park",
	"road", "The east-west road through the Trog village", });

if(!present("trog", this_object())){
object trog, lock;

  trog = clone_object("obj/monster");
  trog -> set_name("brandie");
  trog -> set_alt_name("trog");
  trog -> set_alias("girl");
  trog -> set_level(7);
  trog -> set_size(2);
  trog -> set_gender(2);
  trog -> set_short("Young trog");
  trog -> set_long("Brandie is a young Trog girl, only 400 years old.\nShe is thin, grey and short just like most other Trogs.\n");
    lock = clone_object("obj/armour");
    lock -> set_type("amulet");
    lock -> set_name("locket");
    lock -> set_alt_name("amulet");
    lock -> set_size(2);
    lock -> set_weight(1);
    lock -> set_value(50);
    lock -> set_short("A locket");
    lock -> set_long("It is a beautiful locket with a picture of an elderly Trog and an inscription that reads: 'With love always, Grandma'.\n");
    lock -> set_ac(0);
  	transfer(trog, this_object());
	transfer(lock, trog);
 trog -> init_command("powerup");
	}
}
}

init(){
::init();

  add_action("gather", "pick");
  add_action("gather", "gather");
	i = 0;
	}

gather(str){
object moss;

  if(!str){
	write("Gather what?\n");
	return 1; }
  if(str=="moss"){
    if(i<1){
	write("You pick some moss from the ground.\n");
	moss = clone_object("obj/treasure");
	moss-> set_name("moss");
	moss-> set_id("moss");
	moss-> set_light(1);
	moss-> set_short("Moss. (glowing)");
	moss-> set_long("Strange glowing green moss.\n");
	moss-> set_weight(1);
	moss-> set_value(1);
	transfer(moss, this_player());
	i += 1;
	return 1; }
   else {
	write("That must have been picked already, as it is not here.\n");
	return 1;  }
}
}
