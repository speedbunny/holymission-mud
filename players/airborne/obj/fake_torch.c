inherit "obj/treasure";

reset(arg){
   if(arg) return;
   set_short("A torch");
   set_name("A torch");
   set_alt_name("fake_torch");
   set_long("A torch.\n");
   return 1;
}

get(){ return; }
