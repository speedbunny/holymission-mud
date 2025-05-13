#define NAME "stanley"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        set_light(1);

        short_desc=CNAME +"'s workroom",

        long_desc=
            "This is the workroom of "+CNAME+".\n" +
        "   This is a barren room, but for some reason, there is something intriguing\n"
        "about this place. You wander around the room. You follow along the walls,\n"+
        "sometimes reaching out and tracing along the bare bricks as if the secrets\n"+
        "they hide will become yours if you are nice enough to them.\n"+
        "Stairs lead down to Stanley's War Room.\n"+
        " ";

        dest_dir=({
            "room/post","post",
            "players/stanley/testing/room1","down",
            "room/church","church",
            "players/whisky/magic/mages_bar","bar",
            "room/adv_guild","guild",
                                                     });

        items=({ 
            "secrets","What secrets? Who knows any secrets?",
           "powder","Smooth as talcum",
            "dust","You are sure it will wash off with some soap and water",
            "room","Why examine a room? Just look at it",
            "air","It's very thin up here",
            "floor","The floor is dirty",
            "brick","It leaves a fine grey dust on your fingertips",
            "bricks","They leave a grey powder on your fingertips",
            "wall","The wall is made of grey, powdery brick",
            "walls","The walls are made of grey, powdery brick",
            "ceiling","It is just a ceiling.\n"+
            "You will put a crick in your neck staring up all the time",
                                                    });

        property = ({
            "no_sneak","no_steal",
                                                     });

            smell = "Sniff...sniff..Yep. Stanley's been here all right";
}
}
init()
{
  ::init();
}
