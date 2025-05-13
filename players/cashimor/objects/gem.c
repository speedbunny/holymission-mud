inherit "obj/treasure";

string type;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("gem");
  }
  value--;
}

set_type(str) {
string file,lines;

  type=str;
  set_alias(str);
  file=read_file("/players/cashimor/gems/"+str);
  if(!file) {
    set_alt_name("stone");
    set_short("A worthless stone");
    set_value(0);
    set_long("Try to get rid of it!\n");
    return;
  }
  lines=explode(file,"\n");
  set_short(lines[0]);
  set_value(to_int(lines[1]));
  set_long(lines[2]+"\n");
}

prevent_insert() {
  return 1;
}

drop() {
  return 1;
}

query_auto_load() {
  return "players/cashimor/objects/gem:"+type;
}

init_arg(str) {
  set_type(str);
}
