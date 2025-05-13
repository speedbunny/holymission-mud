int charges;

id(str) {
 return str == "staff" || str == "staff of curing" || str == "rosewood staff";
}

short() {
 return "A Rosewood Staff";
}

long() {
 write("This sturdy staff seems to fit comfortably in your hands.\n");
 write("You feel better after just holding it.\n");
 return 1;
}

drop() { return 0; }
get() { return 1; }
query_name() { return "Staff of Curing"; }
query_value() { return 2000+((charges+1)*500); }
query_weight() { return 3; }
query_charges() { return charges; }
query_info() {
	write("This is a staff of curing. Type 'touch <player>' to heal.\n");
	return;
}

init() {
 if(environment(this_object()) != this_player()) return 1;
 add_action("do_heal"); add_verb("touch");
}

reset(arg) {
 if(arg) return 1;
 charges = 5;
}

do_heal(arg) {
 object ob;
 if(!arg) {
  write("Who do you want to touch with the staff?\n");
  return 1;
  }
  ob = present(arg, environment(this_player()));
  if(!ob) {
	write("Sorry, can't do that.\n");
	return 1;
  }
  if(charges <= 0) {
	write("The staff shivers, but nothing happens.\n");
	say(call_other(this_player(),"query_name")+" touches "+arg+" with");
	say(" a rosewood staff, but nothing happens.\n");
	return 1;
  }
  charges -= 1;
  write("You touch "+arg+" with the staff. A gentle white light\n");
  write("briefly surrounds "+arg+" and then is gone.\n");
  say(this_player()->query_name()+" touches "+arg+" with a");
  say(" rosewood staff and "+arg+" is\nsurrounded by a gentle white light.\n");
  if(this_player()->query_class_name() == "priest") {
	write("The staff warms in your healing hands.\n");
	call_other(ob, "heal_self", random(20)+80);
	tell_object(ob,"You feel better.\n");
	return 1;
   }
  call_other(ob, "heal_self", random(20)+30);
  tell_object(ob,"You feel better.\n");
  return 1;
} 
