inherit "/room/room.c";
reset(arg) {
   ::reset( arg );
}

init(arg) {
   ::init( arg );
   if(arg) return;
   short_desc = "At the sea-storeroom.";
   long_desc = "You are at the sea-storeroom.\n";
}
