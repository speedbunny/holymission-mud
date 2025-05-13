/*
 * This is a generic torch.
 * It will have some good initialisations by default.
 * The torch can't be sold when it is lighted.
 * TORCH version 2: Additional restrictions in the light routine!
 *       version 3: Extinguishes in water!
 * 051092 Modified by Ethereal Cashimor.
 *       version 4: Now has set_short() and set_long()
 *       version 5: Now has a smell command as well.
 * 131092 Modified by Hot Bonzo.
   240393 Modified by Ethereal Cashimor
         version 6: All torches have id "can_light" and the function out has
                    been extended to light torches as well (optional argument
                    1).
 */

string long_desc, short_desc;
string amount_of_fuel;
string smell_mess;
string name;
status is_lighted;
int weight,auto_light,greek_fire;

long() {
  write(long_desc);
  if(is_lighted) write("It's lighted.\n");
}

reset(arg) {
  if (arg) return;
  amount_of_fuel = 2000; 
  name = "torch"; 
  is_lighted = 0; 
  weight = 1;
  short_desc = "a torch";
  long_desc = "A torch.\n";
}

prevent_insert() { 
  if(is_lighted) write("You can't put a lighted torch in a container.\n");
  return is_lighted; 
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

query_is_lit() { return is_lighted; }

short() {
  if (is_lighted) return short_desc+" (lighted)";
  return short_desc;
}

set_name(n) {
  name = n;
  short_desc = n;
  long_desc = capitalize(n)+".\n";
}

set_short(s) {
  short_desc = s;
  long_desc = capitalize(s)+".\n";
}

set_smell(s) {
  smell_mess = s;
}

set_long(l) {
  long_desc = l;
}

set_fuel(f) { amount_of_fuel = f; }
set_auto_light(n) { auto_light=n; }
set_greek_fire(n) { greek_fire=n; }
query_auto_light() { return auto_light; }
query_greek_fire() { return greek_fire; }

init() {
  add_action("light", "light");
  add_action("extinguish", "extinguish");
  add_action("smell","smell");
}

smell(str) {
  if(!id(str)) {
    notify_fail("Smell what?\n");
    return 0;
  }
  say(this_player()->query_name()+" smells a "+name+".\n");
  write("You smell the "+name+".\n");
  if(smell_mess)
    write(smell_mess);
  else
    write("It smells like a "+name+".\n");
  if(is_lighted)
  {
    write("You start to cough.\n");
    say(this_player()->query_name()+" starts to cough.\n");
  }
  return 1;
}

light(str) {
  if (!str || str != name) {
    /* notify_fail("Light what?\n"); */
    return 0;
  }
  if (is_lighted) {
    notify_fail("It is already lighted.\n");
    return 0;
  }
  if((!auto_light)&&(!present("lighted_torch",this_player()))&&
   (!environment(this_player())->query_property("has_fire"))) {
    notify_fail("You have nothing to light it with!\n");
    return 0;
  }
  if(environment(this_player())->query_env_name()=="water") {
    if((greek_fire!=1)&&(environment(this_player())->query_danger())) {
      notify_fail("You can't light it when immersed in water!\n");
      return 0;
    }
  }
  if(environment(this_player())->query_property("has_fire")) {
     environment(this_player())->light_text(name);
  }
  is_lighted = 1;
  call_out("out_of_fuel", amount_of_fuel * 2);
  if (set_light(1) == 1) {
    write("You can see again.\n");
    say(call_other(this_player(), "query_name") +
    " lights a " + name + "\n");
  } else
    write("Ok.\n");
  amount_of_fuel = 0;
  return 1;
}

out_of_fuel() {
object ob;

  if (set_light(-1) == 0)
    say("There is darkness as a " + name + " goes dark.\n");
  else
    say("The " + name + " goes dark.\n");
  destruct(this_object());
}

id(str) {
  if((is_lighted)&&(str=="lighted_torch")) return 1;
  if(str=="can_light") return 1;
  return str == name;
}

query_value() {
  return amount_of_fuel/100;
}

get() { return 1; }

extinguish(str) {
int i;

  if (str && !id(str)) {
    notify_fail("Extinguish what?\n");
    return 0;
  }
  if (!is_lighted) {
    notify_fail("But it isn't lighted!\n");
    return 0;
  }
  i = remove_call_out("out_of_fuel");
  if (i == -1) {
    write("Error.\n");
    return 1;
  }
  amount_of_fuel = i/2;
  is_lighted = 0;
  if (set_light(-1) <= 0) {
    write("It turns dark.\n");
    say(call_other(this_player(), "query_name") +
      " extinguishes the only light source.\n");
  } else {
    write("Ok.\n");
  }
  if(auto_light) destruct(this_object());
  return 1;
}

out(arg) {
int i;

  if(!arg) {
    if(!is_lighted) return;
    if(greek_fire) return;
    i=remove_call_out("out_of_fuel");
    amount_of_fuel=i/2;
    is_lighted=0;
    set_light(-1);
    write("Your "+name+" extinguishes.\n");
  }
  else {
    if(is_lighted) return;
    if(greek_fire==-1) return;
    is_lighted=1;
    call_out("out_of_fuel",amount_of_fuel*2);
    set_light(1);
    write("Your "+name+" lights.\n");
    amount_of_fuel=0;
  }
}

query_name() { return name; }
