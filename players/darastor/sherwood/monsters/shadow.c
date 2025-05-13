inherit "/obj/monster";
int i;
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("shadow");
set_race("shadow");
set_short("Forest dark shadow");
set_long("Forest dark shadow.\n"
         +"It is a creature made by your evil actes.\n");
set_wc(12);
set_ac(3);
set_al(-500);
set_aggressive(1);
set_level(20);  
set_spell_mess1("");
set_spell_mess2("The shadow flies through your body.");
set_chance(15);
set_spell_dam(50);
set_size(3);
set_dead_ob(this_object());
}

monster_died(ob){
 i=this_player()->query_money();
 if (i>2000) i=2000;
 this_player()->add_money(i);
 write("Ok.\n");
 write("You find your money.\n");
 say(this_player()->query_name()+" takes the coins from the corpse.\n");
 }
