inherit "obj/treasure";

status full;

reset(arg) {
  if(arg) return;
  set_id("watering can");
  set_alias("can");
  set_short("A watering can");
  set_long("This is a watering can. If you're near water you could fill it,\n"
	+ "and of course you could water a plant with it (That's what it's for!)\n");
  set_value(50);
  set_weight(2);
}

init() {
  ::init();
  add_action("fill", "fill");
  add_action("water", "water");
}

fill(str) {
  string tmp;
  if(!id(str)) return;
  if(full) {
    write("But the watering can is already full!\n");
    return 1;
  }
  tmp=environment(this_player())->short();
  if(!tmp || (strstr(tmp, " water")==-1 && strstr(tmp, " sea")==-1)) {
    tmp=environment(this_player())->query_room("long_desc");
    if(!tmp || (strstr(tmp, " water")==-1 && strstr(tmp, " sea")==-1)) {
      write("How are you going to fill it? There's no water here!\n");
      return 1;
    }
  }
  full=1;
  write("You fill up the watering can.\n");
  return 1;
}

water(str) {
  object ob;
  if(!str || !(ob=present(str, environment(this_player())))) {
    write("No " + str + " here.\n");
    return 1;
  }
  write("You drench " + ob->short() + " in water.\n");
  full=0;
  ob->water_me();
  return 1;
}
