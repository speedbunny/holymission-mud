#define NAME "dworkin"
inherit "room/room";
 
#define CNAME   capitalize(NAME)
 
void reset(int arg) {
  ::reset(arg);
    set_light(1);
    short_desc=CNAME + "'s workroom",
    long_desc=
      "Everything in this room is covered by a thick layer of dust. Along one wall a large desk sits, strewn with books and papers.\n";
    
    dest_dir=({
      "players/dworkin/startroom","area",
      "room/adv_guild","guild",
      "room/post", "post",
      "room/church", "church",
    });
    items=({ 
      "floor","The floor is dirty",
    });
    property = ({
      "no_teleport","no_sneak","no_steal",
    });
    replace_program("room/room");
}
 
/********** You can place add_actions in here for special actions
init() {
    ::init();
    add_action("_blah","blah");
}
************/





