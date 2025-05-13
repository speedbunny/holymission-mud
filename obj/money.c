/* MONEY.C - This is an inherit/clone file. DO NOT COPY! */
// 281190: JnA: Made sure the money is picked up before it's destructed.
// 110592: Llort: Changed destruction to call_out
// 230693: Ethereal Cashimor: USERDOC added
// 231097: Sauron: Tidied file, strict typed. As an attempt to limit the
//                 number of clones of this object in the mud, I have
//                 made it so that if two money objects are placed in the
//                 same environment, they will merge.
// 071197: Sauron: Moved counting of money picked up to the add_money()
//                 routine in /sys/living.c

int iMoney;
mixed *xaAmountArray; // Added by Bonzo

/* USERDOC:
general
This object can be used to put money on the ground or in boxes ect. It can
also be used to give money to livings, though the function add_money could
be used in those cases. Generally defined functions:
query_weight.
*/

int id(string str) {
    return (iMoney == 1 && str == "coin") ||
           (iMoney != 1 && str == "coins") ||
           str == "money";
}

int count(string str) {
    if(!id(str))
        return 0;
    if(iMoney == 1)
        write("There is 1 coin.\n");
    else
        printf("There are %d coins.\n", iMoney);
// Perhaps something more intelligent here.
    return 1;
}

/* USERDOC:
set_money
Format: set_money(i)
Example: set_money(10)

This function sets the amount of money this particular pile of money is
worth.
*/

void set_money(int iM) {
    iMoney = iM;
}

int query_money() {
    return iMoney;
}

mixed *get_amount_array() {
    if(file_name(this_object())=="obj/money")
        return ({
            2,    "Two ",
            4,    "Very few ",
            6,    "A few ",
            10,   "Some ",
            15,   "Quite some ",
            25,   "A score of ",
            40,   "A lot of ",
            60,   "Many ",
            100,  "A small pile of ",
            150,  "A pile of ",
            250,  "A large pile of ",
            400,  "A small heap of ",
            600,  "A heap of ",
            1000, "A large heap of ",
            1500, "A small treasure of ",
            2500, "A treasure of ",
            4000, "A large treasure of ",
            6000, "A huge treasure of "
        });
    else
        return "/obj/money"->get_amount_array();
}

string query_amount_string() {
    int i;

    if(!pointerp(xaAmountArray))
        xaAmountArray = get_amount_array();

    for(i = 0; i < sizeof(xaAmountArray)/2; i++) {
        if(iMoney <= xaAmountArray[i*2])
            return xaAmountArray[i*2+1];
    }
    return "Mountains of ";
}

string short() {
    if(!iMoney)
        return 0;
    else if(iMoney == 1)
        return "One gold coin";
    else
        return query_amount_string()+"gold coins";
}


string query_name() {
   return short();
}

void long() {
    printf("%s.\n", short());
}

int query_weight() {
  return 0;
}

int get() {
  return iMoney > 0;
}

void dest_mon() {
    if(iMoney < 1)
        destruct(this_object());
}

int query_money_object() {
    return 1;
}

void reset(int iArg) {
    if(!iArg) {
        iMoney = 1;
    }
}

/*
 * If we are picked up by a player, then move the money to his "purse",
 * and destruct this object.
 */

void init() {
    object oMon;

    if(environment() == this_player() || living(environment())) {
// Sauron: Moved the counting of money to the add_money() routine.
        environment()->add_money(iMoney);
        iMoney=0;
        call_out("dest_mon", 1); 
    }
    else {
        oMon = first_inventory(environment());
        while(oMon && (!oMon->query_money_object() ||
                       oMon == this_object()))
            oMon = next_inventory(oMon);
        if(oMon) {
            oMon->set_money(oMon->query_money()+iMoney);
            iMoney = 0;
            call_out("dest_mon", 1);
        }
        else
            add_action("count", "count");
    }
}
