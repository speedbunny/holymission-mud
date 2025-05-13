inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("spider");
    set_alias("black spider");
    set_short("A big black spider");
    set_long("It looks as it's searching for you !!!!!!!!\n");
    set_race("insect");
    set_level(2);
    set_size(1);
    set_al(-100);
    set_aggressive(1);
    
move_object(clone_object("players/misticalla/garden/obj/fangs"),this_object());
    command("wield fangs");
  }
}
