inherit "obj/std_trans";
/* Tatsuo 3-18-95 : replaced old carriage with std_trans version */
reset(arg){
    if(arg) return;
     set_short("a sturdy carriage");
    set_alias("carriage");
    set_long("The carriage is made of sturdy oak. Even though the\n"+
             "carriage looks old, it looks strong enough to weather\n"+
             "the strongest of storms.\n");
    set_inside_long("The carriage is cushioned with red velvet seats\n"+
                    "decorated in gold trim.  A pleasant place to\n"+
                     "enjoy an afternoon ride.\n");
    set_inside_enter("steps into the carriage.\n");
    set_outside_enter("climbs into the carriage.\n");
    set_inside_leave("opens the door and jumps out.\n");
    set_outside_leave("hops out of the carriage.\n");
    set_land(1);
    stop_time(30);
    trans_time(40);
    set_rooms(2,({"/room/vill_road1",
        "/players/tamina/teds/path/path1"}));
    ::reset(arg);
}
