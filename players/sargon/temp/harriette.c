inherit "room/room";

object Harriette;
int count;
string *chat_str;        /* This variable is only initialized once. */
string *a_chat_str;
string *function, *type, *match;

void notify(string str) {
    say(str);
//    write(str);
}
        
void start_Harriette() {

    if(!Harriette) {
        if (!chat_str) {
            chat_str = allocate(10);
            a_chat_str = allocate(8);
            chat_str[0] = "Harriette says: Have you seen Harry?\n";
            chat_str[1] = "Harriette says: Hello dear!\n";
            chat_str[2] = "Harriette says: I don't like Harry drinking.\n";
            chat_str[3] = "Harriette says: I don't like it when I can't find Harry.\n";
            chat_str[4] = "Harriette says: When did you see him last?\n";
            chat_str[5] = "Harriette says: Sighs deeply.\n";
            chat_str[6] = "Harriette says: Why does he go out all the time?\n";
            chat_str[7] = "Harriette says: Harry better not be in that pub again.\n";
            chat_str[8] = "Harriette says: I made him a nice dinner.\n";
            chat_str[9] = "Harriette smiles.\n";
            a_chat_str[0] = "Harriette says: Don't hit me!\n";
            a_chat_str[1] = "Harriette says: That hurt!\n";
            a_chat_str[2] = "Harriette says: Help, someone!\n";
            a_chat_str[3] = "Harriette says: Why can't you go " +
                                         "bullying elsewhere?\n";
            a_chat_str[4] = "Harriette says: Aooooo\n";
            a_chat_str[5] = "Harriette says: I hate bashers!\n";
            a_chat_str[6] = "Harriette says: Bastard\n";
            a_chat_str[7] = "Harriette says: You big brute!\n";

            function = allocate(12);
            type = allocate(12);
            match = allocate(12);

            function[0] = "why_did";
            type[0] = "sells";
            type[1] = "attack";
            type[2] = "left";
            match[2] = "the game";
            type[3] = "takes";
            type[4] = "drops";
            function[5] = "how_does_it_feel";
            type[5] = "is now level";
            function[6] = "smiles";
            type[6] = "smiles";
            match[6] = " happily.";
            function[7] = "say_hello";
            type[7] = "arrives";
            function[8] = "test_say";
            type[8] = "says:";
            type[9] = "tells you:";
            function[10] = "follow";
            type[10] = "leaves";
            function[11] = "gives";
            type[11] = "gives";
        }
        Harriette = clone_object("obj/monster");
        /* Reuse the same arrays. */
        Harriette->load_chat(2, chat_str);
        Harriette->load_a_chat(20, a_chat_str);
        Harriette->set_match(this_object(), function, type, match);
        Harriette->set_name("Harriette");
        Harriette->set_alias("fjant");
        Harriette->set_male();
        Harriette->set_short("Harriette the affectionate");
        Harriette->set_long("Harriette has an agreeable look.\n");
        Harriette->set_ac(0);
        Harriette->set_level(3);
        Harriette->set_al(50);
        Harriette->set_race("human");
        Harriette->set_size(2);
        Harriette->set_ep(2283);
        Harriette->set_wc(5);
        Harriette->set_aggressive(0);
        move_object(Harriette, this_object());
        
        Harriette->set_random_pick(20);
        Harriette->set_move_at_reset();
    }
}

void why_did(string str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "Harriette" || who == "Harriette")
        return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
        notify("Harriette says: Why did you sell " + what + "\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
        notify("Harriette says: Why does " + who + " attack " + what + "?\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
        notify("Harriette says: Why did " + who + " quit the game ?\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
        notify("Harriette says: Why did " + who + " take " + what + " ?\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
        notify("Harriette says: Why did " + who + " drop " + what + " ?\n");
    }
}

void how_does_it_feel(string str) {

    string who, what;

    sscanf(str, "%s %s", who, what);
    if(who == "Harriette" || who == "Harriette")
        return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
        notify("Harriette says: How does it feel, being of level " + what +
               " ?\n");
    }
}
    
void smiles(string str) {

    string who, what;

    sscanf(str, "%s %s", who, what);
    if(who == "Harriette" || who == "Harriette")
        return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
        who != "Harriette") {
        notify("Harriette smiles happily.\n");
    }
}
    
