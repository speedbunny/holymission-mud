#define TP this_player()
#define TPN TP->query_name()
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);

if (arg) return;
  set_name("flame");
  set_alias("demonflame");
  set_short("A demonflame");
  set_long("The weapon of Gods !!!!"+
           "It looks like a big Katana.\n");
  set_class(10);
  set_weight(4);
  set_value(10000000);
  set_hit_func(this_object());
}

weapon_hit(ob) {

  switch(random(5)) {
    case 0:
    tell_room(environment(TP),TPN+" "+
    "burns "+ob->query_name()+" to ashes \n");
    return random(5);
    case 1:
    tell_room(environment(TP),TPN+" "+
    "slashes "+ob->query_name()+" to austrian jam \n");
    return random(10);
    case 2:
    tell_room(environment(TP),TPN+" "+
    "cuts off the rips from "+ob->query_name()+"\n");
    return random(15);
    case 3:
    tell_room(environment(TP),TPN+" "+
    "tears off "+ob->query_name()+" liver \n");
    return random(20);
    case 4:
    tell_room(environment(TP),TPN+" "+
    "smashes off "+ob->query_name()+" limbs \n");
    return random(25);
    }
   return 1;
  }
 
