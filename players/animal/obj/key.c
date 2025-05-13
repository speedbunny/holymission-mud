/* Changed by Ethereal Cashimor, 260393, if(!arg) in reset */
/* set_own_name() is used to set the name now, because 
   this_player() isn't always defined in reset(arg) */
inherit "obj/treasure";
 
string name;
int number;
 
set_own_name() {
  name=this_player()->query_name();
}
get()
{
  if (this_player() && this_player()->query_real_name() != name)
     return 0;
  return 1;
}
 
drop() {
	return 1;
}
 
query_auto_load() {
	return "players/animal/obj/key:"+value+":"+number;
}

init_arg(str) {
	sscanf(str, "%d:%d", value,number);
	if("players/animal/closed/lobby"->query_renter(number) !=
	capitalize(this_player()->query_real_name()))
	call_out("kill",2,this_player());
}

kill(me) { me->add_money(value);
	tell_object(me,"You find out yer cabin is gone!\n"+
	"You have been reimbursed->  "+value+"\n");
	write_file("/players/animal/shops/reims",me->query_real_name()+" got "+value+" coins.\n");
     call_out("dest",2);
}

dest() {  destruct(this_object());  }


id(str) { return str == "cabin key" || str == "key"; }
reset(arg)
{
  string text;
  if(!arg) return;
  set_long("This is a key to a cabin in Cabin Village.\n");
  set_alias("key");
}
 
query_number() { return number; }
set_value(i) {
  if (this_player() && this_player()->query_real_name() != name)
     return 0;
  value = i;
  return value;
}
 
set_number(i) {
  if (this_player() && this_player()->query_real_name() != name)
     return 0;
  number = i;
  return number;
}
 
short() {
	int time;
	time="players/animal/closed/lobby"->query_ttimer(number);
     return "The key to Cabin #"+number+" time left: "+time;
}
 

