inherit "obj/monster";

reset(arg) 

{

object chats;

::reset(arg);



if (arg) return;



set_name("weequay");

set_alt_name("creature");

set_race("elf");

set_short("Weequay");

set_long("A Weequay.\n"

       + "These nervous creatures all have the same name!\n"

       + "Little and flatnosed, it would be a shame to kill them.\n");  

set_level(10);

set_gender(1);

set_aggressive(0);

}

