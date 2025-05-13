inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village";
   long_desc = 
"You have entered the home of a famous Trog warrior. It is a simple house, "+
"for the simple people using it. \n";

   dest_dir = ({"players/airborne/new/town4", "west", });

if(!present("prong", this_object())){
object wa, sh, tr, sd;

   wa = clone_object("obj/monster");
   wa-> set_name("prong");
   wa-> set_alt_name("warrior");
   wa-> set_alias("trog");
   wa-> set_race("trog");
   wa-> set_gender(1);
   wa-> set_short("A trog warrior");
   wa-> set_long
("This is Prong, the Trogs most famous warrior. He is about the same height\n"+
 "as the rest of the Trogs, but he is not slender at all. In fact, he has a\n"+
 "big pot belly.\n");
   wa-> set_level(10);
   wa-> set_class(10);
   wa-> add_money(200);
   wa-> set_ac(5);
   wa-> set_str(12);
 sh = clone_object("obj/armour");
 sh-> set_type("shield/glove");
 sh-> set_alias("shield");
 sh-> set_ac(3);
 sh-> set_weight(5);
 sh-> set_size(3);
 sh-> set_value(200);
 sh-> set_short("A trog shield");
 sh-> set_long("This is the shield of the famous Trog warrior Prong.\n"
               +"It looks magical.\n");
     tr = clone_object("obj/weapon");
     tr-> set_name("trident");
     tr-> set_class(12);
     tr-> set_weight(2);
     tr-> set_value(310);
     tr-> set_short("A trident");
     tr-> set_long("The trident to Prong the famous Trog warrior.\n");
  sd = clone_object("obj/treasure");
  sd-> set_id("unicorn_saddle");
  sd-> set_name("unicorn saddle");
  sd-> set_alt_name("saddle");
  sd-> set_value(500);
  sd-> set_short("A saddle");
  sd-> set_long("A beautiful golden saddle.\n");
  sd-> set_weight(3);
    	move_object(wa, this_object());
	move_object(tr, wa);
	move_object(sh, wa);
	move_object(sd, wa);
   wa-> init_command("wield trident");
   wa-> init_command("wear shield");

	return 1;

	}
     }
}
