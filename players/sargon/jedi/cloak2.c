// cloak.c (Jedi cloak) 
// ?     : Kelly: (?) 
// ?     : Mangla: (?) 
// 121294: Beast: SP-boosting
// ?     : Whisky: moved the call_out tick_cloak to a heart_beat.
//         The reason was, because it took much cpu and filled 
//         the call_out list.
// 012095: Beast: a) type changed to "cloak"
//                b) immortals can wear it now :)
//                c) tests for 'is_active' if remove/drop/...
// 012595: Beast: TP in heart_beat changed to ENV() (TP isn't defined there)
// 012695: Beast: set_ac() in wear() is now compensed in remove() and drop()
// 013195: Beast: for immortals is cloak more informative now
// 020295: Beast: 'transfer' function
// 021095: Beast: thief-proof thing

inherit "obj/armour";

#include "/players/beast/defines.h"

#define POWER         "players/beast/objs/jedipower" // jedipower object
#define TICK_CLOAK    50                             // cloak-tick delay
#define TICK_FADEAWAY 15                             // fadeaway delay 
#define SIDE_STR      (((power)>=0)?"Light":"Dark")  // your side info string
#define VERB_STR      ((is_verbose)?"ON":"OFF")      // verbose info string
#define GRLEN(x)      (((x)-1)/16 + 1)               // length of gr-power
#define BASE_AC       1                              // cloak base ac
#define TDELAY        4                              // transfer delay
#define SPCOST        10                             // base transf. cost
#define SPCOST_I(_w)  (((_w)+5) * 5)                 // transf. cost (item)
#define SPCOST_C(_c)  ((_c) / 50 + 5)                // transf. cost (coins)
#define SHAD_PATH     "players/beast/objs/tpr_shad"  // path to shadow
#define SHAD_TIME     0                              // time for shadow
#define SHAD_ID       "tpr_shad"                     // shadow id 
#define SHAD_COST     40                             // shadow sp cost 

int is_verbose;      // Is verbose mode on ? (if so, shows you SP changes 
                     // if your cloak is active) 
int is_active;       // Is your cloak active (e.g. worn,...)
int is_tpr;          // Is in thief-proof mode ?
int power;           // Amount of power for you. It is evaluated (from your 
                     // level & alignment) when you wear your cloak and it 
                     // is negative/positive for the dark/light side. 
                     // Absolute value of 'power' is added to dark/light
                     // global power and subtracted when you remove/drop 
                     // your cloak. 
int counter;         // Counts the heart_beats for the cloak_tick
int in_transfer;     // 1 if transfer is in progress
int coins;           // how much coins to transfer
object myshad;       // shadow for thief-proof thing
string item;         // what item to transfer
string dest;         // destination for transfer

void reset(int arg) 
{
    ::reset(arg);
    if (!arg) {
        set_name("jedicloak");
        set_alias("cloak");
        set_short("A new black Jedi-cloak");
        set_long("This is your Jedi-Cloak. You should wear it with pride.\n"+
                 "  For more help on features this cloak might possess\n"+
                 "  just type 'cloak help'.\n");
        set_ac(BASE_AC);
        set_value(0);
        set_weight(1);
        set_type("cloak");
        is_verbose = 1;
        is_active = in_transfer = is_tpr = 0;
        power = 0;
        counter = 0;
// strange the actions are then gone enable_commands();
    }
}

int get() 
{
    remove_call_out("fade_away");
    return 1;
}

// bug reporting routine
void cloak_bug(string arg) {
    write("It seems your cloak doesn't work properly.\n"
          "Bug report: "+arg+".\n"
          "Please inform Beast.\n");
    return;
}

