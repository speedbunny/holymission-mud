inherit "obj/treasure";

int power,number;

reset(arg) {
  if(!arg) {
    set_name("arrow");
    set_value(1);
    set_weight(1);
    set_number(1);
    set_power(1);
  }
}

short() {
  if(number>1) {
    return number+" "+alias_name;
  }
  return capitalize(name);
}

set_name(s) {
  name=s;
  alias_name=s+"s";
}

set_power(i) {
  power=i;
}

query_power() {
  return power;
}

set_number(i) {
  number=i;
}

query_number() {
  return number;
}

reduce_number() {
  number=number-1;
  if(!number) {
    write("You're out of ammo!\n");
    destruct(this_object());
    return;
  }
}

query_value() {
  return value*number;
}

query_weight() {
  return local_weight*number;
}
