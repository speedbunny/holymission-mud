inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("ruby-coloured robe");
    set_alias("holy robe");
    set_type("robe");
    set_ac(0);
    set_value(200);
    set_size(0);
    set_weight(2);
    set_short("A ruby-coloured robe");
    set_read("In the name of God! instantum illuminaris");
  } else if (!environment(environment(this_object())))
    destruct(this_object());
}

long () {
  string str;
  str = "Some holy sign embellish this ruby-coloured rope.\n";
  if (query_ac())
    str += ("It glows with a cold, blue aura.\n");
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
  if ((str != "illuminaris") && (str != "illuminaris robe") ) return 0;
  if (worn && query_worn()) {
    al = worn_by->query_alignment();
    if (al < 0) 
      write("You cannot do that in your "+worn_by->query_al_string()
           +" state.\n");
    else {
      write("The robe begins to glow in a cold blue aura.\n");
      if (al>600) set_ac(1);
      worn_by->re_wear();
    }
  } else
    write("you must first wear the robe.\n"); 
  return 1;
}

remove(str) {
  int ret;
  ret = ::remove(str);
  if (ret) {
    set_ac(0);
    write("The robe stops to glow.\n");
  }
  return ret;
}
