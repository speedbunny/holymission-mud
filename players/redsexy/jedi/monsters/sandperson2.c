inherit "obj/monster";

void reset( int arg) 

{

::reset(arg);



if (arg) return;

set_name("sandperson");

set_alt_name("sandman");

set_race("human");

set_short("Sandperson");

set_long("This is one of the sandpeople who are notorious fighters and\n"

       + "easy to anger. This guy looks kind of placid, though\n"

       + "and you have a feeling he may just be here to shop.\n");  

set_gender(1);

set_level(25);

add_money(1000);


}