#define NAME "turbo"
#define CNAME   capitalize(NAME)
inherit "room/room";
reset(arg) {
    if(!arg) {
     set_light( 4 );
     short_desc="Alone and at peace";
     long_desc="A quiet place where it can be alone with its thoughts"+
     ", its music, and its booze is where Turbo calls home.  It is here it"+
     " works, and here it sleeps.  But most importantly, it is here it is!\n";
     dest_dir=({
   //  "/players/turbo/rooms/r1","enter",
       "/room/church","church",
       "/obj/tick","north",
     });

   //move_object(clone_object("/players/turbo/obj/catapult2"),this_object());
     items=({ 
     });
     smell = "Smells like White Diamonds perfume";
    }
}

init()
{
    ::init();
}
