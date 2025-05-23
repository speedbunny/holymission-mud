/* Removed sourcer's old guild stuff. Put it in yard.old. */
inherit "room/room";

object beggar;

/*
 * Make these arrays global, so they only have to be initialized once.
 */
string *chat_str, *a_chat_str, *function, *type, *match;

void reset(int arg) {

    if(!arg) {
        set_light(1);
        short_desc="Small yard";
        long_desc="A small yard surrounded by houses.\n";
        dest_dir=({
            "room/vill_road1", "south",
#if 0
// 060498: Sauron: Commented out exit west to 'Goblin scalp' quest hermit since
//                 it duplicates the one in the forest.
            "players/moonchild/goblins/house", "west",
#endif
            "room/pub2", "east",
            "players/kelly/rooms/violens","north",
                 });
    }
    if (!present("knife")) {
        object weapon;
        weapon = clone_object("obj/weapon");
        weapon->set_name("knife");
        weapon->set_class(5);
        weapon->set_value(8);
        weapon->set_weight(2);
        weapon->set_type(2);
        move_object(weapon, this_object());
    }
    if (!beggar) {
        beggar = clone_object("obj/monster");
        beggar->set_name("beggar");
        beggar->set_level(3);
        beggar->set_race("human");
        beggar->set_size(3);
        beggar->set_al(200);
        beggar->set_long("A really filthy looking poor beggar.\n");
        beggar->set_hp(30);
        move_object(beggar, this_object());
        if (!function) {
            function = allocate(1);
            type = allocate(1);
            match = allocate(1);
            function[0] = "give_beggar";
            type[0] = "gives";
        }
        beggar->set_match(this_object(), function, type, match);
        if (!chat_str) {
            chat_str = allocate(3);
            chat_str[0] = "Beggar says: Please, give money to a poor beggar!\n";
            chat_str[1] = "Beggar says: Why can't I find any money ?\n";
            chat_str[2] = "Beggar says: two coins please !\n";
        }
        if (!a_chat_str) {
            a_chat_str = allocate(1);
            a_chat_str[0] = "Beggar says: Why do you do this to me ?\n";
        }
        beggar->load_chat(1, chat_str);
        beggar->load_a_chat(20, a_chat_str);
    }
}

void give_beggar(string str) {

    say("Beggar says: Thank you.\n");
    if (beggar->query_money() >= 12 &&
            environment(beggar) == this_object()) {
        beggar->init_command("east");
        beggar->init_command("buy beer");
        beggar->init_command("drink beer");
        beggar->init_command("west");
    }
}

