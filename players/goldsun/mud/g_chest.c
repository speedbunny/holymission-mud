inherit "/obj/container";


void reset(int arg){
object coins;
    ::reset(arg);
 set_name("chest");
 set_short("A treasure chest");
 set_long("Wooden chest.\n");
 set_max_weight(10);
 set_can_get(0);
 set_can_close(1);
   coins=clone_object("/obj/money");
   coins->set_money(random(12000)+1200);
   transfer(coins,this_object());
 set_closed();
}
