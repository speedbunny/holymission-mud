inherit "obj/container";

reset(arg) {
  ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(99999);
      set_value(0);
      set_alias("barrel");
      set_long("A large barrel.\n");
      set_can_close(0);
      can_get=0;
    }
}

init(){
  ::init();

    add_action("qb","qb");
  }
     
int query_vat(){ return 1; }

int qb(){
    call_out("query_bag_value",0,this_object());
    return 1;
  }

int query_bag_value(object ob){
  int i, j, total, ic, jc;
  object *inv, *invc;
  
  if (!first_inventory(ob)) return 0;
  
  inv = all_inventory(this_object());
  total =0;
  j=sizeof(inv);
  
  for (i=0; i < j; i++){
    if (inv[i]->query_container()){ 
      
      if (first_inventory(inv[i])){      
        invc = all_inventory(inv[i]);
        jc=sizeof(invc);      
        for (ic=0; ic < jc; ic++){
          total+=(invc[ic]->query_value());
        }        
      }
    }   
    else {
      total+=(inv[i]->query_value());
    }
  } 
  return total;
}











