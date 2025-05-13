inherit "obj/weapon";
object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Sword of Frost");
 set_alt_name("sword of frost");
 set_alias("sword");
 set_short("A Sword of Frost");
 set_long("This sword has frost rimming the edge of the blade.\n");
 set_class(14);
 set_weight(3);
 set_value(2500);
 set_hit_func(this_object());
}

weapon_hit(ob) {
  string name, race, short, junk1, junk2;
  int test;
  if(target == ob) {
    tell_object(wielded_by,"Steam billows forth when you hit ");
    tell_object(wielded_by,ob->query_name()+"!\n");
    return 5;
  }
  test = 0;
  name = ob->query_name();
  if(!name) name = "blah";
  race = ob->query_race();
  if(!race) race = "blah";
  short = ob->query_short();
  if(!short) short = "blah";
  if(sscanf(name,"%sfire%s",junk1,junk2) == 2 ||
     sscanf(name,"%sFire%s",junk1,junk2) == 2 ||
     sscanf(race,"%sfire%s",junk1,junk2) == 2 ||
     sscanf(race,"%sflame%s",junk1,junk2) == 2 ||
     sscanf(short,"%slava%s",junk1,junk2) == 2 ||
     sscanf(short,"%sLava%s",junk1,junk2) == 2 ||
     sscanf(short,"%sflame%s",junk1,junk2) == 2 ||
     sscanf(short,"%sFlame%s",junk1,junk2) == 2 ||
     sscanf(short,"%sfire%s",junk1,junk2) == 2 ||
     sscanf(short,"%sFire%s",junk1,junk2) == 2)   test = 1;
  if(test) {
    target = ob;
    tell_object(wielded_by,"Steam billows forth when you hit ");
    tell_object(wielded_by,ob->query_name()+"!\n");
    return 5;
  }
  return;
}
