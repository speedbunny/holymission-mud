inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("wooden shield");
    set_alias("holy shield");
    set_type("shield");
    set_ac(0);
    set_value(500);
    set_size(0);
    set_weight(3);
    set_short("A wooden shield");
    set_read("In the name of God! instantum illuminaris");
  } else if (!environment(environment(this_object())))
    destruct(this_object());
}

long () {
  string str;
  str = "This wooden shield belongs to a holy druid.\n";
  if (query_ac())
    str += "This shield glows with a cold, blue aura.\n";
  return str;
}

init () {
  ::init();
  add_action("instantum","instantum");
}

id_quest(arg) {
  return arg == "holy_druid";
}

instantum(str) {
  int al;
  if ((str != "illuminaris") && (str != "illuminaris shield") ) return 0;
  if (worn && query_worn()) {
    if ((al= worn_by->query_alignment()) < 0) 
      write("You cannot do that in your "+worn_by->query_al_string()
           +" state.\n");
    else {
      write("The shield begins to glow in a cold blue aura.\n");
      if (al>3000) set_ac(2);
      else if (al>300) set_ac(1);
      worn_by->re_wear();
    }
  } else
    write("you must first wear the shield.\n"); 
  return 1;
}

remove(str) {
  int ret;
  ret = ::remove(str);
  if (ret) {
    set_ac(0);
    write("The shield stops to glow.\n");
  }
  return ret;
}
