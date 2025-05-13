/* e07 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
object sailor, flu;

ONE_EXIT( REGION+"d14", "northeast",
"On top of an old dyke",
"On top of an old dyke.\n",
1 )

towadden() { return "northeast"; }

init() {
   ::init();
	if (this_player() && living(this_player()) 
			&& !present("flu_q174", this_player())) {
		flu = clone_object("/players/qclxxiv/obj/flu");
		move_object(flu, this_player() );
	}
}

extra_reset(arg) {
   if (!sailor) {
		sailor = clone_object(REGION+"sailor");
		move_object(sailor, this_object() );
	}
   if (arg) return;
    set_nodig(1);
   items = ({
		"dyke", "A steep gray old dyke",
   });
}

/*
do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}
*/
