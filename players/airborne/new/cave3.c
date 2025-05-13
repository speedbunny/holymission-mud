inherit "room/room";
object mon, boot, kni, sign;

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog caves";
   long_desc = 
"The tunnel ends at this wide cliff underground. The cliff hangs over what "+
"looks to be a small village of sorts. The surface of the cliff looks like "+
"it would make a rough climb and should only be tried with the right "+
"equipment.\n";

   dest_dir = ({"players/airborne/new/cave2", "north" });

   items = ({"tunnel", "The tunnel leads north through the stone", 
	"cliff", "A cliff hanging over an underground creavas",
	"village", "You are too far to notice details, however you can see"+
		   " many small buildings" });

   smell = "Musty still";

if(!present("humanoid", this_object())){
   mon = clone_object("obj/monster");
   mon ->set_name("humanoid");
   mon ->set_alt_name("trog");
   mon ->set_alias("small humanoid");
   mon ->set_race("trog");
   mon ->set_size(3);
   mon ->set_level(5);
   mon ->set_gender(1);
   mon ->set_short("A small humanoid");
   mon ->set_long("A small grey skinned humanoid about three feet tall.\n");
   mon ->add_money(75);
     move_object(mon, this_object());
  boot = clone_object("obj/armour");
  boot ->set_type("boot");
  boot ->set_size(3);
  boot ->set_value(10);
  boot ->set_weight(1);
  boot ->set_name("boots");
  boot ->set_alt_name("climbing boots");
  boot ->set_id("climbing boots");
  boot ->set_ac(1);
  boot ->set_alias("boots");
  boot ->set_short("Climbing boots");
  boot ->set_long("A pair of boots with small spikes in the sole used for climbing\n");
      move_object(boot, mon);
   kni = clone_object("obj/weapon");
   kni ->set_name("climbing spike");
   kni ->set_alt_name("spike");
   kni ->set_class(5);
   kni ->set_weight(1);
   kni ->set_value(10);
   kni ->set_short("A spike");
   kni ->set_long("A long spike used to help climbing");
       move_object(kni, mon);
   mon ->init_command("wear boots");
   mon ->init_command("wield spike");
	}

if(!present("sign", this_object())){

   sign = clone_object("obj/treasure");
   sign-> set_name("sign");
   sign-> set_id("sign");
   sign-> set_short("A sign");
   sign-> set_long("A small sign that reads:\n\n Please do not jump!\n");
   sign-> set_read("\n\nPlease do not jump!\n");
   sign-> set_weight(1000);
   sign-> set_value(0);
     move_object(sign, this_object());
  	}

   }
}

init(){
 ::init();
   
   add_action("down", "down");
   add_action("jump", "jump");
	}

down(){
  if((present("climbing spike", this_player())) && (present("climbing boots", this_player()))){
    write("You climb down with grace.\n");
    this_player()->move_player("down#players/airborne/new/town1");
	return 1; }
  else {
    write("You fall down the cliff !!\n");
    this_player()->hit_player(100+random(50));
    this_player()->move_player("falling down#players/airborne/new/town1");
    return 1; }
}
     
jump(){
   write("You leap off the cliff in an act of bravery.. or stupidity...\n");
   shout(this_player()->query_name()+" just commited suicide.\n");
   this_player()->move_player("committing suicide#players/airborne/new/town1");
   this_player()->hit_player(700);
   return 1; }
