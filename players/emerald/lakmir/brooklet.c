#define TPN this_player()->query_name()
inherit "room/room";

void set_descs(int choice) {
    if(choice == 1) {
	long_desc="You have found a small brook which winds its way through " +
	"the forest.  The water in the brook is quite bloody and " +
	"foul, as if something has died in it recently.\n";
	short_desc = "By the banks of a brook";
    }
    else {
	long_desc="You have found a small brook which winds its way through " +
	"the forest.  The water looks quite clean, without a trace " +
	"of algae or tannins.  You feel that you could sit here " +
	"forever listening to the trickling of the water.\n";
	short_desc = "By the banks of a brook";
    }
}

void reset(int arg) {
    if(arg) return;

    set_light(1);

    items=({"brook","A small forest stream",
      "forest","The trees are very dark and seem quite evil",
      "water","@@water@@",
    });

    dest_dir=({"/players/emerald/lakmir/forest7","east",
    });

    property=({"has_water"});

    clone_list=({
      1,1,"nymph","/players/emerald/lakmir/waternymph",0,
    });

    ::reset(arg);
}

water() {
    if(!present("nymph", this_object())) {
	return "Foul, bloody water";
    }
    return "Sparkling clean water";
}
void init() {
    ::init();
    add_action("_fill","fill");
    if(!present("nymph", this_object()))
	set_descs(1);
    else
	set_descs(0);
}

int _fill(string str) {
    object bottle, ruby, waternymph;
    if(!(str)) {
	notify_fail("Fill what");
	return 0;
    }

    if(str=="bottle with water") {
	if(!bottle=present("bottle",this_player())) {
	    write("You need something to hold the water.\n");
	    return 1;
	}
	if(!waternymph=present("nymph",this_object())) {
	    write("The water is too foul to use!\n");
	    return 1;
	}
	if(!ruby=present("ruby",waternymph)) {
	    transfer (bottle,waternymph);
	    write("As you try to fill the bottle, the waternymph steals your bottle\n"
	      +"and says: If you want back your bottle you must\n"
	      +"give me the ruby, which the snake has stolen.\n");
	    say(TPN +" tries to fill the bottle with water, but the waternymph\n" +
	      "steals the bottle.\n");
	    return 1;
	}
    }
    return( 0 );
}
