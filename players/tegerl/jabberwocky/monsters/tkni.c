/* Tegerl, 28.3.1995 */
/* monsters/tkni */

inherit "obj/monster";

reset(arg) 
{
::reset(arg);

if (!arg){

set_name("knight");
set_alt_name("man");
set_race("human");
set_short("Knight");
set_long("A really strong knight.\n"
       + "He killed all others in the tournament.\n"
       + "Why did you challenge him ? \n");  
set_level(8);
set_n_wc(9);
set_n_ac(7);
set_gender(1);
set_al(-500);
set_spell_mess1("The knight's horse hurts you badly.");
set_spell_mess2("The knight's horse hurts you badly.");
set_spell_dam(100+random(40));
set_chance(25);
set_aggressive(1);
move_object(clone_object("/players/tegerl/jabberwocky/obj/oldlanc"),
             this_object());
load_a_chat(20,({
"The knight yells: You will not win this tournament !!! \n"
} ));
}
}