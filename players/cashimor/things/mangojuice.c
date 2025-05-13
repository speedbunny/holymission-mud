inherit "obj/soft_drink";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("mangojuice");
    set_short("Some mangojuice");
    set_long("This looks like some fresh mangojuice...\n");
    set_weight(2);
    set_strength(15);
    set_drinker_mess("It tastes very good!\n");
    set_drinking_mess(" seems to enjoy a glass of mango juice.\n");
    set_empty_container("glass");
  }
}