// make a shadow for player to detect stealing from him
int cloak_thiefproof() {
    if (is_tpr) {
        if (!myshad) 
            cloak_bug("Can't destruct");
        else {            
            destruct(myshad);
            myshad = 0;
            is_tpr = 0;
            write("Your awareness suddenly decreases.\n");
        }            
        return 1;
    }        
    if (TP->SP < SHAD_COST) {
        write("You are too tired.\n"
            "You are unable to increase your awareness.\n");
        return 1;
    }            
    if (!(myshad = clone_object(SHAD_PATH))) {
        cloak_bug("Fail to clone shadow");
        return 1;
    }        
    if (myshad->start_shadow(TP, SHAD_TIME, SHAD_ID) != 1) {
        cloak_bug("Fail to start shadow");
        return 1;
    }   
    write("You feel your awareness increases.\n");    
    TP->ADDSP(-SHAD_COST);
    is_tpr = 1; 
    return 1;
}  

int remove_fun(object player) {
    if (is_active) {
        if (is_tpr)
            cloak_thiefproof();
        POWER->decompute_power(power);
        set_heart_beat(0);
        disable_commands();
        is_active = 0;
    }
    TO->set_ac(BASE_AC);
    return 1;
}

int drop(string arg) {
    if (is_active) {
        if (is_tpr)
            cloak_thiefproof();
        POWER->decompute_power(power);
        set_heart_beat(0);
        disable_commands();
        is_active = 0;
    }
    TO->set_ac(BASE_AC);
    call_out("fade_away", TICK_FADEAWAY);
    return ::drop(arg);
}

// this function is called every 'TICK_CLOAK' seconds
// if cloak is active and you are not fighting it restores some SP 
void heart_beat() {
    int diff, tmpdiff, tmpsp;
    if (!is_active)
        return;
    if (++counter < TICK_CLOAK)
        return;     
    counter = 0;
    diff = ((is_tpr) ? -SHAD_COST : 0) + 
        ((ENV()->ATTACK) ? 0 : random(POWER->query_power(power)) + 1);
    if (diff < 0) {
        if (ENV()->SP + diff < 0)
            diff = 0;
    } else {
        if (ENV()->SP + diff > ENV()->MAXSP)
            diff = ENV()->MAXSP - ENV()->SP;
    }            
    if (diff != 0) {
        ENV()->ADDSP(diff);
        if (is_verbose) {
            if (diff > 0) 
                TELL(ENV(), "You gain some power.\n");
            else
                TELL(ENV(), "You feel tired.\n");
        }                                
    }        
    if (is_tpr && ENV()->SP < SHAD_COST) {
        write("You are tired. You feel your awareness decreases.\n");
        destruct(myshad);
        myshad = 0;
        is_tpr = 0;
    }
    return;
}
    
int wear_fun(object player) {
    if (player->GUILD != GUILDN("jedi")) {
        write("A strong Force keeps you from wearing this cloak.\n");
        command("remove "+query_name(),player);
        return 1;
    }
    TO->set_ac((TP->DEX / 15) + BASE_AC);
    say(TP->NAME+" somehow looks more powerful.\n");
    is_active = 1;
    power = POWER->compute_power(TP->ALIGN, TP->LEVEL);
    enable_commands();
    set_heart_beat(1);
    write("You feel the " + SIDE_STR +
          " Force take control of your mind and body.\n");
    return 1;
}

int fade_away() {
    if (!living(ENV(TO)) && ENV(TO)->GUILD != GUILDN("jedi")) {
        tell_room(ENV(TO),"The cloak gets indistinct and fades away.\n");
        destruct(TO);
    }
    return 1;
}

// 'cloak color' command; sets color of your cloak to 'arg'
int cloak_color(string arg) {
    switch(arg) {
        case "blue": 
        case "red": 
        case "black": 
        case "green": 
        case "orange":
        case "brown":
        case "grey":
        case "white": 
            set_short("A new "+arg+" Jedi-cloak");
            write("Set to "+arg+".\n");
            return 1; 
    }
    return 0;
}

