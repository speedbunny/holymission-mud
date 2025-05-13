inherit "room/shop";
object trashcan;
#define TP this_player()

reset(arg){
    if(!trashcan) {
	trashcan=clone_object("/players/whisky/shops/trashcan");
	move_object(trashcan, this_object());
    }
    ::reset(arg);
    set_short("The Tower Store");
    set_long(
      "This is the main shop of the Tower of Highest Thought. In here\n"+
      "you can: 'Buy item', 'sell item', 'sell all', 'list', 'list weapons',\n"+
      "'list armours', 'value item'. The shopkeeper doesn't look to be a\n"+
      "very nice person. Taken as a whole, this shop looks like hell!\n");

    set_store_room("/players/akira/psi/store");
    set_store_exit("south");
    dest_dir=({"/players/akira/psi/hall1", "north"});
    set_light(1);
}
query_property(arg) {
    return arg == "no_fight";
}
init(){
    ::init();
    add_action("torch", "torch");
}
torch(arg){
    if(TP->query_money()<40) {
	write("You don't have enough coins.\n");
	return 1;
    }
    write("You buy a torch.\n");
    TP->add_money(-40);
    move_object(clone_object("obj/torch"), TP);
    return 1;
}
