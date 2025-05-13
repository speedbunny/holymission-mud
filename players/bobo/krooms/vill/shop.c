inherit "/obj/std_shop";
int i, x;
void reset(int arg) {
  ::reset(arg);
   if (!arg) {
   set_light(1);
   short_desc="Red Rock Junction General Store.";
   long_desc=
	"This is the Red Rock Junction General Store.  the walls are made "+
	"of red brick and the floor is made of spruce.  This is the place "+
	"where Kasimir, the nun, who is standing behind a desk trades for "+
	"all sorts of goods.  There is a sign hanging on the wall saying:  "+
	"'type list'.\n";
   store="/players/bobo/krooms/vill/store";
   keeper = "Kasimir";
   items = ({"walls","The walls are made of red bricks",
	    "counter","A long wooden counter stretches across the wall",
	    "floor","It's made of spruce",
	    "kasimir","She is standing behind the desk smiling at you",
	    "sign","The sign says:  Type list please!",
            });
   dest_dir=({
	"/players/bobo/krooms/vill/road2","west",
   });
}

    if (!present("torch",query_store()))
    {
        for(x=0;x<5;x++)
        {
            move_object(clone_object("/players/whisky/obj/torch"),
                        query_store());
        }
     }
}

