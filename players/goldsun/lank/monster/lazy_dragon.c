inherit "/obj/monster";

void reset(int arg)
 {
  ::reset(arg);
if (arg) return;
 set_name("lazy dragon");
 set_race("dragon");   
 set_short("A big lazy dragon");
 set_long("A big lazy cave-dragon.\n");
 set_aggressive(0);
 set_level(20+random(5));
 set_size(4);
 set_ac(4);
 set_spell_mess1("Lazy dragon cast a FIRE !\n");
 set_spell_mess2("Lazy dragon makes a hit with his TAIL !\n");
 set_spell_dam(60);
 set_chance(20);
 add_money(900+random(200));
}
init(){
 ::init();
add_action("south","south");
}
int south(){
 write("The dragon bars you the way.\n");
 return 1;
}

