/* Tegerl, 14.3.1995 */
/* monsters/fass */

inherit "obj/monster";
string chats;
reset(arg) 
{
::reset(arg);

if (!arg){

set_name("fasstaubis");
set_alt_name("man");
set_race("human");
set_short("Fasstaubis");
set_long("Fasstaubis.\n"
       + "He used to be a barrelmaker. But here in town he couldn't find a job.\n"
       + "So he became a beggar. He didn't get much money, till today.\n"
       + "Yes, today he had a brilliant idea.\n"
       + "Today he cut of his foot and now he gets money enough.\n");  
set_level(15);
set_n_wc(5);
set_n_ac(9);
set_gender(1);
set_hp(500);
set_al(130);
set_aggressive(0);
move_object(clone_object("/players/tegerl/jabberwocky/obj/knife"),
             this_object());
add_money(300+random(200));
load_chat(20,({
"Fasstaubis says: I couldn't get a job here. But today I got it.\n"
"Fasstaubis says: Let me cut your foot too, then we can group.\n"
} ));
return 1;
}
}