

inherit "room/room";

object cor,chain;
reset(arg) {
if (!cor) {
cor=clone_object("/obj/monster");
chain=clone_object("/obj/weapon");
cor->set_name("corpse");
cor->set_short("Bloody Corpse");
cor->set_long("This was once a valiant warrior, but now is dead and pissed.\n");
cor->set_level(25);
cor->set_gender(1);
cor->set_aggressive(1);
cor->add_money(600);
chain->set_name("chain");
chain->set_short("Chain");
chain->set_long("This chain was used to hold a fighter captive.\n");
chain->set_wc(15);
chain->set_weight(4);
chain->set_value(500);
move_object(chain,cor);
move_object(cor,this_object());
}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is  a very damp and bloody dungeon...The last\n"
        + "person left in here is dead now... except for........\n";
    dest_dir = 
        ({
        "players/warlord/drac/drachall1", "west",
        });
}

