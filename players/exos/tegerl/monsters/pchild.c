

/* Tegerl, 9.3.1995 */
/* monsters/pchild */


inherit "obj/monster";
reset(arg) 
{
    object chats;
    ::reset(arg);

    if (arg) return;

    set_name("poor child");
    set_alt_name("kid");
    set_race("human");
    set_short("poor Kid");
    set_long("A sweet child.\n"
      + "It doesn't own anythink. Will you give some coins to it ?\n"
      + "It came here with its parents to find protection and food in town.\n");  
    /* Exos 4-26-97
    set_level(4);
    Level Change */
    set_level(2);
    set_gender(0);
    set_aggressive(0);
}
