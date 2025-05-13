

inherit"players/warlord/NEWSTUFF/room";
object ob,horn;

reset(arg) {
if (!ob) {
ob=clone_object("obj/monster");
ob->set_name("unicorn");
ob->set_short("White Unicorn");
ob->set_long("This is a magnificent beast.\n");
ob->set_race("questunicorn");
ob->set_level(30);
ob->set_ac(20);
ob->set_hp(1000);
ob->add_money(1000);
horn=clone_object("obj/weapon");
horn->set_name("horn");
horn->set_short("Unicorn horn");
horn->set_long("This is the horn of a unicorn\n");
horn->set_class(10);
horn->set_weight(2);
horn->set_value(500);
horn->set_hit_func(this_object());
move_object(ob,this_object());
move_object(horn,ob);
}
    if (!arg) {

    set_light(1);
    short_desc = "Unicorn room";
    no_castle_flag = 0;
    long_desc = 
        "You see a large unicorn here running around. It sees you and stops\n"
       +"for a second. It starts walking toward you.\n";
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room18", "south",
        });
}
}
weapon_hit(attacker){
  if (attacker->query_race()=="questdragon") {
  return 35; }
}
