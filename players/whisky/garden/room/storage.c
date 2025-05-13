 
 
inherit "players/whisky/f_store";
 
reset(arg) {
    if (arg) return;
 
    set_light(1);
    short_desc = "storage";
    long_desc = 
        "This is the storage of SEAWORLDS shop.........\n"
        + "Only wizards may enter......\n"
        + "If you where transed to the storage please write to whisky....\n"
        + "\n"
        + "                               I hope you enjoy Pudermud..\n"
        + "\n"
        + "                                            WHISKY..\n";
set_shop("players/whisky/sw_shop");
set_shop_exit("north");
set_auto_load("players/whisky/hyperbag");
set_auto_load("players/whisky/b_bag");
set_auto_load("players/whisky/star");
set_auto_load("players/whisky/hammer");
set_auto_load("players/whisky/sw_ring");
set_auto_load("players/whisky/orcslayer");
set_auto_load("players/whisky/teeth");
set_auto_load("players/whisky/trollslayer");
set_auto_load("players/whisky/p_sword");
set_auto_load("players/whisky/p_mail");
set_auto_load("obj/torch");
set_auto_load("players/whisky/teeth");
set_auto_load("players/whisky/l_bag");
set_auto_load("players/whisky/m_bag");
set_auto_load("players/whisky/boots");  
set_auto_load("players/whisky/maily");
set_auto_load("players/whisky/swordy");
}
