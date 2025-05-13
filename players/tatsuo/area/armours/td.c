inherit "obj/weapon";
int charges;

reset(arg) {
  if(arg) return;
  set_name("poison dagger");
  set_alias("dagger");
  set_short("A poison dagger");
  set_class(11);
  set_hit_func(this_object());
  set_type(2);
  charges=8;
}

init(){
  ::init();
    add_action("repoison","repoison");
    add_action("tester","tester");
}

int tester(string str) {
  object dest;
  int i;
    if (dest=env(this_player())->query_room("dest_dir")) {
      printf("Obvious exits:\n");
      for (i=0;i<sizeof(dest);i+=2)
	printf("%-10s -   %s\n",capitalize(dest[i+1]),dest[i]->short());
    }
  else printf("No obvious exits.\n");
  if (dest=env(this_player())->query_room("hidden_dir")) {
    printf("UnObvious exits:\n");
    for (i=0;i<sizeof(dest);i+=2)
      printf("%-10s -   %s\n",capitalize(dest[i+1]),dest[i]->short());
  }
  else printf("No UnObvious exits.\n");
  return 1;  
}


long(str) {
  if(!id(str)) return;
  write("A poison dagger. ");
  switch(charges) {
    case 0:
	write("It looks as if there is no poison on it.\n");
	break;
    case 1..5:
	write("It looks as if there is some poison left on it.\n");
	break;
    case 6..10:
	write("It looks pretty well smeared with poison.\n");
	break;
      case 10..20:
	write("There is ALOT of poison smeared on the dagger.\n");
    default:
	write("It looks a superb weapon, but only if you're a thief!\n");
	break;
  }
}
query_value() { return 500 + charges * 3; }

weapon_hit(ob) {
  if(!charges || random(4) || wielded_by->query_guild()!=1) return;
  charges--;
  write("You sneak past " + ob->query_name() + "'s defences and stab him with the dagger!\n");
  ob->add_poison(charges/2);
  return 50+random(charges*10);
}

int repoison(string arg){
  object pobj;
  string pstr, wstr;
  sscanf(arg,"%s with %s",wstr, pstr);
  if(pobj = present(pstr)) {
    charges=charges + pobj->query_strength();
    write("Poison level is now "+charges+"\n");
    return 1;
  }
  write("That is not poison.");
  return 1;
}









