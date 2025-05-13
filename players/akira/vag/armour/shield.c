inherit "/obj/armour";
reset(arg){
::reset(arg);

set_name("Abysal Shield");
set_alias("shield");
set_short("Abysal Shield");
set_long("This is a large shield with a what looks to be a small abyss on\n"+
         "the front of it. Shots blocked by this shield seem to sucked into\n"+
         "this abyss, never to be seen again.\n");
set_weight(3);
set_ac(3);
set_value(2000);
set_type("shield");
}
