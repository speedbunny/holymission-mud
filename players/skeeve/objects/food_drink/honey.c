inherit "obj/food";

reset (arg) {
  ::reset (arg);
  if (!arg) {
    set_name("honey");
    set_alias("sweet honey");
    set_short("A small peace of sweet honey");
    set_long("Its a small peace of dark, sweet honey.\n"
            +"It smells very good and will give you some power.\n");
    set_value(50);
    set_weight(1);
    set_strength(8); 
    set_eater_mess("It tastes very sweet. You feel stronger.\n");
    set_eating_mess(" eats a piece of honey.\n");
  }
}

get () {
  object bees;
  if (environment(this_object()) 
     && bees = present("bees",environment(this_object()))) {
    bees->attack_object(this_player());
    return 0;
  } else 
    return 1;
}
