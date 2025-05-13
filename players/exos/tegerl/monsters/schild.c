

/* Tegerl, 9.3.1995 */
/* monsters/schild */


inherit "obj/monster";
reset(arg) 
{
    object chats;
    ::reset(arg);

    if (arg) return;

    set_name("child");
    set_alt_name("kid");
    set_race("human");
    set_short("Kid");
    set_long("A sweet child.\n"
      + "It is playing here in the streets.\n"
      + "It has nothing else to do.\n");  
/* Exos 4-26-97
    set_level(4);
Level change */
set_level(2);
    set_gender(0);
    set_aggressive(0);
}
