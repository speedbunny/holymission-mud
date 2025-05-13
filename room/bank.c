inherit "room/std_bank";

int door_is_open, door_is_locked;
object guard;

void reset(int arg) {

    if (!arg) {

        set_light(1);

        short_desc="The bank";

        long_desc=
                  "You are in the old part of the bank. " +
                  "To the west is a low counter. The counter is covered " +
                  "with heavy iron bars. On the wall beside the counter, " +
                  "a door leads further west.\n";

        dest_dir=({
                   "room/newbroker","north",
                   "room/bankroom","west",
                 });

        items=({
                "counter","There is a sign  in the counter that says\n"+
                          "CLOSED FOR RECONSTRUCTION",
                "door","@@door_desc",
              });
    }
    if (!guard || !living(guard)) {
        object key, weapon;
        guard = clone_object("obj/monster");
        guard->set_name("guard");
        guard->set_race("human");
        guard->set_size(3);
        guard->set_level(11);
        guard->set_hp(200);
        guard->set_al(100);
        guard->set_short("A guard");
        guard->set_long("A big and sturdy guard.");
        move_object(guard, this_object());
        weapon = clone_object("obj/weapon");
        weapon->set_name("shortsword");
        weapon->set_short("A shortsword");
        weapon->set_alias("sword");
        weapon->set_long(
                         "It is a professional looking short sword, " +
                         "used by warriors and guards\n");
        weapon->set_class(12);
        weapon->set_value(700);
        weapon->set_weight(3);
        weapon->set_type(2);
        transfer(weapon, guard);
        guard->init_command("wield shortsword");
        key = clone_object("obj/treasure");
        key->set_id("key");
        key->set_alias("bank key");
        key->set_short("A bronze key");
        key->set_value(10);
        key->set_weight(1);
        transfer(key, guard);
    }
    door_is_open = 0; door_is_locked = 1;
}

string door_desc() {

    if (door_is_open) 
        return("The door is open");
    else
        return("The door is closed");
}

init() {
    ::init();
    add_action("open", "open");
    add_action("unlock", "unlock");
    add_action("west", "west");
}

int open(string str) {

    if (str && str != "door")
        return 0;
    if (door_is_open)
        return 0;
    if (door_is_locked) {
        write("The door is locked.\n");
        return 1;
    }
    door_is_open = 1;
    write("Ok.\n");
    say(this_player()->query_name() + " opened the door.\n");
    return 1;
}

int unlock(string str) {
    if (str && str != "door")
        return 0;
    if (door_is_open || !door_is_locked)
        return 0;
    if (!present("bank key", this_player())) {
        if (present("key", this_player()))
            write("You don't have the right key.\n");
        else
            write("You need a key.\n");
        return 1;
    }
    door_is_locked = 0;
    write("Ok.\n");
    say(this_player()->query_name() + " unlocked the door.\n");
    return 1;
}

int west() {
    if (!door_is_open) {
        write("The door is closed.\n");
        return 1;
    }
    if (guard && present(guard, this_object())) {
        write("The guard bars the way.\n");
        return 1;
    }
    ::move();
    return 1;
}

int query_door() {
    return !door_is_open;
}

int open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}
