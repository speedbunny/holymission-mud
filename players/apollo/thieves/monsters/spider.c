inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("spider");
    set_alias("black spider");
    set_short("A big black spider");
    set_long("It looks as it's searching for you !!!!!!!!\n");
    set_race("insect");
    set_level(1);
    set_size(1);
    set_al(-100);
    set_aggressive(1);
  }
}
