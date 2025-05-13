inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("egg");
    set_short("An egg");
    set_long("A delicious looking, fresh laid egg.\n");
    set_strength(5);
    set_eater_mess("It tastes good.\n");
    set_eating_mess(" sucks out an egg and crushes it.\n");
  }
}
