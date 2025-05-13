 
 
inherit "players/rasta/room/f_shop";
 
reset(arg) {
    if (arg) return;
 
    set_light(1);
    short_desc = "sw_shop";
    long_desc = 
 "This is Rasta's shop where Trench Town dwellers use to buy their ganja,"
+"food and weapons to fight against the nefarious Babylonian system.\n";

set_store_room("players/rasta/room/storage");
set_store_exit("south");
}
