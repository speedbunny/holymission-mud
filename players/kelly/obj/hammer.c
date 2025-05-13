inherit "obj/weapon";
 
int power;
 
reset(arg) {
 power=50;
 set_name("hammer");
 set_class(19);
 set_weight(7);
 set_value(12100);
 set_short("Thor's hammer");
 set_long("Thor's hammer is a very powerful weapon. You can throw it\n"+
    "towards your enemies. But not everybody can use it.\n");
 set_hit_func(this_object());
}
 
init() {
::init();
  add_action("throw","throw");
}
 
weapon_hit(attacker) {
 if ((wielded_by->query_dex()<15) && (random(10)>3)) {
   write("Thor's hammer seems not to be interrested in the fight.\n");
   return 0;
 }
 if ((wielded_by->query_dex()>=18) && (random(10)<4)) {
   write("The hammer crushes the bones of "+attacker->query_name()+
     " and throws "+attacker->query_objective()+" to the other end of "+
     "room.\n");
   return 50;
  }
  return 25;
}
 
throw(str) {
  object ob;
  string what,who;
  if(str) {
    sscanf(str,"%s to %s",what,who);
    if(!id(what)) return;
  }
  if(!wielded) { write("You should wield the hammer.\n");
    return 1; 
  }
  if(wielded_by->query_dex()<15) {
    write("You're to slow to do that!\n");
    return 1;
  }
  if(!who)
   ob=wielded_by->query_attack();
  else
   ob=present(lower_case(who),environment(wielded_by));
  if(!ob || !living(ob)) {
    write("Throw !? To Whom ?\n");
    return 1; }
  if(ob==wielded_by) {
    write("You don't want to do that !\n");
    return 1; }
  if(power>0) {
    hitting(ob);
    --power; }
  else  write("The hammer has lost it's magic.\n");
  return 1;
}
 
hitting(ob) {
  string name;
  name=ob->query_name();
  write("You throw the hammer towards " + name +".\n");
  write(capitalize(ob->query_pronoun())+
  " doubles over and pukes on the ground.\n");
  say(wielded_by->query_name() + " throws "+
    wielded_by->query_possessive()+" hammer towards "+ob->query_name()+
    ".\n"+capitalize(ob->query_pronoun())+"doubles over on pukes on the ground.\n");
  ob->hit_player(40);
  return 1;
}
 
