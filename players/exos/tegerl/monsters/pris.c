/* Tegerl, 22.3.1995 */
/* monsters/pris */

inherit "obj/monster";
string chats;
reset(arg) 
{
::reset(arg);

if (!arg){

set_name("prisoner");
set_alt_name("man");
set_race("human");
set_short("Prisoner");
set_long("Prisoner.\n"
       + "He is very dirty man.\n"
       + "As you know that only murderer come in here,\n"
       + "you know why he is here.\n");  
set_level(15);
set_n_wc(10);
set_n_ac(9);
set_gender(1);
set_al(-300);
set_aggressive(1);
return 1;
}
}