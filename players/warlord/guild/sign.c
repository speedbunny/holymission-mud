
string  what;

set_what(n) {  what=n; }

id(arg) { return arg=="powerfield"; }

short() {
  if (what) 
     return "You get the feeling: "+what; 
  else
    return "An empty sign";
    }

/* just to be sure */

get() { return; }

drop() { return 1; }

init() {
  if (this_player()->query_real_name()!="whisky") {   /* nobody else */
 call_out("dest_me",400);
   }
 }
 
 dest_me() {
   destruct(this_object());
   }