// 'cloak help' command; prints help info about your cloak
int cloak_help() {
    write("Help on Jedi-cloak:\n"
          "  Wearing this cloak you are one with the Force (Dark side\n"
          "  or Light side, acording your alignment). Your power\n"
          "  increases total power of your side and depends on\n"
          "  your level (of course) and on your alignment (smallest\n"
          "  for neutral). While not fighting you are gaining some\n"
          "  spell-points from the Force. So ... choose one side!\n\n"
          "  You can see how the Force is balanced with\n"
          "    cloak check\n"
          "  or you can make your cloak more informative with\n" 
          "    cloak verbose\n"
          "  and your cloak has some colors it can impersonate - choose\n"
          "  a color (blue,red,black,green,orange,brown,gray,white) with\n"
          "    cloak color <color>\n"
          "  If you feel thieves behind your back you can try\n"
          "    cloak thiefproof\n"
          "  and stealing from you can be dangerous for them!\n\n"
          "  Using the Force and your power you can transfer some\n"
          "  items/coins to another player. To do so, just type\n"
          "    transfer <item/coins> to <player>\n"
          "  Note you can't transfer weapons and/or quest items.\n\n"
          "                                            da beest\n\n");
    return 1;
}

// 'cloak verbose' command; sets verbose ON/OFF and prints message about it
int cloak_set_verbose(int newverbose) {
    is_verbose = newverbose;
    write("Cloak verbose is now " + VERB_STR + ".\n");
    return 1;
}

// returns graphic representation of 'pw' 
string gr_power(int pw, int tpw) {
    if (pw > 0) {
        pw = GRLEN(pw);
        return sprintf("%*'>'c%*c",pw,'>', tpw-pw, ' ');
    }
    return sprintf("%*c",tpw,' ');
}

// 'cloak check' command; prints cloak status and jedipower status 
int cloak_check() {
    int dpw, lpw, tpw;
    write("You are one with the "+SIDE_STR+" side of the Force.\n");
    dpw = POWER->query_dark_power();
    lpw = POWER->query_light_power();
    tpw = GRLEN(dpw >= lpw ? dpw : lpw) * 2 + 1;
    write("Dark power  : [" + 
          gr_power(dpw, tpw) + "]\n" +
          "Light power : [" + 
          gr_power(lpw, tpw) + "]\n" +
          "Your power  : [" + 
          gr_power(ABS(power), tpw) + "]\n"); 
    if (is_tpr) 
        write("Your awareness is unnaturally high.\n");
    if (TP->IMMORTAL) {
        write("Wizard only info:\n"+
            "Cloak(s) worn: "+POWER->query_ncloaks() + ".\n" +
            "Dark/Light/Your power: "+
            POWER->query_dark_power() + "/" +
            POWER->query_light_power() + "/" +
            ABS(power) + ".\n" +
            "You can get max "+POWER->query_power(power)+" SP per tick.\n");
    }        
    return 1;
}


// cloak command handler; you have to wear cloak to use it
int _cloak_cmd(string str) {
    string wfun, warg;
    if (!is_active) {
        write("You have to wear it first.\n");
        return 1;
    }    
    switch (str) {
        case "verbose":
            return cloak_set_verbose(1 - is_verbose);
        case "check":
            return cloak_check();
        case "help":
            return cloak_help();
        case "thiefproof":
            return cloak_thiefproof();           
        default:
           if (str && sscanf(str,"%s %s",wfun,warg) == 2 && wfun == "color") 
               return cloak_color(warg);
           return 0;
    }
    return 0;
}

// Finishes a transfer of an 'item' to a 'player' 
// Note: you can't transfer weapon/quest item, 
//       and you can't transfer to ghost/linkdead player

