

/* Tegerl, 9.3.1995 */
/* monsters/hman */


inherit "obj/monster";
reset(arg) 
{
object chats;
::reset(arg);

if (arg) return;

set_name("housewife");
set_alt_name("woman");
set_race("human");
set_short("Housewife");
set_long("A housewife.\n"
       + "She does her best to protect her family.\n"
       + "She is a good mother.\n");  
set_level(10);
set_gender(2);
set_aggressive(0);
}
