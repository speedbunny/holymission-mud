inherit "/obj/treasure";

reset(arg){
 if (arg) return;
 set_id("scroll");
 set_read("Dig down, climb, shake, pass, cut, light, listen, tear\n"+
	 "tree, bush. Mystic forest is magic ! Small bears live near\n"+
	 "great bears. Huge treasure is ......\n");
 set_short("A scroll");
 set_long("An old scroll.\n");
 set_weight(1);
 set_value(2);
 }
