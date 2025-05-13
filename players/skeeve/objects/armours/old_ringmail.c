inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("old ringmail");
    set_alias("ringmail");
    set_type("armour/arm");
    set_value(110);
    set_ac(2);
    set_weight(6);
    set_size(0);
    set_short("A old ringmail");
    set_long("This ringmail is old, rusty and injured.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}

config(tp) {
  if (tp->query_npc())
    set_size(tp->query_size());
  return this_object();
}

remove(str) {
  int ret,ac;
  if (worn_by-query_player()) {
    if (::remove(str)) {
      if (ac= armour_class()-1) {
        set_ac(ac);
        write("As you remove the "+query_name()+" some pieces broken from it.\n");
        return 1;
      } else {
        write("As you remove the "+query_name()+" it brokes totally.\n");
        destruct(this_object());
        return 1;
      }
    } else return 0;
  } else return ::remove(str);
}
