inherit "/obj/container";
#define PATH "/players/goldsun/nottingham/obj/"

void reset(int arg){
object coins;
    ::reset(arg);
 set_name("chest");
 set_short("A chest");
 set_long("A small iron chest.\n");
 set_max_weight(10);
 set_can_lock(1,"iron","special_tr_key_003");
   coins=clone_object("/obj/money");
   coins->set_money(random(888));
   transfer(clone_object(PATH+"t_key"),this_object());
   transfer(coins,this_object());
 set_closed();
 set_locked();
}
