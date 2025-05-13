inherit "/players/whisky/genobj/real_weap";


reset(arg) {
  ::reset();
  if (arg) return 1;
  
    set_name("sword");
    set_alias("holy sword");
    set_short("The Holy sword");
    set_long("A very strong sword, with a strange glance.\n");
    set_class(15);
    set_level(10);
    set_use(1400);
    set_hit_func(this_object());
    set_weight(2);
    set_value(775);
return 1;
}
    weapon_hit(ob) {
    if (ob->query_alignment() <= 0) { 
    write("********************************************\n\n"+
          "    T H E  S T R I K E  I S  T R U E \n\n"+ 
          "********************************************\n");
    say(this_player()->query_name()+" trusts the holy sword awfully against "+
        ob->query_name()+".\n");
    return 8; 
}
}
