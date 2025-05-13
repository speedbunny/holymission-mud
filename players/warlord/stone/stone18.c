

inherit "room/room";
object bront;

reset(arg) {
if (!bront) {
bront=clone_object("/obj/monster");
bront->set_name("bront");
bront->set_short("Brontosaurus");
bront->set_level(30);
bront->set_wc(30);
bront->set_ac(15);
bront->set_hp(2000);
bront->set_chance(2);
bront->set_spell_dam(180);
bront->add_money(2000);
bront->set_aggressive(0);
bront->set_long("This is the largest dinosaur you have ever seen\n");
move_object(bront,this_object());
}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room is holding (barely) the largest creature on this mud..\n"
        + "He is a Brontosaurus... and you are his lunch..\n";
    dest_dir = 
        ({
        "players/warlord/stone/stone19", "northwest",
        "players/warlord/stone/stone17", "west",
        "players/warlord/stone/stone16", "southeast",
        "players/warlord/stone/stone15", "southwest",
        });
}

