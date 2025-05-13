inherit "obj/monster";

reset(arg) 

{

object chats;

::reset(arg);



if (arg) return;



set_name("jawa");

set_alt_name("creature");

set_race("human");

set_short("Jawa");

move_object(clone_object("players/redsexy/jedi/objects/jspear.c"), this_object());
    
command("wield spear");

set_long("A hooded Jawa.\n"

       + "This Jawa has come the island for the annual swap meet.\n"

       + "He will probably be carrying money or goods!.\n");  

set_level(20);

set_gender(1);

set_aggressive(0);

add_money(300);

}

