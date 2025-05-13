

/* Tegerl, 8.3.1995 */
/* monsters/preacher */


inherit "obj/monster";
reset(arg) 
{
object chats;
::reset(arg);

if (arg) return;

set_name("preacher");
set_alt_name("man");
set_race("human");
set_short("Preacher");
set_long("An old Preacher.\n"
       + "He seems to be bored.\n"
       + "It seems as if he wants the old man to die soon,\n"
       + "so that he can leave again.\n");  
set_n_wc(5);
set_n_ac(10);
set_gender(1);
set_hp(250);
set_al(70);
set_aggressive(0);
set_level(3);
add_money(10);
}
