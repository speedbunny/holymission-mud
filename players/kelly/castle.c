#define NAME "kelly"
#define DEST "players/kelly/workroom"
#define MYAREA "room/eastroad5"
#define BINS ({"room/pub2","room/inn","room/adv_guild"})
 
int closed;
object obj;
 
id(str) { return str == "castle" || str=="loader"; }
 
short() {
    return "Automatic Loader";
}
 
long() {
 write(
 "This is Kelly's castle.\n"+ 
 "It is loading all necessary objects for Kelly's areas when the game reboots.\n");
}
 
 
reset(arg) {
   object obj;
   int i;

   if(arg) return;
   closed=1;
   move_object(this_object(),DEST);

/*
   move_object(clone_object("players/kelly/rooms/vill/facade"),MYAREA);  
*/

//    "players/kelly/guild/entrance"->reset(); 

   /* This room must be loaded once to place the doors */
   "players/kelly/rooms/castle/cellar1"->reset();

   /* This room must be loaded to start Violens */
   "players/kelly/rooms/violens"->reset();

   /* start the carriage */
/*
   "players/kelly/cart/cart"->short();
*/

   /* place some Trashbins */
   for(i=0;i<sizeof(BINS);i++)
     move_object(clone_object("players/kelly/obj/trashbin"),BINS[i]);
 
}
