
/* castle.c    Metaprat                                   */

/* This is the castle used to autoload the keys, insurance policies.. */

#define DEST "/room/storage"

object lockers;
object estate;

id(str) {
   return (str == "silas_castle");
}

reset(arg) {
   object storage;

    if (!arg) {
        /* move to the destination, after first loading it into the game. */
        call_other(DEST,"XXXXX");
        move_object(this_object(),DEST);
    }
   /* preload all the autoloading objects that I use. */
   /* If this is not done, the first players into the */
   /* game will lose keys, policies, etc.             */
   call_other("/players/silas/houses/misc_objs/insurancequote","XXXX");
   call_other("/players/silas/houses/misc_objs/house_key","XXXX");
   call_other("/players/silas/houses/house_key","XXXX");

   /* make sure the storage room is loaded into the game */
   call_other(DEST,"XXXX");
   storage = find_object(DEST);

   /* check if lockers already exist.  If not, load them, and move them */
   if ((!lockers) && (!present("lockers", storage))) {
      call_other("/players/silas/houses/misc_objs/lockers","XXXX");
      lockers = find_object("/players/silas/houses/misc_objs/lockers");
      move_object(lockers, storage);
   }

   /* check if estate agent already exists.  If not, load it, and move. */
   if ((!estate) && (!present("agent", storage))) {
      call_other("/players/silas/houses/estate_agent", "XXXX");
      estate = find_object("/players/silas/houses/estate_agent");
      move_object(estate, storage);
   }
}


short() {
    return 0;   /* invisible */
}

long() {
   write("Eh? This is supposed to be invisible!\n");
   return 1;
}

