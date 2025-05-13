/* TORCH.C, This is an inherit/clone file - DO NOT COPY! */
/* 051092: Ethereal Cashimor: Added set_short, set_long and smell. */
/* 131092: Bonzo: smell changed. */
/* 240393: Ethereal Cashimor: can_light id added, out added. */
/* 260493: Ethereal Cashimor: Now uses tell_room in out_of_fuel */
/* 090693: Ethereal Cashimor: USERDOC added */
/* 310793: Galadriel: fixed error msg in prevent_insert() */

/* USERDOC:
general
This is a generic torch. It will have some good initialisations by default. The
torch can't be sold when it is lighted. Generally defined functions:
set_weight, query_weight, set_name, set_short, set_long, query_value,
query_name.
*/
#include "setlight.h"

string long_desc, short_desc;
string amount_of_fuel;
string smell_mess;
string name;
status is_lighted;
int weight,auto_light,greek_fire;

long() {
  write(long_desc);
  if(is_lighted) write("It is lit.\n");
}

reset(arg) {
  if (arg) return;
  amount_of_fuel = 1000; 
  name = "torch"; 
  is_lighted = 0; 
  weight = 1;
  short_desc = "a torch";
  long_desc = "A torch.\n";
}

/* Galadriel: now uses query_name() instead of "torch" */
prevent_insert() { 
  if(is_lighted) write("You can't put a lighted "+query_name()+" in a container.\n");
  return is_lighted; 
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

/* USERDOC:
query_is_lit
Format: i=query_is_lit()
This function returns 0 if the torch isn't lit.
*/
query_is_lit() { 
  return is_lighted; 
}

short() {
  if (is_lighted) return short_desc+" (lit)";
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

/* USERDOC:
set_smell
Format: set_smell(s)
Example: set_smell("The torch smells awful.\n");
This function sets the smell of the torch. The smell of the burning torch will
be different, though. A \n is needed at the end of the smell, unlike in rooms.
*/
set_smell(s) {
  smell_mess = s;
}

set_long(l) {
  long_desc = l;
}

/* USERDOC:
set_fuel
Format: set_fuel(i)
Example: set_fuel(2000)
This function sets the number of seconds the torch will burn.
*/
set_fuel(f) { 
  amount_of_fuel = f; 
}

/* USERDOC:
set_auto_light
Format: set_auto_light(i)
Example: set_auto_light(1)
See also: query_auto_light.
This function allows the torch to be lighted automatically, that is, without
an additional heat source. This is used to make matches and things like that.
An auto_light torch can not be lighted once extinguished. A torch will be
auto_light when i is not 0.
*/
set_auto_light(n) { 
  auto_light=n; 
}

/* USERDOC:
set_greek_fire
Format: set_greek_fire(i)
Example: set_greek_fire(1)
See also: query_greek_fire.
This function makes the torch invurnerable to water. Don't make too many
torches with this option: greek_fire torches use up much of the processortime
when they are under water. A torch will be greek fire when i is not equal to
0, preferably 1.
*/
set_greek_fire(n) { 
  greek_fire=n; 
}

/* USERDOC:
query_auto_light
Format: i=query_auto_light()
See also: set_auto_light.
This function returns if the torch can be lighted without additional help. 0
means it can't.
*/
query_auto_light() { 
  return auto_light; 
}

/* USERDOC:
query_greek_fire
Format: i=query_greek_fire()
See also: set_greek_fire.
This function returns if the torch will stay burning under water. 0 means it
won't.
*/
query_greek_fire() { 
  return greek_fire; 
}

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
    notify_fail("Light what?\n");
    return 0;
  }
  if (is_lighted) {
    notify_fail("It is already lit.\n");
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

  if(set_light(-1)==0) {
    troom("There is darkness as a " + name + " goes dark.\n");
  }
  else {
    troom("The " + name + " goes dark.\n");
  }
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
    notify_fail("But it isn't lit!\n");
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

/* USERDOC:
out
Format: out([i])
Example: out()
This function extinguishes the torch if it is given without parameter, of with
i is 0. When an argument unequal to zero is given (preferably 1) the torch will
light automagically. Remember that the torch can be detected by checking the
id with "can_light".
*/
out(arg) {
int i;

  if(!arg) {
    if(!is_lighted) return;
    if(greek_fire) return;
    i=remove_call_out("out_of_fuel");
    amount_of_fuel=i/2;
    is_lighted=0;
    extinguish("torch");
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

troom(str) {
object room;

  if(!this_player()) {
    room=environment(this_object());
  }
  else {
    room=environment(this_player());
  }
  tell_room(room,str);
}




