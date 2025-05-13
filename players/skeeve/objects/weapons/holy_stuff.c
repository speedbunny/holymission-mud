inherit "/obj/weapon";

#define CHR 0x20

int count;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("stuff");
    set_alt_name("wooden stuff");
    set_alias("holy_stuff");
    set_class(6);
    set_type(CHR);
    set_value(1000);
    set_short("A wooden stuff");
    set_read("In the name of God! instantum illuminaris");
    set_weight(3);
    set_hit_func(this_object());
    count = 0;
  } else if (!environment(environment(this_object())))
    destruct(this_object());
}

long () {
  string str;
  str ="This wooden stuff belongs to the holy druid.\n"
      +"There a some runes engraved on it.\n";
  if (count)
    str +="It glows with a cold, blue aura.\n";
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
  if ((str != "illuminaris") && (str != "illuminaris stuff")) return 0;
  if (query_wield()) {
    al = wielded_by->query_alignment();
    if (al<0) 
      write("You cannot do that in your demonic alignment.\n");
    else {
      for (count=0;al > 0;al>>=1)
        count++; 
      write("The stuff begins to glow in a cold blue aura.\n");
    }
  } else
    write("you must first wield the stuff.\n"); 
  return 1;
}

weapon_hit(ob) {
  int al,bonus;
  al = -ob->query_alignment();
  if (count) {
    for (bonus = 0;al>0;al >>= 1)
      bonus++;
    if (wielded_by->query_player()){
      count--;
      write ("A blue flash springs from the stuff against the "+ob->query_name()+".\n");
      say("A blue flash springs from the stuff against "+ob->query_name()+
       "\n as "+wielded_by->query_name() +"uses the stuff.\n");
    }
  }
  return count + bonus;
}