void _doit() {
    int weight, cost, i;
    object *inv, item_ob, dest_ob;    
    string cdest;
    in_transfer = 0;
    // find destination (player)
    dest = lower_case(dest);
    cdest = capitalize(dest);
    if (cdest == TP->SNAME) {
        write("You can't transfer it to yourself.\n");
        return;
    }        
    dest_ob = find_player(dest);
    if (!dest_ob) {
	    write("You can't find " + cdest + ".\n");
	    return;
    }
    // target have to be a member of the jedi guild ?    
    if (dest_ob->GUILD != GUILDN("jedi")) {
        write(cdest + " is not able to accept it.\n");
        return;
    }
    if (dest_ob->query_ghost()) {
        write("You can't transfer it to a ghost.\n");
        return;
    }
    if (dest_ob->query_linkdeath()) {
        write("You can't transfer it to a linkdead player.\n");
        return;
    }
    if (item) {
        // check this item
	    item_ob = present(item, this_player());
	    if (!item_ob) {
	        write("There is no such item here.\n");
	        return;
	    }
	    if (ENV(item_ob) != TP) {
	        write("You must carry it first.\n");
	        return;
	    }
	    if (item_ob->query_quest_item() || item_ob->query_weapon()) {
            write("You can't transfer this item.\n");
            return;
        }
        weight = item_ob->query_weight();
        if (! dest_ob->add_weight(weight)) {
	        write("This item is too heavy for "+cdest+".\n");
	        return;
        }
        cost = SPCOST_I(weight);
        if (TP->SP < cost) {
            write("Item is too heavy for you to transfer.\n");
            return;
        }
	    if (item_ob->drop(0) == 1) {
	        write("You can't get rid of this item.\n");
    	    return;
        }    	    
        TP->add_weight(-weight);
        move_object(item_ob, dest_ob);
        write("You manage to transfer "+item+" to "+cdest+".\n");
        TELL(dest_ob, TP->SNAME+" transfers "+item+" to you.\n"); 
    } else if (coins > 0) {
        // check money    
        if (TP->MONEY < coins) {
	        write("You don't have that much money.\n");
	        return;
	    }
	    cost = SPCOST_C(coins);
        if (TP->SP < cost) {
            write("Too much money for you to transfer.\n");
            return;
        }
	    TP->add_money(-coins);
	    dest_ob->add_money(coins);
        write("You manage to transfer some coins to "+cdest+".\n");
        TELL(dest_ob, TP->SNAME+" transfers some coins to you.\n"); 
    } else {
        // if <= 0 coins    
        write("Blah! You can't do it!\n");
        return;
    }
    TP->ADDSP(-cost);
    // tell it to all in target's room (except target)
    inv = all_inventory(ENV(dest_ob));
    for (i = 0; i < sizeof(inv); i++) 
        if (living(inv[i]) && inv[i] != dest_ob)
            TELL(inv[i], cdest+" receives something from" +
                " the channels of the Force.\n");
    return;
}

// transfer function - initiates the transfer
int my_transfer(string str) {
    if (!str)
	    return 0;
    if (!is_active) {
        write("You have to wear your cloak first.\n");
        return 1;
    }    
    if (in_transfer) {
        write("Another transfer is allready in progress.\n");
        return 1;
    }                	    
    item = 0;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	    item = 0;
    else if (sscanf(str, "1 coin to %s", dest) == 1)
	    coins = 1;
    else if (sscanf(str, "coin to %s", dest) == 1)
	    coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) {
	    write("Transport what to whom ?\n");
	    return 1;
    }
    if (TP->SP < SPCOST) {
        write("You are not strong enough to use the Force.\n");
        return 1;
    }
    if (TP->ATTACK) {
        write("You can't concentrate while fighting.\n");
        return 1;
    }            
    say(TP->SNAME + " concentrates on the Force.\n");
    write("You concentrate on the Force.\n");
    TP->ADDSP(-SPCOST);
    call_out("_doit", TDELAY);
    in_transfer = 1;
    return 1;
}

void init() 
{
    ::init();
    add_action("_cloak_cmd","cloak");
    add_action("my_transfer","jeditransfer");
//  whisky return;
}

