
int counter;


reset(arg) {
  if (!arg)
  {
    counter = 0;
    call_out("dest",1);
    set_light(60);
   }
  }

id(str) { return str=="berry" || str=="fireberry"; }
short() { return "A fireberry"; }
long() { write("A little berry, which spends a stange, bright light\n");}
query_weight() { return 1; }
query_counter() { return counter; }
query_berry(){ return 1; }
set_counter(c) { counter = c; }
get() { return 1; }
drop() { counter = 5;  return 0; }

 dest() {
  if (query_counter()>4 || counter>4) {   /* just to be sure */
   write("Suddenly your berry goes darker.\n");
    destruct(this_object());
  }
  call_out("dest",2);
  return 1;
  }

