inherit "room/shop";
object trashcan;
#define TP this_player()

reset(arg){
    if(!trashcan) {
	trashcan=clone_object("/players/whisky/shops/trashcan");
	move_object(trashcan, this_object());
    }
    ::reset(arg);
    set_short("The Happy Store");
    set_long(
      "Welcome to The Happy Store. This is the local shop of the Shire. Here\n"+
      "you can: 'Buy item', 'sell item', 'sell all', 'list', 'list weapons',\n"+
      "'list armours', 'value item'. The shopkeeper looks at you with a nice\n"+
      "and friendly smile on his face as he caters to your needs.\n");

    set_store_room("/players/colossus/mearth/shire/store");
    set_store_exit("north");
    set_exits(({"/players/colossus/mearth/shire/main1", "south"}));
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
