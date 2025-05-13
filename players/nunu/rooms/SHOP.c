

inherit "/players/whisky/obj/std_shop";

   reset(arg)
   {
   ::reset(arg);
   short_desc = "In a small, dirty hut";
   long_desc =
   "You are in a small hut. It smells fishy here. The walls are made\n"+
   "of small red bricks and the bottom covered with spruce wooden lathes.\n"+
   "This is the place where 'Hans' the old experienced sailor sells all\n"+
   "kinds of stuff. There is a sign saying: 'type list' fixed to the wall,\n"+
   "behind a wooden desk.\n";
 
    store = "/players/whisky/seaworld/room/sw_store";
   items = ({
            "hut","You are just standing in the hut", 
            "bottom","It's covered with spruce wooden lathes", 
            "walls","They are covered with red bricks", 
            "bricks","Just red, dirty bricks", 
            "hans","Hans the human is staying behind the desk smiling at you", 
            "sign","You see a small wooden sign saying: type list",
            "lathes","You see spruce wooden lathes"
                                                     });
    dest_dir = ({ "/players/whisky/seaworld/room/shop_entry","out" });

    if (!present("torch",query_store()))
      transfer(clone_object("/obj/torch"),query_store());
    if (!present("club",query_store()))
    {
     transfer(clone_object("/players/patience/ezo/ryuworld/club"),
      query_store());
     }
    keeper = "Hans";
}
