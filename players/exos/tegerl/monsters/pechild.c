

/* Tegerl, 9.3.1995 */
/* monsters/pechild */


inherit "obj/monster";
reset(arg) 
{
    object chats;
    ::reset(arg);

    if (arg) return;

    set_name("peasant child");
    set_alt_name("kid");
    set_race("human");
    set_short("peasant's Kid");
    set_long("A sweet child.\n"
      + "It looks around anxiously and doesn't say a word.\n"
      + "It left the farm with its parents.\n");  
    /* Exos 4-26-97
    set_level(4);
Level Change */
    set_level(2);
    set_gender(0);
    set_aggressive(0);
}
