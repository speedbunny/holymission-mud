

/* Tegerl, 8.3.1995 */
/* monsters/bmaker */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("barrelmaker");
set_alt_name("man");
set_race("human");
set_short("Barrelmaker");
set_long("An old barrelmaker.\n"
       + "He is a very old man, and he seems to be very ill.\n"
       + "He lies in his bed and appears to be dying.\n");  
set_level(1);
set_n_wc(1);
set_n_ac(0);
set_gender(1);
set_hp(20);
set_al(70);
set_aggressive(0);
add_money(4);
load_chat(20,({ 
"The barrelmaker says: Stay here, make barrels, don't try to kill the monster.\n"
} ));
return 1;
}
