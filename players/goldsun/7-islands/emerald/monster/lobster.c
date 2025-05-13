inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("lobster");
set_race("animal");
set_short("A sea lobster");
set_long("A sea lobster with strong claws.\n");
set_level(8);
set_gender(1);
set_wc(9);
set_ac(5);
set_spell_mess1("Lobster pinches you.\n");
set_spell_mess2("");
set_spell_dam(11);
set_chance(22);
set_size(2); 
move_object(clone_object("players/goldsun/7-islands/emerald/obj/claws"),
   this_object());
move_object(clone_object("players/goldsun/7-islands/emerald/obj/shield"),
   this_object());

}

