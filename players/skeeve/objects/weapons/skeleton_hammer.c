inherit "/obj/weapon";

#define STR 0x01

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("skeleton hammer");
    set_alt_name("hammer");
    set_alias("skeleton_hammer");
    set_class(10);
    set_type(STR);
    set_value(200);
    set_weight(4);
    set_short("A heavy hammer with a bony haft");
    set_long("This is a very big hammer which looks like it has\n"
           + "slayed many enemys. There is something carved on it.\n");
    set_read("Made from a skeleton. Deathly for skeletons.\n");
    set_hit_func(this_object());
  } else if (!environment(environment(this_object())))
    destruct(this_object());
}

weapon_hit(ob) { /* The special hit function */
  int i;
  if(ob->id("skeleton")) {
    i = random(6)+random(6);/* 0 .. 10 */
    if (i>7)
      write("A skeleton bone is smashed into thousend shivers.");
    else if (i>3)
      write("The skeleton showers, but no bones are broken.\n");
    return i;
  }

  if(environment(ob)->query_env_name()=="water") {
    write("The water stops the hammer, before the "+ob->query_name()
    +" is hited.");
    return -8;
  }
  return 0;
}
