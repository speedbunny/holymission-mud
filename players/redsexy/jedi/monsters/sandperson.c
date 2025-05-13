inherit "obj/monster";

void reset( int arg) 

{

::reset(arg);



if (arg) return;

set_name("sandperson");

set_alt_name("sandman");

set_race("human");

set_short("Sandperson");

move_object(clone_object("players/redsexy/jedi/objects/jspear.c"), this_object());
    
command("wield spear");

set_long("This is one of the sandpeople who are notorious fighters and\n"

       + "easy to anger.  These people kill for fun, and it\n"

       + "looks as if they may want to kill you!\n");  

set_gender(1);

set_level(25);

add_money(1000);

set_aggressive(1);


}