inherit "/players/goldsun/gen/obj/container";

void add_money(int amount){
 object coins;
 
   coins=clone_object("/obj/money");
   coins->set_money(amount);
   transfer(coins,this_object());
}

void reset(int arg){
    ::reset(arg);
 if (arg) return;

 set_name("chest");
 set_short("A treasure chest");
 set_long("A Goldsun's treasure chest.\n");
 set_can_lock(1,"steel","goldsun_code");
 set_max_weight(10);
 set_can_get(0);
 /* move_object(clone_object("/players/goldsun/obj/t_bill"),this_object());
 */
}
