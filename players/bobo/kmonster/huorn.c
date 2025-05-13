inherit "obj/monster";
 
reset(arg) {
 object br;

 ::reset(arg);
 if(arg) return;
 set_name("huorn");
 set_level(20);
 set_hp(3000);
 set_al(-250);
 set_race("ent");
 set_size(5);
 set_short("A huorn");
 set_long("It looks like a tree, but it lives.\n");
 set_ac(35);
 set_wc(35);
 set_aggressive(1);
 set_spell_mess1("The huorn swings around with a branch.");
 set_spell_mess2("The huorn smashes branch on your head.");
 set_chance(30);
 set_spell_dam(100);

 if(!present("branch")) {
   br=clone_object("obj/weapon");
   br->set_name("branch");
   br->set_short("A branch");
   br->set_long("This is a sturdy branch from an ent.\n");
   br->set_class(20);
   br->set_type(1);
   br->set_two_handed();
   br->set_weight(50);
   move_object(br,this_object());
   init_command("wield branch");
 }
}
 
 
 
