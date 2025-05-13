/* Tegerl, 22.3.1995 */
/* monsters/cancelor */

inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (!arg){

set_name("chancellor");
set_alt_name("man");
set_race("human");
set_short("Chancellor");
set_long("The chancellor of this country.\n"
       + "He is very fat and seems to be very strong.\n"
       + "He looks at you with distrust.\n"
       + "He has stolen all the king's treasures.\n");  
set_level(50);
set_n_wc(50);
set_n_ac(20);
set_gender(1);
set_al(-300);
set_aggressive(1);
set_spell_mess1("The chancellor hits you with all his bad power.");
set_spell_mess2("Your body seems to explode as the attack annihilates you.");
set_spell_dam(100+random(60));
set_prevent_poison(1);
set_chance(25);
add_money(10000);
load_a_chat(20,({
"The chancellor says: Leave, that is my money, leave.\n"
"You can see mountains of gold coins in his pockets.\n"
} ));
}
}
void init() {
 ::init();
 add_action("take","get");
 add_action("take","take");
}

int take(string str) {
if ((str!="pillow") && (str!="all from pillow") && (str!="all")) return 0;
write("The chancellor hinders you to take this.\n");
return 1;
}