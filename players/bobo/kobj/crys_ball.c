inherit "/obj/treasure";
 
object obj;
int i;
 
reset(arg) {
if (arg) return;
 set_alias("ball");
 set_short("A crystal ball");
 set_value(2000);
 set_weight(1);
}
 
init() {
  add_action("magic","search");
}
 
magic(str) {
  if(!id(str)) return;
  write("You look deep into the ball, but you find nothing.\n");
  return 1;
}

long() {
  object obj;
  write("You look into the crystal ball and see :\n");
  obj=find_object("questsword");
  if(!obj) {
    write("A large black hole.\n");
     return 1;
  }
  if(living(environment(obj))) {
    write(environment(environment(obj))->short()+environment(obj)->query_name()+
      "carries the Holy Sword.\n");
    return 1;
  }
  write(environment(obj)->short()+" the Holy Sword lies around.\n");
  return 1;
}
