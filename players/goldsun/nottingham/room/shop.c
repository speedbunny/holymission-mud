 /*  nottingham general shop   */

inherit "/room/shop";

void reset(int arg){
 ::reset(arg);

 if (!present("trashcan",this_object())){
   move_object(clone_object("/players/whisky/shops/trashcan"),this_object());
 }

 if (arg) return;
  set_light(1);
  set_short("A shop");
  set_long("You are in the general shop in Nottingham.\n"+
	    "You can buy or sell things here.\n"+
	    "Commands are: 'buy item', 'sell item', 'sell all'\n"+
	    " 'list', 'list weapons', 'list armours' and 'value 'item'.\n");
  set_exits(({"/players/goldsun/nottingham/room/road1", "south"}));
  smell="You smell the odor of wood, leather, clothes and steal.";
  set_store_room("/room/store");
  set_store_exit("up");
}
	    


