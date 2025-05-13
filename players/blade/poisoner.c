inherit "obj/thing";
    
int poison_amount;
object owner;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("poisoner");
    set_short(0);
    set_long("This is used to poison a monster.\n");
    set_weight(0);
    set_value(0);
  }
}

drop(silently) {
  destruct(this_object());
  return 1;
}

add_poison(amount) {
  int i;
  
  /* Portil 010994: Muzmuz wanted me to readd this next line
     But I still think its stupid */
  /* Blade  051296: It is stupid, so I changed it back */
  if(amount > poison_amount) poison_amount=amount;

  i=remove_call_out("do_poison");
  if(i==-1) i=10;
  call_out("do_poison",i);
}

set_owner() {
  owner=environment(this_object());
}

do_poison() {
  poison_amount--;
  if(poison_amount<1) return;
  if(!owner) {
    destruct(this_object());
    return;
  }
  if(!living(owner)) {
    destruct(this_object());
    return;
  }
  owner->hit_player(poison_amount,7);
  call_out("do_poison",10);
}

query_poison_amount() {
  return poison_amount;
}





