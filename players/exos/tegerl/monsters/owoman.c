

/* Tegerl, 8.3.1995 */
/* monsters/owoman */


inherit "obj/monster";
reset(arg) 
{
object chats;
::reset(arg);

if (arg) return;
set_name("old woman");
set_alt_name("woman");
set_race("human");
set_short("old Woman");
set_long("An old woman.\n"
       + "She seems to be very sad.\n"
       + "She only looks at that ill old man in the bed.\n");  
set_n_wc(3);
set_n_ac(1);
set_gender(2);
set_hp(90);
set_al(70);
set_aggressive(0);
set_level(3);
add_money(15);
}
