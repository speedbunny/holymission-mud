string alt_name;
int value;
int local_weight;
    string who;
 
query_name() { return "King Ralph's head"; }
 
 
long() {
    write("This is Good King Ralph's head. It stares back at you as\n" +
          "you look at it. You do not feel comfortable carrying it.\n");
}
 
short() {
          return "King Ralph's head";
}
 
id(str) {
          return (str == "king ralph's head" || str == "head");
} 
  
drop() { 
     call_other(this_player(),"drop_object",this_object());
} 
  
  
query_value() { 
    return 100; 
} 
  
query_weight() { return 4; } 
  
set_weight() { local_weight =5; } 
  
get() { return 1; } 
  
set_alt_name() 
{ 
    alt_name = "head"; 
} 

/* Done by Herp */

init() { enable_commands(); } 

reset(arg) {
	if(arg == 0) {
	if(this_player() && this_player()->query_level() >= 30)
	{
 log_file("animal.head",
	this_player()->query_real_name()+"("+this_player()->query_level()+
	") cloned "+
	"the head on "+ctime(time())+"\n");
	call_out("kill",2);
	}
	}
}
kill() {
	 destruct(this_object()); }
