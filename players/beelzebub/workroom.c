#define NAME "beelzebub"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)
string shield;
/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "' workroom",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is the workroom of "+CNAME+".\n" +
            "Looking around the room you are awestruck by all the electronic equipment\n" +
            "in here.  Theres Beelzebub's awesome computer that he uses for games and \n" +
            "coding (mostly games), his stereo with 5 way dolby pro logic surround sound,\n" +
            "and then theres his theater screen T.V. which mostly serves for watching \n" +
            "sports and playing Mortal Kombat I, II, & III with Morrolan.  You also \n" +
            "a Sony Playstation, 3DO, and a CD-I player hooked up to the T.V.\n" +
            " \n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "/room/post", "post",
            "/room/church", "church",
            "/room/adv_guild", "guild", 
            "/players/morrolan/workroom", "janitor",
            "/players/tuppence/workroom", "tuppy",
            "/players/matt/newworld/city/rooms/votebooth", "vote",
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "computer","It's CRAY Supercomputer.",
            "tv","Mortal Kombat the movie is playing on the VCR.",
            "stereo","A 2000 watt stereo system with duel 40 inch subwoofers.",
              });
        /* Properties can be set like the following */
        property = ({
"no_teleport","no_sneak","no_steal","no_snoop", 
                    });
        /* Smell is set like this... */
        smell = "This place smells like money.";
    }
}

init()
{
  ::init();
    add_action("do_shield","shield");
    if (shield && this_player()->query_real_name() != "beelzebub") {
        write("Beelzebub is coding, get out of here!\n");
        write("You are magically transfered to the church.\n");
        move_object(this_player(),"/room/church");
	if (find_living(NAME)) {
        tell_object(find_living(NAME), capitalize(this_player()->query_real_name())+ " tried to enter your workroom.\n"); }
    }
}

do_shield(str) {
    if (this_player()->query_real_name() != NAME) {
        write("Only Beelzebub can raise or lower the shields!\n");
        return 1;
    }
else
	{
    if (str == "on") {
        shield = "on";
        say("Beelzebub raises the shields forbidding people from entering the room.\n");
        write("You raise the shields.\n");
        return 1;
    }
    if (str == "off") {
        shield = !shield;
        say("Beelzebub lowers the shields allowing people to enter the room.\n");
        write("You lower the shields.\n");
        return 1;
    }
    if (!str && !shield) {
        write("The shields are lowered.\n");
        return 1;
    }
    if (!str && shield) {
        write("The shields are raised.\n");
        return 1;
    }
}
}
