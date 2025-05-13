inherit "obj/weapon";
object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Sword of Fire");
 set_alias("sword of fire");
 set_alt_name("sword");
 set_short("A Sword of Fire");
 set_long("This glowing red sword is warm to the touch.\n");
 set_class(14);
 set_weight(3);
 set_value(2000);
 set_hit_func(this_object());
}

weapon_hit(ob) {
  string name, race, short, junk1, junk2;
  int test;
  if(target == ob) {
    tell_object(wielded_by,"Fire plays along the blade when you hit ");
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
  if(sscanf(name,"%sice%s",junk1,junk2) == 2 ||
     sscanf(name,"%sIce%s",junk1,junk2) == 2 ||
     sscanf(name,"%sfrost%s",junk1,junk2) == 2 ||
     sscanf(name,"%sFrost%s",junk1,junk2) == 2 ||
     sscanf(name,"%ssnow%s",junk1,junk2) == 2 ||
     sscanf(name,"%sSnow%s",junk1,junk2) == 2 ||
     sscanf(race,"%swater%s",junk1,junk2) == 2 ||
     sscanf(race,"%sice%s",junk1,junk2) == 2 ||
     sscanf(race,"%sfrost%s",junk1,junk2) == 2 ||
     sscanf(race,"%ssnow%s",junk1,junk2) == 2 ||
     sscanf(short,"%ssnow%s",junk1,junk2) == 2 ||
     sscanf(short,"%sSnow%s",junk1,junk2) == 2 ||
     sscanf(short,"%sice%s",junk1,junk2) == 2 ||
     sscanf(short,"%sIce%s",junk1,junk2) == 2 ||
     sscanf(short,"%sfrost%s",junk1,junk2) == 2 ||
     sscanf(short,"%sFrost%s",junk1,junk2) == 2)   test = 1;
  if(test) {
    target = ob;
    tell_object(wielded_by,"Fire plays along the blade when you hit ");
    tell_object(wielded_by,ob->query_name()+"!\n");
    return 5;
  }
  return;
}
