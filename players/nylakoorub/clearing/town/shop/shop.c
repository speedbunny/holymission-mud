inherit "room/shop";
object trashcan;
#define TP this_player()

void reset(int arg){
    if(!trashcan) {
	trashcan=clone_object("/players/whisky/shops/trashcan");
	move_object(trashcan, this_object());
    }
    ::reset(arg);
    set_short("Wanderers R' Us");
    set_long(
      "You are at a small shop with a sign saying: Wanderers 'R Us.\n"+
      "Here's where you can buy and sell stuff without running back\n"+
      "to the shop in town. You can: 'Buy item', 'sell item', 'sell all',\n"+
      "'list', 'list weapons', 'list armours', 'value item'.\n");

    set_store_room("/players/nylakoorub/guild/rooms/shop/store");
    set_store_exit("north");
    set_exits(({"/players/nylakoorub/guild/rooms/inner_room", "out"}));
    set_light(1);
    property = ({ "no_fight" });
}
