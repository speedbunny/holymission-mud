#define NAME "muzmuz"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
        set_light(1);

        short_desc=CNAME + "' workroom",

        long_desc=
            "Here you are in the workroom of "+CNAME+".\n" +
            "He did not think a lot about how to make it,\n" +
            "But you should not be impatient, he does\n" +
            "His best to make it well. Enjoy it here and\n" +
            "if you want, he will show you around\n";

        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
            "/players/muzmuz/testroom2.c","up",
            "/players/muzmuz/testroom","stairs",
            "players/muzmuz/island/rooms/ae","island",
            "players/muzmuz/area/rooms/entrance","area",
            "players/muzmuz/rooms/pit","pit",
            "players/muzmuz/rooms/rom","rom",
            });
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        property = ({
                     "no_sneak","no_steal","no_clean_up",
                    });
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();

}


