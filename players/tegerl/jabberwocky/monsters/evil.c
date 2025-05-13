/* Tegerl, 22.3.1995 */
/* monsters/evil */

inherit "obj/monster";

reset(arg) 
{
::reset(arg);

if (!arg){

set_name("evil");
set_alt_name("evil");
set_race("monster");
set_short("Evil");
set_long("Evil the thief.\n"
       + "He is very dangerous man.\n"
       + "He killed more people than you ever will know.\n"
       + "And he steals from everybody.\n");  
set_level(60);
set_n_wc(50);
set_n_ac(30);
set_gender(1);
set_al(-1000);
set_spell_mess1("Evil steps behind you and backstabs you.");
set_spell_mess2("Evil finds a vulnerably place and hurts you bad.");
set_spell_dam(120+random(60));
set_prevent_poison(0);
set_chance(25);
set_aggressive(1);
load_a_chat(20,({
"Evil yells: Meet your maker !!!!!\n"
}));
return 1;
}
}