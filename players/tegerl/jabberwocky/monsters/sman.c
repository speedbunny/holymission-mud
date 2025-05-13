

/* Tegerl, 9.3.1995 */
/* monsters/sman */


inherit "obj/monster";
reset(arg) 
{
object chats;
::reset(arg);

if (arg) return;

set_name("inhabitant");
set_alt_name("man");
set_race("human");
set_short("Inhabitant");
set_long("A town inhabitant.\n"
       + "He seems to be very busy. Maybe he has a job to do.\n"
       + "He doesn't care about the things happening around.\n");  
set_level(20);
set_gender(1);
set_aggressive(0);
add_money(20);
}
