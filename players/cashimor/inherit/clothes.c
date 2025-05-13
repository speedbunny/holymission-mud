inherit "obj/armour";

string look,what;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_class(0);
    set_info("Clothes.");
    set_read("Do not wash at temperatures above 40 degrees celcius.\n");
  }
}

set_look(s) {
  look=s;
}

query_look() {
  return look;
}

extra_look() {
  if(!worn_by) return 0;
  return worn_by->query_pronoun()+" "+look;
}

id(str) {
  return str=="clothes" || str==name || str==alias || str==type ;
}
