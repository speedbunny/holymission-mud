

/* Tegerl, 9.3.1995 */
/* monsters/hman */


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
       + "He is lucky to have his own house in this poor town.\n"
       + "But he has to work hard to get food every day.\n");  
set_level(20);
set_gender(1);
set_aggressive(0);
add_money(20);
}
