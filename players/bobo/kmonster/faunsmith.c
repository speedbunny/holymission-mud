inherit "obj/monster";

object obj;

reset(arg) {
::reset(arg);
if (arg) return;
 set_name("faunsmith");
 set_alias("smith");
 set_short("The faunsmith");
 set_long("He's the owner of this smithy, he is a tough old man.\n"+
     "Maybe you can ask him for a list.\n");
 set_male();
 set_size(3);
 set_ac(6);
 set_race("faun");
 set_level(17);
 set_al(200);
 set_wc(10);
 set_aggressive(0);

 if(!present("hammer",this_object())) {
   obj=clone_object("/obj/weapon");
   obj->set_name("hammer");
   obj->set_short("A hammer");
   obj->set_long("This seems to be a sledgehammer.\n");
   obj->set_wc(10);
   obj->set_value(250);
   obj->set_weight(4);
   move_object(obj,this_object());
   init_command("wield hammer");
 }
}

