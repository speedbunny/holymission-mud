
// kshop : recoded to room/room  Whisky on 22.02.95 uni-linz.ac.at

inherit "/obj/std_shop";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "Keidall Trading Post";
        long_desc = break_text(
        "You have entered the Keidall Trading Post where the " +
        "populace of the city of Keidall buys and sells items. " +
        "All the usual shop commands work here also. " +
        "There is an opening to the north, and some shimmering " +
        "blue light in the doorway.\n",60);
        
         dest_dir =
         ({
            "players/silas/fghant/keidall4", "south",
         });
         store = "/players/silas/fghant/kstore";
         keeper = "Keidall";
     }
     if (!present("torch",query_store()))
         move_object(clone_object("/obj/torch"),query_store());
}


