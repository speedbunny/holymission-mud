inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("crayfish");
set_race("fish");
set_short("A crayfish");
set_long("A red crayfish with strong tail and claws.\n");
set_level(14);
set_spell_mess1("Crayfish snatchs you.\n");
set_spell_mess2("");
set_chance(21);
set_spell_dam(26+random(9));
set_wc(15);
set_ac(10);
set_size(3);
set_al(10);
move_object(clone_object("players/goldsun/7-islands/sapphire/obj/claws"),
              this_object());     
}

