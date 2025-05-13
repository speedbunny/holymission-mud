inherit "players/akira/fun/ngp7.c";
reset(arg){
::reset(arg);
set_name("Juicer Assassin's Rifle");
set_alias("rifle");
set_short("Juicer Assassin's Rifle");
set_long("You have never seen a weapon like this before. It looks like\n"+
         "a crossbow with out the string. It is kind os heavy and makes\n"+
         "a strange humming noise.\n");
set_class(15);
set_weight(8);
set_value(1000);
set_max_shots(30);
set_shots(30);
set_max_salvo(2);
set_wc_per_shot(15);
set_sound("BLAST! A shot fires from the rifle.\n");
set_value_per_shot(2);
}
