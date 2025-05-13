inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Secret Library";
    long_desc=
"This rooms seems to be one of the major secrets of the Mage-Tower.\n"+
"There are lots of shelves filled with books, scipts and scrolls.\n"+
"You notice that the room seems to be larger then the whole level of the\n"+
"tower. You don't know how you should ever find what you search.\n";

    items=({ "shelf","Alot of dusty shelves",
             "shelves","Alot of dusty shelves",
             "books","They seem to be everywhere",
             "scripts","Scripts are everywhere you look",
             "scrolls",
                 "Uncounted lots of scrolls in languages you never heared of"
          });
}

init() {
    ::init();
    add_action("search","search");
}

search(a) {
    if (!a) return;
    a=lower_case(a);
    if(a=="for elminsters tome of wonders" ||
       a=="elminsters tome of wonders")
    {
       say(this_player()->query_name_true()+
           " starts to search for something.\n",this_player(),this_player(),
           "");
       write("After some time you finally find the tome. Scanning it,\n"+
             "you find the following entry about wish spells:\n\n"+
" ... and there are the spells called WISHES.\n"+
" by means of this spells the caster is able to wish for certain things\n"+
" (listed below). There exist tow kinds of wishes. The limited wishes and\n"+
" the true wishes (just called wishes).\n"+
" The contents ...\n"+
"\n ... here now the list of the known effects one can wish for:\n\n"+
" (NOTE: every effect possible with a limited wish is possible with true\n"+
"        wish too!)\n\n"+
" limited wishes:\n"+
"        experience ... the effect is somehow random\n"+
"        gold       ... go receive as much gold as you can carry\n"+
"        str, dex, int, wis, con, chr ... only possible up to 32\n"+
"\n"+
" true wishes:\n"+
"        recall     ... teleport to the church from everywhere\n"+
"        power      ... gives you the ability to hit harder\n"+
"        defense    ... gives you some kind of natural defense\n"+
"        str, dex, int, wis, con, chr ... raise a stat by 1\n"+
"\n"+
" ....\n"+
" .... to use a wish scroll you have to 'recite wish <effect>'\n"+
" that mean eg: recite limited-wish gold\n"+
"\n But be aware, misspelled wish makes the god angry.\n"+
" ...\n");
       return 1;
    }
    else
    {
       write("You dont even know where to start.\n"+
             "You have to get some information first.\n");
       return 1;
    }
}
