/* Tegerl's first monster, coded 6.3.1995 */
/* monsters/ff */

inherit "obj/monster";
string chats;
reset(arg) 
{
::reset(arg);

if (!arg){

set_name("fishfinger");
set_alt_name("man");
set_race("human");
set_short("Fishfinger");
set_long("Mr. Fishfinger.\n"
       + "He is a fisher, but he is a merchant too.\n"
       + "He is dirty and looks at you with his tiny eyes.\n"
       + "You don't trust him and wouldn't make a deal with him anyway.\n"
       + "He has no merchandise with him. Maybe he is sold out and carries a lot of money.\n");  
set_level(15);
set_n_wc(5);
set_n_ac(9);
set_gender(1);
set_hp(500);
set_al(-30);
set_aggressive(0);
move_object(clone_object("/players/tegerl/jabberwocky/obj/knife"),
             this_object());
command("wield knife");
add_money(400+random(200));
load_chat(10,({
"Fishfinger says: Everbody fears the beast, that is good for the business.\n"
"Fishfinger looks at you.\n"
} ));
return 1;
}
}
