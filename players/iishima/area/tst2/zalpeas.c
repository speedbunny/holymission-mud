inherit "obj/monster";

object shovel;

reset(){
::reset();
set_name("zalpur peasant");
set_level(5);
set_alias("peasant");
set_short("A Zalpur peasant");
set_long("The Zalpur Peasant is barely dressed.  He is covered in thin, ragged clothes\n"+
         "that seem like they have not been changed in weeks.  He has a shovel in his\n"+
         "hands.\n");
set_race("Zalpur");
set_hp(90);
set_aggressive(0);
set_gender(1);
}
