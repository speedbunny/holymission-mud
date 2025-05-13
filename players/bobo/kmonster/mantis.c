inherit "obj/monster";
 
object claw;
 
reset(arg) {
::reset(arg);
 if(arg) return;
  set_name("mantis");
  set_short("A over-sized mantis");
  set_aggressive(1);
  set_size(3);
  set_race("insect");
  set_level(10);
  set_hp(150);
  set_al(-10);
 
 if(!claw) {
 claw=clone_object("players/kelly/obj/bihitter");
 claw->set_name("claws");
 claw->set_alias("claw");
 claw->set_class(16);
 claw->set_weight(2);
 claw->set_short("A pair of claw");
 claw->set_long("The pair of claw of a mantis.\n");
 claw->set_value(620);
 claw->set_second_hit("reaches out with the other claw.\n");
 move_object(claw,this_object());
 init_command("wield claw");
 
 }
 
}
 