void say_hello(string str) {

    string who;

    if (sscanf(str, "%s arrives.", who) == 1) {
        notify( "Harriette says: Hi " + who + ", nice to see you !\n");
    }
}
    
void test_say(string str) {

    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "Harriette" || a == "Harriette")
        return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
        return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
        message = "Harriette says: Pleased to meet you!\n";
    }
    if (str == "shut up") {
        message = "Harriette says: Why do you want me to shut up ?\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
        sscanf(str, "%snot follow%s", a, b) == 2 ||
        sscanf(str, "%sget lost%s", a, b) == 2) {
        message = "Harriette says: Ok then.\n";
    }
    if(!message)
        message = "Harriette says: Why do you say '" + str + "'???\n";
    notify(message);
}

void follow(string str) {

    string who, where;

    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
        Harriette->init_command(where);
}

void gives(string str) {

    string who, what, whom;
    int rand;
    object obj, next_obj;

    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
        return;
    if(whom != "Harriette")
        return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
        rand = random(4);
        if(rand == 0) {
            if(random(10) > 6) {
                notify("Harriette sighs and says: I guess you're gonna " +
                       "kill me now.\n");
                obj = first_inventory(Harriette);
                while(obj) {
                    next_obj = next_inventory(Harriette);
                    transfer(obj, environment(Harriette));
                    notify("Harriette drops " + obj->short() + ".\n");
                    obj = next_obj;
                }
                Harriette->init_command("west");
            }
        }
        if(rand == 1) {
            Harriette->init_command("drink " + what);
        }
        if(rand == 2) {
            obj = first_inventory(Harriette);
            while(!obj->id(what))
                obj = next_inventory(obj);
            transfer(obj, environment(Harriette));
            notify("Harriette drops the " + what + ".\n");
        }
        if(rand == 3) {
            obj = first_inventory(Harriette);
            while(!obj->id(what))
                obj = next_inventory(obj);
            transfer(obj, find_living(lower_case(who)));
            notify("Harriette returned the " + what + " to " + who + ".\n");
        }
    }
    else if(what == "corpse") {
        notify("Harriette says: HEY, bury your corpses yourself, asshole.\n");
        obj = first_inventory(Harriette);
        while(!obj->id(what))
            obj = next_inventory(obj);
        transfer(obj, find_living(lower_case(who)));
        notify("Harriette returned the " + what + " to " + who + ".\n");
    }
    else {
        notify("Harriette says: Thank you very much, sir.\n");
    }
}

int  monster_died() {

    object obj, b;
    int num;

    obj = first_inventory(Harriette);
    while(obj) {
        b = next_inventory(Harriette);
        if(obj->id("bottle")) {
            destruct(obj);
            num = 1;
        }
        obj = b;
    }
    if(num)
        notify("There is a crushing sound of bottles breaking, " +
               "as the body falls.\n");
    return 0;
}

int down() {
    this_player()->move_player("down#room/station");
    return 1;

}

void reset(int arg) {

    start_Harriette();
    if (arg)
        return;
/*

    dest_dir = ({ "room/vill_road1b","west",
                  "room/vill_shore","east",
                  "players/airborne/new/station","down",
                  "room/main_shop","north" });
*/

    short_desc = "Village road";

    no_castle_flag = 1;

    long_desc = "A long road going through the village. " +
                "There are stairs going down. " +
                "The road continues to the west. " +
                "To the north is the shop. " +
                "The road runs towards the shore to the east.\n";

    set_light(1);
}
