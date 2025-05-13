inherit "room/shop";
object trashcan;
#define TP this_player()

void reset(int arg){
    if(!trashcan) {
	trashcan=clone_object("/players/whisky/shops/trashcan");
	move_object(trashcan, this_object());
    }
    ::reset(arg);
    set_short("Spliff Shop");
    set_long(
      "You have entered a small building with a small counter in the back\n"+
      "with some glass jars on it.  You notice that the jars contain some\n"+
      "strange flowery substances in them.  The smell here is strange yet\n"+
      "rather sweet.  You can do only one thing here, buy spliffs.\n");


    set_store_room(
      "/players/sargon/obj/store"
    );
    set_store_exit("north");
    set_exits(({
      }));
    set_light(1);
    property = ({ "no_fight" });
}
