inherit "/obj/container";

reset(arg){
object money;
 ::reset(arg);

if (arg) return;

 set_name("chest");
 set_can_lock(1,"crystal","kliment_code");
 set_closed();
 set_locked();
 set_of_glass(1);
 set_max_weight(9);
 move_object(clone_object("/players/goldsun/nottingham/obj/orb_key"),
     	this_object());
 money=clone_object("/obj/money");
 money->set_amount(12222);
 transfer(money,this_object());
 move_object(clone_object("/players/goldsun/nottingham/obj/ring"),
	this_object());
 set_long("A crystal chest.\n");
}

