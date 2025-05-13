inherit "/obj/weapon";

#define DEX 0x02
#define INT 0x08

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("harpoon");
    set_alias("harpoon");
    set_class(5);
    set_weight(2);
    set_type(DEX + INT);
    set_short("A harpoon");
    set_long("This harpoon is a special weapon for water.\n");
    set_value(1200);
    set_hit_func(this_object());
  }
}

weapon_hit(ob) {
  if(environment(ob)->query_env_name()=="water") {
    if (random (4)) {
      write("You hit the "+ob->query_name()+" with a arrow!\n");
      return (10 + random (11));
    } else
      write("The arrow stripes the "+ob->query_name()+".\n");
  return 0;
  }
}
