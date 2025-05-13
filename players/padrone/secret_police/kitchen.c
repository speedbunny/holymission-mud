/* secret_police/kitchen.c */

inherit "/room/room"; // whisky

object beer;

reset(arg) 
{
    if (!present("beer", this_object())) {
	beer = clone_object("obj/drink");
	beer->set_value("beer#A bottle of beer#That feels good#0#12#2");
        move_object(beer, this_object());
    }
    if (!arg)
    {
       set_light(1);
       dest_dir =
       ({
         "players/padrone/secret_police/backroom", "west",
       });
       short_desc =  "A kitchen behind the shop";
       long_desc =
         "You are in a small kitchen behind the shop.\n" +
	 "It doesn't look like it's been used much lately.\n";
    }
}

