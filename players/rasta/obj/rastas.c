
object me, target;
  object victem;
 int SP_COST;
string my_name;
 string what;
int my_level;
int shield_amount;
  int tele_count;
int can_blast, damage;

id(str) {
 return str == "rasta_soul";
}

short() { return; }

long() {
 write("rasta force tool.\n");
}

drop() { return 1; }
get() { return 1; }

reset(arg) {
  damage = 0;
  target = 0;
  can_blast = 1;
}
  
init() {
  me = this_player();
  my_name = me->query_name();
  my_level = me->query_level();
  add_action("do_force"); add_verb("control");
}
  do_force(action){
    string name,nothing;
  SP_COST = 0;
  sscanf(action,"%s %s",name,what) == 2 ||
  sscanf(action,"%s to %s",name,what) == 2;
    if(!name){
  write("Control who???\n");
	return 1;
    }
    victem = find_player(name);
    if(!victem){
	write(capitalize(name)+" was not found,\n");
    }
    else{
	if(victem==this_player()){
    write("You can do the task without forcing yourself!\n");
	    return 1;
	}
 }
	if(victem->query_level()<1000)
	  write(capitalize(name)+" is under your control!\n");
	else{
	    write(capitalize(name)+" is a wizard, and may not be "+
		  "controlled!\n");
	    victem = 0;
  return 1;
	}
    name = capitalize(victem->query_real_name());
    if(what=="quit"
       ||sscanf(what,"drop %s",nothing)==1
       ||sscanf(what,"give %s",nothing)==1){
   write("Not even you can master anothers mind that way!\n");
	return 1;
    }
    if(this_player()->query_spell_points()>=SP_COST){
     say(name+ "is being controlled!\n");
    command(what,victem);
    write("You commanded "+name+" to "+what+"\n");
   this_player()->add_spell_points(-SP_COST);
    }
    else
      write("You are too drained to accomplish the deed.\n");
    return 1;
}
