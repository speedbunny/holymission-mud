

/* Tegerl, 10.3.1995 */
/* monsters/pewoman */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("peasant woman");
set_alt_name("woman");
set_race("human");
set_short("peasant Woman");
set_long("A peasant woman.\n"
       + "She seems to be very anxious.\n"
       + "She left the farm because the monster destroyed the fields.\n"
       + "She wants to start a new life in town.\n");  
set_level(10);
set_gender(2);
set_al(60);
}
