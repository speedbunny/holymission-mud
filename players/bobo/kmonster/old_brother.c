inherit "obj/monster";
object obj;
reset(arg) {
 ::reset(arg);
 set_name("man");
 set_level(19);
 set_size(3);
 set_hp(300);
 set_al(1000);
 set_short("A old man");
 set_long("This old man is obviously the only living person in this "+
   "cloister.\n");
 set_ac(30);
 set_wc(5);
 set_aggressive(0);
 set_spell_mess1("Why do you do that ?");
 set_spell_mess2("Help !");
 set_chance(20);
 
 obj=clone_object("players/kelly/obj/crux");
 move_object(obj,this_object());
}
 
 
init () {
 ::init();
 init_command("wear crux");
}
 
