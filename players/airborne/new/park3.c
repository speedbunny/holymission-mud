inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc = 
"The path in the park bends to the south and west here. The green moss "+
"continues to light the area with its faint glow giving light to the "+
"various floral wonders around. The park remains peaceful and relaxing "+
"the wonderous smell of flowers permiates the area.\n";

   dest_dir = ({"players/airborne/new/park2", "west", 
		"players/airborne/new/park6", "south", });

   items = ({"path", "Grey cobblestone path leading through the park",
	"moss", "Strange green glowing moss",
	"green moss", "Strange green glowing moss",
	"flowers", "Exotic flowers unimaginable to surface dwellers", });

   smell = "The wonderous scent of exotic flowers";

if(!present("trog", this_object())){
 object trog;

	trog = clone_object("obj/monster");
	trog-> set_name("Bobby");
        trog-> set_level(5);
	trog-> set_alt_name("trog");
	trog-> set_gender(1);
	trog-> set_race("trog");
	trog-> set_wc(5);
	trog-> set_ac(2);
	trog-> add_money(20+random(51));
	trog-> set_short("Young Trog");
	trog-> set_long("Billy is a young Trog similar to the rest; short, grey and slim.\n");
          move_object(trog, this_object());
            }
    }
}

init(){
::init();

  add_action("pick", "pick");
  add_action("pick", "gather");
	}

pick(str){

 if(str=="flowers" || str=="flower"){
	write("They are so prettyyou decide to leave them alone.\n");
	return 1; }
 if(str=="moss" || str=="green moss"){
	write("The moss doesn't look mature enough to pick here.\n");
	return 1; }
  else {
	write("Pick what?\n");
	return 1; }
 
}

