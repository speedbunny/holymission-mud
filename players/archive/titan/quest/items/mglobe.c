	inherit "obj/players/titan/quest/globe";
	object money;

	reset(arg) {
	if(arg) return;

	money=clone_object("obj/money");
	money->set_money(2000+random(5000));
	move_object(money,this_object());
}
