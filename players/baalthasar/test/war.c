#define TPN this_player()->query_real_name()

inherit "room/room";
object man,stick,cloak;

reset(arg) {
if (!man) {
man=clone_object("obj/monster");
cloak=clone_object("obj/armour");
stick=clone_object("obj/armour");

man->set_name("old man");
man->set_short("Old man");
man->set_alias("man");
man->set_long("This is Warlord's greatest guard. He is retired now. He is VERY TOUGH DO NOT TRY TO KILL HIM\n");
man->set_race("human");
man->set_gender(1);
man->set_level(40);
man->set_al(100);
man->add_money(5000);
man->set_wc(random(80));
man->set_ac(20);
man->set_aggressive(0);
man->set_chance(10);
man->set_damage(150);

cloak->set_name("cloak");
cloak->set_short("Cloak of Retirement");
cloak->set_long("This cloak belongs to the Old man");
cloak->set_ac(1);
cloak->set_value(500);
cloak->set_weight(-1);
cloak->set_type("cloak");

stick->set_name("stick");
stick->set_short("Old Walking stick");
stick->set_long("Old man's walking stick");
stick->set_class(20);
stick->set_value(3000);
stick->set_weight(3);

move_object(man,this_object());
 move_object(cloak,man);
 move_object(stick,man);
}
    if (arg) return;

    set_light(1);
    short_desc = "hut";
    long_desc = 
        "This hut belongs to a poor old man who has lived a long\n"
        + "and wise life. He just sits by the window and stares at the castle.\n";
    dest_dir = 
        ({
        "players/warlord/road1", "east",
        });
items=({
"window","You look at the window and see a Castle to the north",
"hut","The hut is empty other then a chair by the window",
"chair","A simple little chair made of wood",
"castle","It's a very large and white castle",
});
}

init() {
::init();
add_action("go","gohome");
}
go() {
if((TPN=="skyler")||(TPN=="warlord")||(TPN=="christian")) {
this_player()->move_player("goes home#/players/warlord/house/foyer");
return 1;
}
}
