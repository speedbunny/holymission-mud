
string name, alias_name,read_file,read_message, short_desc, long_desc, time_dest;
int weight,time;
status wait;

query_property(str) { return str=="no_teleport"; }

short() {
    return short_desc;
}

long() {
    if (long_desc)
	write(long_desc);
    else if (read_file || read_message)
	read(name);
    else
	write("You see nothing special.\n");
}

reset(arg) {
    if (arg)
	return;
    time_dest = 20+random(60); 
    call_out("wait",time_dest * random(4+1));
    set_name("block");
    long_desc = 0;	/* Use read() if no long_desc set! */
    read_message = 0;
    read_file = 0;
    time = 0;
    weight = 1;
}
wait() {
 object ob,ob2;
  ob=first_inventory(this_object());
  ob2=environment(this_object());
  if (ob) {
  tell_object(ob2,""+ob->query_name()+" suddenly melts.\n");
    say("you suddenly begin to melt.\n");
  move_object(ob,environment(this_object())); 
  }
  destruct(this_object());
 return 1;
 }
query_container() { return 1; }

id(str) {
    return str == name || str == alias_name;
}


query_name() { return name; }
query_weight() { return weight; }
set_name(n) { name = n; }
set_short(sh) { short_desc = sh; }
set_long(long) { long_desc = long; }
set_read(str) { read_message = str; }
set_read_file(filename) { read_file = filename; }
set_weight(w) { weight = w; }
set_alias(n) { alias_name =lower_case(n); }
