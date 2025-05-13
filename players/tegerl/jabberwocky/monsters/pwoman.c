

/* Tegerl, 10.3.1995 */
/* monsters/pwoman */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("poor woman");
set_alt_name("woman");
set_race("human");
set_short("poor Woman");
set_long("A poor woman.\n"
       + "She is desperate.\n"
       + "She really owns nothing.\n"
       + "She wants to start a new life in town.\n");  
set_level(10);
set_gender(2);
set_al(40);
}
