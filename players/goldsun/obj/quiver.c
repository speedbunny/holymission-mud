inherit "/players/goldsun/gen/std/std_quiver";
     
void reset(int arg){
  if (!arg){        /* call ::reset() after your definitions */
      set_name("goldsun's quiver");
      set_amount(300);
   }
    ::reset(arg);
 }

void dec_arrows(int amount){ return; }

drop(){
 write("Quiver disappears.\n");
 destruct(this_object());
}
